#include <assert.h>
#include <stdexcept>
#include <set>
#include <iomanip>
#include <iostream>
#include <sstream>

#include <DeckLinkAPI.h>

#if defined(__APPLE__)
#include <string.h>

//=====================================================================================================================
#define STDMETHODCALLTYPE

//---------------------------------------------------------------------------------------------------------------------
const REFIID IID_IUnknown = CFUUIDGetUUIDBytes(IUnknownUUID);

//---------------------------------------------------------------------------------------------------------------------
inline bool IsEqualGUID( const CFUUIDBytes& a, const CFUUIDBytes& b )
{
  return memcmp( &a, &b, sizeof(CFUUIDBytes) ) == 0;
}

#elif defined(__linux__)
#include <string.h>

//=====================================================================================================================
#define STDMETHODCALLTYPE

//---------------------------------------------------------------------------------------------------------------------
inline bool IsEqualGUID( const REFIID& a, const REFIID& b )
{
  return memcmp( &a, &b, sizeof(REFIID) ) == 0;
}
#endif

//=====================================================================================================================
inline IDeckLinkDiscovery* CreateDiscoveryInst()
{
#ifdef _WIN32
    //-----------------------------------------------------------------------------------------------------------------
	LPVOID  p = NULL;
	HRESULT  hr = CoCreateInstance(
				CLSID_CDeckLinkDiscovery,  NULL,  CLSCTX_ALL,
				IID_IDeckLinkDiscovery,  &p
				);

	if ( FAILED(hr) )
	{
		throw std::runtime_error("creating IDeckLinkDiscovery failed");
	}

	assert( p != NULL );
	return  static_cast<IDeckLinkDiscovery*>(p);
#else
    //-----------------------------------------------------------------------------------------------------------------
	IDeckLinkDiscovery* p = CreateDeckLinkDiscoveryInstance();

	if( p == NULL )
	{
		throw std::runtime_error("creating IDeckLinkDiscovery failed");
	}

	return p;
#endif
}

//=====================================================================================================================
class CDiscoveryCallback : public IDeckLinkDeviceNotificationCallback
{
    std::set<IDeckLink*>  m_DevPointers;

public:
    // overrides IDeckLinkDeviceNotificationCallback
    virtual HRESULT STDMETHODCALLTYPE DeckLinkDeviceArrived( IDeckLink* pDev );

    virtual HRESULT STDMETHODCALLTYPE DeckLinkDeviceRemoved( IDeckLink* pDev );

    // overrides IUnknown
    virtual HRESULT STDMETHODCALLTYPE QueryInterface( REFIID iid, void** ppv );

    virtual ULONG STDMETHODCALLTYPE AddRef(void);
    virtual ULONG STDMETHODCALLTYPE Release(void);
}  g_DiscoveryCallback;

//---------------------------------------------------------------------------------------------------------------------
HRESULT STDMETHODCALLTYPE CDiscoveryCallback::DeckLinkDeviceArrived( IDeckLink* pDev )
{
    std::ostringstream sstr;
    sstr << "CDiscoveryCallback::DeckLinkDeviceArrived: IDeckLink pointer = 0x" << std::hex << (uintptr_t)pDev
                                                                                                        << std::endl;

    m_DevPointers.insert(pDev);
    pDev->AddRef();

    std::cerr << sstr.str();
    std::cerr.flush();

    return S_OK;
}

//---------------------------------------------------------------------------------------------------------------------
HRESULT STDMETHODCALLTYPE CDiscoveryCallback::DeckLinkDeviceRemoved( IDeckLink* pDev )
{
    std::ostringstream sstr;
    sstr << "CDiscoveryCallback::DeckLinkDeviceRemoved: IDeckLink pointer = 0x" << std::hex << (uintptr_t)pDev;

    if( m_DevPointers.erase(pDev) )
    {
        sstr << " (added earlier)\n";
        pDev->Release();
    }
    else
    {
        sstr << " (unknown pointer)\n";
    }

    std::cerr << sstr.str();
    std::cerr.flush();

    return S_OK;
}

//---------------------------------------------------------------------------------------------------------------------
HRESULT STDMETHODCALLTYPE CDiscoveryCallback::QueryInterface( REFIID riid, void** ppvObject )
{
    if( IsEqualGUID( riid, IID_IDeckLinkDeviceNotificationCallback ) )
    {
        *ppvObject = static_cast<IDeckLinkDeviceNotificationCallback*>(this);
        return S_OK;
    }

    if( IsEqualGUID( riid, IID_IUnknown ) )
    {
        *ppvObject = static_cast<IUnknown*>(this);
        return S_OK;
    }

    return E_NOINTERFACE;
}

//---------------------------------------------------------------------------------------------------------------------
ULONG STDMETHODCALLTYPE CDiscoveryCallback::AddRef(void)
{
    return 2;
}

//---------------------------------------------------------------------------------------------------------------------
ULONG STDMETHODCALLTYPE CDiscoveryCallback::Release(void)
{
    return 1;
}

//=====================================================================================================================
int main( int argc, char** argv )
{
#ifdef _WIN32
    CoInitialize(NULL);
#endif
    int status = 0;

    try
    {
        std::cerr << "Starting..." << std::endl;
        IDeckLinkDiscovery* pInst = CreateDiscoveryInst();
        HRESULT hr = pInst->InstallDeviceNotifications( &g_DiscoveryCallback );

        if( FAILED(hr) )
        {
            std::cerr << "Error: IDeckLinkDiscovery::InstallDeviceNotifications failed. HRESULT=0x" <<
                                        std::setw(8) << std::setfill('0') << std::left << std::hex << hr << std::endl;
            status = 1;
        }
        else
        {
            std::cerr << "Error: IDeckLinkDiscovery::InstallDeviceNotifications succeeded.\n\nPress ENTER to quit.\n";
            std::cerr.flush();
            std::cin.ignore();
            pInst->UninstallDeviceNotifications();
        }

        pInst->Release();
    }
    catch( const std::exception& ex )
    {
        std::cerr << "Error: " << ex.what() << std::endl;
        status = 1;
    }

    std::cerr << "Finished." << std::endl;
    return status;
}
