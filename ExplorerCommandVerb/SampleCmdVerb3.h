#pragma once

class __declspec(uuid("3C69AD8E-17DE-47F1-B84A-96B1E3044CA2"))
    SampleCmdVerb3 : public UnknownBase<IExplorerCommand>
{
public:
    SampleCmdVerb3() = default;

    //IExplorerCommand
    HRESULT STDMETHODCALLTYPE GetTitle(IShellItemArray* psiItemArray, LPWSTR* ppszName);
    HRESULT STDMETHODCALLTYPE GetIcon(IShellItemArray* psiItemArray, LPWSTR* ppszIcon);
    HRESULT STDMETHODCALLTYPE GetToolTip(IShellItemArray* psiItemArray, LPWSTR* ppszInfotip);
    HRESULT STDMETHODCALLTYPE GetCanonicalName(GUID* pguidCommandName);
    HRESULT STDMETHODCALLTYPE GetState(IShellItemArray* psiItemArray, BOOL fOkToBeSlow, EXPCMDSTATE* pCmdState);
    HRESULT STDMETHODCALLTYPE Invoke(IShellItemArray* psiItemArray, IBindCtx* pbc);
    HRESULT STDMETHODCALLTYPE GetFlags(EXPCMDFLAGS* pFlags);
    HRESULT STDMETHODCALLTYPE EnumSubCommands(IEnumExplorerCommand** ppEnum);

    ~SampleCmdVerb3() = default;
};
