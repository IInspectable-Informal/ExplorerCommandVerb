#include "pch.h"
#include "SampleCmdVerb3.h"

//IExplorerCommand
HRESULT STDMETHODCALLTYPE SampleCmdVerb3::GetTitle(IShellItemArray* psiItemArray, LPWSTR* ppszName)
{
	return SHStrDupW(L"Sample Command Verb 3 - Delayed", ppszName);
}

HRESULT STDMETHODCALLTYPE SampleCmdVerb3::GetIcon(IShellItemArray* psiItemArray, LPWSTR* ppszIcon)
{
	return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE SampleCmdVerb3::GetToolTip(IShellItemArray* psiItemArray, LPWSTR* ppszInfotip)
{
	return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE SampleCmdVerb3::GetCanonicalName(GUID* pguidCommandName)
{
	return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE SampleCmdVerb3::GetState(IShellItemArray* psiItemArray, BOOL fOkToBeSlow, EXPCMDSTATE* pCmdState)
{
	if (fOkToBeSlow)
	{
		Sleep(5 * 1000);
		*pCmdState = ECS_ENABLED;
		return S_OK;
	}
	else
	{
		*pCmdState = ECS_DISABLED;
		return E_PENDING;
	}
}

HRESULT STDMETHODCALLTYPE SampleCmdVerb3::Invoke(IShellItemArray* psiItemArray, IBindCtx* pbc)
{
	MessageBoxW(nullptr, L"This command is disabled until 5 seconds waiting completed.", L"Sample Command Verb 3 - Delayed", MB_OK);
	psiItemArray->Release();
	return S_OK;
}

HRESULT STDMETHODCALLTYPE SampleCmdVerb3::GetFlags(EXPCMDFLAGS* pFlags)
{
	*pFlags = ECF_DEFAULT;
	return S_OK;
}

HRESULT STDMETHODCALLTYPE SampleCmdVerb3::EnumSubCommands(IEnumExplorerCommand** ppEnum)
{
	return E_NOTIMPL;
}
