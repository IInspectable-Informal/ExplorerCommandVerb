#pragma once

/// <summary>
/// Increse the reference count of this DLL
/// </summary>
void DllAddRef();

/// <summary>
/// Decrese the reference count of this DLL
/// </summary>
void DllRelease();

/// <summary>
/// Get this DLL's absolute path
/// </summary>
/// <returns>
/// This DLL's absolute path
/// </returns>
LPCWSTR GetDllPath();
