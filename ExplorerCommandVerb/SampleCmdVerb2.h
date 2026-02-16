#pragma once

class __declspec(uuid("C8D3DFFF-6A09-4513-90C9-6C736EABC287"))
    SampleCmdVerb2 : public UnknownBase<IExplorerCommand>
{
public:
    SampleCmdVerb2() = default;

    //IExplorerCommand
    HRESULT STDMETHODCALLTYPE GetTitle(IShellItemArray* psiItemArray, LPWSTR* ppszName);
    HRESULT STDMETHODCALLTYPE GetIcon(IShellItemArray* psiItemArray, LPWSTR* ppszIcon);
    HRESULT STDMETHODCALLTYPE GetToolTip(IShellItemArray* psiItemArray, LPWSTR* ppszInfotip);
    HRESULT STDMETHODCALLTYPE GetCanonicalName(GUID* pguidCommandName);
    HRESULT STDMETHODCALLTYPE GetState(IShellItemArray* psiItemArray, BOOL fOkToBeSlow, EXPCMDSTATE* pCmdState);
    HRESULT STDMETHODCALLTYPE Invoke(IShellItemArray* psiItemArray, IBindCtx* pbc);
    HRESULT STDMETHODCALLTYPE GetFlags(EXPCMDFLAGS* pFlags);
    HRESULT STDMETHODCALLTYPE EnumSubCommands(IEnumExplorerCommand** ppEnum);

    ~SampleCmdVerb2() = default;
};
