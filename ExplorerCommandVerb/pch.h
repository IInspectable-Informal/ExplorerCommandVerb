#pragma once
//Win32
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include <unknwn.h>
#include <shobjidl_core.h>
#include <shlwapi.h>
#pragma comment(lib, "shlwapi.lib")
#include <strsafe.h>

//Standard Libraries
#include <stdint.h>
#include <type_traits>

//This project
#include "UnknownBase.hpp"
