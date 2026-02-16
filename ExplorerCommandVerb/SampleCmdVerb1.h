#pragma once

class __declspec(uuid("015921BF-6C26-4FDA-A7B4-B722BD29B5AF"))
    SampleCmdVerb1 : public UnknownBase<IExplorerCommand>
{
public:
	SampleCmdVerb1() = default;

	//IExplorerCommand
    HRESULT STDMETHODCALLTYPE GetTitle(IShellItemArray* psiItemArray, LPWSTR* ppszName);
    HRESULT STDMETHODCALLTYPE GetIcon(IShellItemArray* psiItemArray, LPWSTR* ppszIcon);
    HRESULT STDMETHODCALLTYPE GetToolTip(IShellItemArray* psiItemArray, LPWSTR* ppszInfotip);
    HRESULT STDMETHODCALLTYPE GetCanonicalName(GUID* pguidCommandName);
    HRESULT STDMETHODCALLTYPE GetState(IShellItemArray* psiItemArray, BOOL fOkToBeSlow, EXPCMDSTATE* pCmdState);
    HRESULT STDMETHODCALLTYPE Invoke(IShellItemArray* psiItemArray, IBindCtx* pbc);
    HRESULT STDMETHODCALLTYPE GetFlags(EXPCMDFLAGS* pFlags);
    HRESULT STDMETHODCALLTYPE EnumSubCommands(IEnumExplorerCommand** ppEnum);

    ~SampleCmdVerb1() = default;
};
