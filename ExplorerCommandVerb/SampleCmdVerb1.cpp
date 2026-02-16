#include "pch.h"
#include "dllmain.h"
#include "SampleCmdVerb1.h"

//IExplorerCommand
HRESULT STDMETHODCALLTYPE SampleCmdVerb1::GetTitle(IShellItemArray* psiItemArray, LPWSTR* ppszName)
{
	return SHStrDupW(L"Sample Command Verb 1", ppszName);
}

HRESULT STDMETHODCALLTYPE SampleCmdVerb1::GetIcon(IShellItemArray* psiItemArray, LPWSTR* ppszIcon)
{
	return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE SampleCmdVerb1::GetToolTip(IShellItemArray* psiItemArray, LPWSTR* ppszInfotip)
{
	return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE SampleCmdVerb1::GetCanonicalName(GUID* pguidCommandName)
{
	return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE SampleCmdVerb1::GetState(IShellItemArray* psiItemArray, BOOL fOkToBeSlow, EXPCMDSTATE* pCmdState)
{
	*pCmdState = ECS_ENABLED;
	return S_OK;
}

HRESULT STDMETHODCALLTYPE SampleCmdVerb1::Invoke(IShellItemArray* psiItemArray, IBindCtx* pbc)
{
	DWORD count = 0;
	HRESULT hr = psiItemArray->GetCount(&count);
	if (SUCCEEDED(hr))
	{
		IShellItem* firstItem = nullptr;
		hr = psiItemArray->GetItemAt(1, &firstItem);
		if (SUCCEEDED(hr))
		{
			LPWSTR firstItemPath = nullptr;
			hr = firstItem->GetDisplayName(SIGDN_DESKTOPABSOLUTEPARSING, &firstItemPath);
			if (SUCCEEDED(hr))
			{
				wchar_t messageStr[10 + 32 + MAX_PATH];
				StringCchPrintfW(messageStr, sizeof(messageStr) / sizeof(wchar_t), L"%d item(s), first item's path is:\n%ls", count, firstItemPath);
				MessageBoxW(nullptr, messageStr, L"Sample Command Verb 1", MB_OK);
			}
			CoTaskMemFree(firstItemPath);
			firstItem->Release();
		}
	}
	psiItemArray->Release();
	return S_OK;
}

HRESULT STDMETHODCALLTYPE SampleCmdVerb1::GetFlags(EXPCMDFLAGS* pFlags)
{
	*pFlags = ECF_DEFAULT;
	return S_OK;
}

HRESULT STDMETHODCALLTYPE SampleCmdVerb1::EnumSubCommands(IEnumExplorerCommand** ppEnum)
{
	return E_NOTIMPL;
}
