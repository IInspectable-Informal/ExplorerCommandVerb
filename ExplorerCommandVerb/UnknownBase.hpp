#pragma once
#include "dllmain.h"

template<typename... I>
class UnknownBase abstract : public I...
{
    static_assert((std::is_base_of_v<IUnknown, I> && ...), "All the interface(s) must be derived from IUnknown!");
public:
    UnknownBase()
    {
        DllAddRef();
    }

    //IUnknown
    HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppvObject)
    {
        if (ppvObject == nullptr)
        {
            return E_POINTER;
        }
        else
        {
            *ppvObject = nullptr;
            if (riid == __uuidof(IUnknown))
            {
                *ppvObject = reinterpret_cast<IUnknown*>(this);
            }
            else
            {
                for (ULONG i = 0; i < s_IIdCount; ++i)
                {
                    if (riid == s_IIds[i])
                    {
                        *ppvObject = this;
                        break;
                    }
                }
            }
            if (*ppvObject)
            {
                AddRef();
                return S_OK;
            }
            else
            { 
                return E_NOINTERFACE;
            }
        }
    }

    ULONG STDMETHODCALLTYPE AddRef()
    {
        return InterlockedIncrement(&m_RefCount);
    }

    ULONG STDMETHODCALLTYPE Release()
    {
        ULONG cRef = InterlockedDecrement(&m_RefCount);
        if (cRef == 0)
        {
            delete this;
        }
        return cRef;
    }

    ~UnknownBase()
    {
        DllRelease();
    }

protected:
    ULONG m_RefCount = 1;

    static constexpr ULONG s_IIdCount = sizeof...(I); // Get implement interfaces count at compile time
    static constexpr IID s_IIds[s_IIdCount] = { __uuidof(I)... }; // Get implement interfaces at compile time
};
