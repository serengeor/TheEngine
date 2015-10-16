#pragma once

#include "IMeshLoader.h"
#include "core/AppContext.h"

class Mesh;
struct iqmheader;
class Logger;

class iqmloader : public imesh_loader
{
private:
	void load_header(const char* data, iqmheader & header);
	void loadiqmanims(std::shared_ptr<Mesh> m, const char* data, iqmheader & header);
	Logger * m_logger;
	AppContext * m_appContext;
public:
	iqmloader(AppContext * appContext);

	virtual std::shared_ptr<Mesh> load(const char* data, const uint32_t size);
	virtual bool check_by_extension(const std::string & ext);

private:
};
