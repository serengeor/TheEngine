#pragma once
#include "utility/Vector.h"
#include "ForwardDecl.h"

template <class T>
struct resource
{
	Path _path;
	std::shared_ptr<T> _resource;
};

template <class T>
class resource_cache
{
public:

	void add_resource(resource<T> res)
	{
		m_resources.push_back(res);
	}

	resource<T> get_resource(const Path & path)
	{
		auto it = std::find_if(m_resources.begin(), m_resources.end(), [&path](resource<T> res)
		{
			return res._path == path;
		});

		if (it != m_resources.end())
		{
			return (*it);
		}

		return resource<T>();
	}

protected:
	vector< resource<T> >  m_resources;
};

template <class T>
vector<std::shared_ptr<T> > * create_resource_cache()
{
	return new vector<std::shared_ptr<T> >();
}
