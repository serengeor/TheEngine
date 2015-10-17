#include "Precomp.h"
#include "MeshLoader.h"
#include "IQMloader.h"
#include "opengl/Mesh.h"
#include "application/AppContext.h"
#include "boost/filesystem/path.hpp"

mesh_loader::mesh_loader(AppContext * appContext)
{
	m_appContext = appContext;
	add_loader(new iqmloader(m_appContext));
}

mesh_loader::~mesh_loader()
{
	for (imesh_loader * l : m_loaders)
		delete l;
}

void mesh_loader::add_loader(imesh_loader * loader)
{
	auto it = std::find_if(m_loaders.begin(), m_loaders.end(), [&loader](imesh_loader * l)
	{
		return l == loader;
	});

	if (it == m_loaders.end())buffer
		m_loaders.push_back(loader);
}

MeshPtr mesh_loader::load(const Path & fileName)
{
	bool found_usable_loader = false;
	resource<Mesh> res;
	res = this->get_resource(fileName);

	if (res._resource)
	{
		m_appContext->logger->log(LOG_LOG, "Found mesh in cache, skipping loading.");
		return res._resource;
	}

	std::string ext = fileName.extension().generic_string();
	m_appContext->logger->log(LOG_LOG, "Mesh extension: '%s'", ext.c_str());

	///REFACTOR: Search loader by extension func, return loader. Then try loading.
	if (m_appContext->fileSystem->FileExists(fileName.c_str()))
		for (imesh_loader * l : m_loaders)
		{
			if (l->check_by_extension(ext))
			{
				found_usable_loader = true;

				FilePtr file = m_appContext->fileSystem->OpenRead(fileName);

				if (file->IsOpen())
				{
					ByteBufferPtr buffer = file->Read();
					m_appContext->logger->log(LOG_LOG, "Mesh file size: %u", buffer->size());

					res._path = fileName;
					res._resource = MeshPtr(l->load((const char*)buffer->data(), buffer->size()));
					this->add_resource(res);
					res._resource->Init();
					return res._resource;
				}
				else
				{
					m_appContext->logger->log(LOG_ERROR, "File %s appears to be empty.", fileName.generic_string().c_str());
				}
			}
		}

	if (!found_usable_loader)
		m_appContext->logger->log(LOG_ERROR, "No loader can load '%s' mesh files.", ext.c_str());

	return nullptr;
}