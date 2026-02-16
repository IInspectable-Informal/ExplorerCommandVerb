#include "pch.h"
#include "SampleCmdVerb2.h"

//IExplorerCommand
HRESULT STDMETHODCALLTYPE SampleCmdVerb2::GetTitle(IShellItemArray* psiItemArray, LPWSTR* ppszName)
{
	return SHStrDupW(L"Sample Command Verb 2", ppszName);
}

HRESULT STDMETHODCALLTYPE SampleCmdVerb2::GetIcon(IShellItemArray* psiItemArray, LPWSTR* ppszIcon)
{
	wchar_t iconPath[MAX_PATH + 12];
	StringCchPrintfW(iconPath, ARRAYSIZE(iconPath), L"%ls,%d", GetDllPath(), 0);
	SHStrDupW(iconPath, ppszIcon);
	return S_OK;
}

HRESULT STDMETHODCALLTYPE SampleCmdVerb2::GetToolTip(IShellItemArray* psiItemArray, LPWSTR* ppszInfotip)
{
	return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE SampleCmdVerb2::GetCanonicalName(GUID* pguidCommandName)
{
	return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE SampleCmdVerb2::GetState(IShellItemArray* psiItemArray, BOOL fOkToBeSlow, EXPCMDSTATE* pCmdState)
{
	*pCmdState = ECS_ENABLED;
	return S_OK;
}

HRESULT STDMETHODCALLTYPE SampleCmdVerb2::Invoke(IShellItemArray* psiItemArray, IBindCtx* pbc)
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
				StringCchPrintfW(messageStr, ARRAYSIZE(messageStr), L"%d item(s), first item's path is:\n%ls", count, firstItemPath);
				MessageBoxW(nullptr, messageStr, L"Sample Command Verb 2", MB_OK);
			}
			CoTaskMemFree(firstItemPath);
			firstItem->Release();
		}
	}
	psiItemArray->Release();
	return S_OK;
}

HRESULT STDMETHODCALLTYPE SampleCmdVerb2::GetFlags(EXPCMDFLAGS* pFlags)
{
	*pFlags = ECF_DEFAULT;
	return S_OK;
}

HRESULT STDMETHODCALLTYPE SampleCmdVerb2::EnumSubCommands(IEnumExplorerCommand** ppEnum)
{
	return E_NOTIMPL;
}
