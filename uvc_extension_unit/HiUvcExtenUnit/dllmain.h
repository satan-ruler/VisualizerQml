// dllmain.h: 模块类的声明。

class CHiUvcExtenUnitModule : public ATL::CAtlDllModuleT< CHiUvcExtenUnitModule >
{
public :
	DECLARE_LIBID(LIBID_HiUvcExtenUnitLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_HIUVCEXTENUNIT, "{1ee36a32-0b20-43d8-88ef-51c92bfc6752}")
};

extern class CHiUvcExtenUnitModule _AtlModule;
