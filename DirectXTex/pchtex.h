//--------------------------------------------------------------------------------------
// File: DxStdAfx.h
//
// Desc: Header file that is the standard includes for the DirectX SDK samples
//
// Copyright (c) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#pragma once

#ifndef UNICODE
#error "DirectXTex requires a Unicode build."
#endif

// Exclude rarely-used stuff from Windows headers
#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN
#endif
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif
#ifndef STRICT
#define STRICT
#endif

#ifndef _INC_SDKDDKVER
#include <sdkddkver.h>
#endif

// If app hasn't choosen, set to work with Windows 8 and beyond
#if _WIN32_WINNT < _WIN32_WINNT_WIN8
#undef _WIN32_WINNT
#endif
#ifndef _WIN32_WINNT
#define _WIN32_WINNT   _WIN32_WINNT_WIN8
#endif
#ifndef WINVER
#define WINVER         _WIN32_WINNT
#endif
#ifndef _WIN32_WINDOWS
#define _WIN32_WINDOWS _WIN32_WINNT
#endif

#if (_WIN32_WINNT >= _WIN32_WINNT_WIN8) && !defined(DXGI_1_2_FORMATS)
#define DXGI_1_2_FORMATS
#endif

#include "DirectXTexexp.h"

#if defined(_MSC_VER) && defined(DXTEXLIB_EXPORTS) || defined(_LIB) || defined(DXTEXLIB_IMPORTS) || defined(_DLL) && !defined(DXUT_AUTOLIB)
#define DXTEX_AUTOLIB 0
#endif

// #define DXTEX_AUTOLIB to automatically include the libs needed for DXTEX
#if !defined(DXUT_AUTOLIB) && !defined(EFFECTS11_AUTOLIB) && !defined(DXTK_AUTOLIB)
#ifdef DXTEX_AUTOLIB
#pragma comment( lib, "d3d11.lib" )
// #pragma comment( lib, "d3d10_1.lib" )
// #pragma comment( lib, "d3d10.lib" )
#pragma comment( lib, "ComCtl32.Lib" )
#pragma comment( lib, "dxgi.lib" )
#pragma comment( lib, "dxguid.lib" )
//#pragma comment( lib, "d3dcompiler.lib" )
// #pragma comment( lib, "ole32.lib" ) // included with additional include directories 
// #pragma comment( lib, "uuid.lib" ) // included with additional include directories 
#pragma comment( lib, "usp10.lib" )
// #pragma comment( lib, "ddraw.lib" )
#if (_WIN32_WINNT >= _WIN32_WINNT_WIN8) || defined(_WIN7_PLATFORM_UPDATE) && !defined(_XBOX_ONE)
#pragma comment( lib, "d2d1.lib" )
#endif
// #pragma comment( lib, "dwrite.lib" )
// #ifdef _DEBUG
// #pragma comment( lib, "d3dcsxd.lib" )
// #else
// #pragma comment( lib, "d3dcsx.lib" )
// #endif
#pragma comment( lib, "WinMM.Lib" )
#pragma comment( lib, "Imm32.Lib" )
#pragma comment( lib, "Version.Lib" )
#if !defined(WINAPI_FAMILY) || (WINAPI_FAMILY != WINAPI_FAMILY_PHONE_APP)
#pragma comment( lib, "windowscodecs.lib" )
#endif
#endif
#endif

#ifdef DXTEXLIB_IMPORTS
#ifdef DXTEXLIB_DLL
#ifdef _DEBUG
#pragma comment( lib, "DirectXTex_d.lib" )
#else
#pragma comment( lib, "DirectXTex.lib" )
#endif
#elif DXTEXLIB_STATIC
#ifdef _DEBUG
#pragma comment( lib, "DirectXTexs_d.lib" )
#else
#pragma comment( lib, "DirectXTexs.lib" )
#endif
#else
#pragma warning ("DXTEXLIB_IMPORTS import librarys aren't defined")
#endif
#endif

#pragma warning(disable : 4067 4102 4127 4201 4251 4324 4481 4505 4616 4706 6326 6993 )

#pragma warning(push)
#pragma warning(disable : 4005)

#pragma pack(push)
#pragma pack(8)

// Standard Windows includes
#include <windows.h>
#include <ocidl.h>
#include <initguid.h>
#include <commctrl.h> // for InitCommonControls()
#include <shellapi.h> // for ExtractIcon()
#include <shlobj.h>
#include <usp10.h>
#include <dimm.h>
#include <sal.h>
#include <strsafe.h>
#include <msctf.h>
#include <mmsystem.h>
#include <ks.h>
#include <ole2.h>
#include <wrl.h>
#include <objbase.h>
#include <mmreg.h>

// Direct3D11 includes
#if defined(_XBOX_ONE) && defined(_TITLE) && MONOLITHIC
#include <d3d11_x.h>
#define DCOMMON_H_INCLUDED
#define NO_D3D11_DEBUG_NAME
#else

//#include <d3dcommon.h>
#if (_WIN32_WINNT >= _WIN32_WINNT_WINBLUE) && !defined(_XBOX_ONE)
#include <dxgi1_3.h>
#include <d3d11_2.h>
#include <d2d1_2.h>
#elif (_WIN32_WINNT >= _WIN32_WINNT_WIN8) || defined(_WIN7_PLATFORM_UPDATE) && !defined(_XBOX_ONE)
#include <dxgi1_2.h>
#include <d3d11_1.h>
#include <d2d1_1.h>
#else
#include <dxgi1_1.h>
#include <d3d11.h>
#include <d2d1.h>
#endif
// #include <d3d11shader.h>
// #include <d3dcompiler.h>
// #include <d3dcsx.h>
#endif

#if defined(DEBUG) || defined(_DEBUG)
#include <dxgidebug.h>
#endif

// DirectXMath includes
#include <DirectXMath.h>
#include <DirectXColors.h>
#include <DirectXPackedVector.h>
#include <DirectXCollision.h>

// WIC includes
#if !defined(WINAPI_FAMILY) || (WINAPI_FAMILY != WINAPI_FAMILY_PHONE_APP)
#include <wincodec.h>
#endif

// XInput includes
//#include <xinput.h>

/*
#include <ddraw.h>
#include <dwrite.h>
#include <dxtmpl.h>
*/

#pragma pack (pop)

// STL includes
#include <assert.h>
#include <wchar.h>
#include <new.h>      // for placement new
#include <math.h>
#include <malloc.h>
#include <limits.h>
#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <intsafe.h>
#include <string>
#include <algorithm>
#include <array>
#include <memory.h>
#include <memory>
#include <map>
#include <float.h>
#include <cmath>
#include <vector>
#include <functional>
#include <set>
#include <search.h>
#include <exception>
#include <type_traits>
#ifdef _OPENMP
#include <omp.h>
#endif

// CRT's memory leak detection
#if defined(DEBUG) || defined(_DEBUG)
#include <crtdbg.h>
#endif

#pragma warning(pop)

// Enable extra D3D debugging in debug builds if using the debug DirectX runtime.
// This makes D3D objects work well in the debugger watch window, but slows down
// performance slightly.
#if defined(DEBUG) || defined(_DEBUG)
#define D3D_DEBUG_INFO
#endif

#ifdef min
#undef min // use __min instead
#endif
#ifdef max
#undef max // use __max instead
#endif

/*
#ifndef max
#define max __max
#endif

#ifndef min
#define min __min
#endif*/

#if !(UNUSED == -1) && !defined(UNUSED)
#define UNUSED -1
#endif

/*
namespace_DirectX
#if (DIRECTXMATH_VERSION < 305) && !defined(XM_CALLCONV)
#define XM_CALLCONV __fastcall
			typedef const XMVECTOR& HXMVECTOR;
			typedef const XMMATRIX& FXMMATRIX;
#endif
namespace_DirectX_end*/

#ifndef SAFE_DELETE
#define SAFE_DELETE(p)       { if (p) { delete (p);     (p) = nullptr; } }
#endif
#ifndef SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(p) { if (p) { delete[] (p);   (p) = nullptr; } }
#endif
#ifndef SAFE_RELEASE
#define SAFE_RELEASE(p)      { if (p) { (p)->Release(); (p) = nullptr; } }
#endif

#ifndef SAFE_ADDREF
#define SAFE_ADDREF(p)        { if (p) { (p)->AddRef(); } }
#endif

#if FXDEBUG
#ifndef __BREAK_ON_FAIL
#define __BREAK_ON_FAIL       { __debugbreak(); }
#endif
#else
#ifndef __BREAK_ON_FAIL
#define __BREAK_ON_FAIL 
#endif
#endif

#ifndef VA
#define VA(x, action) { hr = (x); if (FAILED(hr)) { action; __BREAK_ON_FAIL;                     return hr;  } }
#endif
#ifndef VNA
#define VNA(x,action) {           if (!(x))       { action; __BREAK_ON_FAIL; hr = E_OUTOFMEMORY; goto lExit; } }
#endif
#ifndef VBA
#define VBA(x,action) {           if (!(x))       { action; __BREAK_ON_FAIL; hr = E_FAIL;        goto lExit; } }
#endif
#ifndef VHA
#define VHA(x,action) { hr = (x); if (FAILED(hr)) { action; __BREAK_ON_FAIL;                     goto lExit; } }
#endif

#ifndef V
#define V(x)          { VA (x, 0) }
#endif
#ifndef VN
#define VN(x)         { VNA(x, 0) }
#endif
#ifndef VB
#define VB(x)         { VBA(x, 0) }
#endif
#ifndef VH
#define VH(x)         { VHA(x, 0) }
#endif

#ifndef VBD
#define VBD(x,str)         { VBA(x, DPF(1,str)) }
#endif
#ifndef VHD
#define VHD(x,str)         { VHA(x, DPF(1,str)) }
#endif
#ifndef VEASSERT
#define VEASSERT(x)   { hr = (x); if (FAILED(hr)) { __BREAK_ON_FAIL; assert(!#x);                     goto lExit; } }
#endif
#ifndef VNASSERT
#define VNASSERT(x)   {           if (!(x))       { __BREAK_ON_FAIL; assert(!#x); hr = E_OUTOFMEMORY; goto lExit; } }
#endif
#ifndef D3DX11FLTASSIGN
#define D3DX11FLTASSIGN(a,b)    { *reinterpret_cast< UINT32* >(&(a)) = *reinterpret_cast< UINT32* >(&(b)); }
#endif


		//--------------------------------------------------------------------------------------
		// SAL2 fixups for VS 2010
		//--------------------------------------------------------------------------------------

		/*
		#if defined(_MSC_VER) && (_MSC_VER<1610) && !defined(_In_reads_)
		#define _Analysis_assume_(exp)
		#define _In_reads_(exp)
		#define _In_reads_opt_(exp)
		#define _Out_writes_(exp)
		#define _Out_writes_opt_(exp)
		#define _In_reads_bytes_(exp)
		#define _Out_writes_bytes_(exp)
		#define _Out_writes_bytes_to_opt_(a,b)
		#define _Inout_updates_bytes_(exp)
		#define _Inout_updates_all_(exp)
		#define _Inout_updates_all_opt_(exp)
		#define _COM_Outptr_
		#define _Outptr_
		#define _Outptr_opt_
		#define _Outptr_result_z_
		#define _Outptr_opt_result_maybenull_
		#define _When_(a,b)
		#define _Acquires_lock_(exp)
		#define _Releases_lock_(exp)
		#define _Inexpressible_(exp)
		#endif*/

#if defined(_MSC_VER) && (_MSC_VER<1610) && !defined(_In_reads_)
#define _Analysis_assume_(exp) __analysis_assume(exp)
#define _In_reads_(exp) _In_count_x_(exp)
#define _In_reads_opt_(exp) _In_opt_count_x_(exp)
#define _In_reads_bytes_(exp) _In_bytecount_x_(exp)
#define _Inout_updates_(exp) _Inout_cap_x_(exp)
#define _Inout_updates_z_(exp) _Inout_z_cap_x_(exp)
#define _Inout_updates_bytes_(exp) _Inout_bytecap_x_(exp)
#define _Inout_updates_all_(exp) _Inout_z_cap_x_(exp)
#define _Inout_updates_all_opt_(exp) _Inout_opt_z_cap_x_(exp)
#define _Out_writes_(exp) _Out_cap_x_(exp)
#define _Out_writes_opt_(exp) _Out_opt_cap_x_(exp)
#define _Out_writes_bytes_(exp) _Out_bytecap_x_(exp)
#define _Out_writes_bytes_to_opt_(a,b) _Out_opt_bytecap_x_(a,b)
#define _Outptr_ _Deref_out_
#define _Outptr_opt_ _Deref_out_opt_
#define _Outptr_result_z_ _Deref_out_z_
#define _Outptr_opt_result_maybenull_ _Deref_opt_out_opt_
#define _Outptr_result_maybenull_z_ _Deref_opt_out_opt_z_
#define _Outptr_result_buffer_(exp) _Deref_post_cap_x_(exp)
#define _Outptr_result_buffer_all_maybenull_(exp) _Deref_post_opt_cap_x_(exp)
#define _COM_Outptr_ _Deref_out_
#define _When_(test,exp)
#define _Acquires_lock_(exp)
#define _Releases_lock_(exp)
#define _Inexpressible_(exp)
#endif

#ifndef _Use_decl_annotations_
#define _Use_decl_annotations_
#endif

#ifndef offsetof_fx
#define offsetof_fx( a, b ) (uint32_t)offsetof( a, b )
#endif

#include "DirectXTexvers.h"
#include "typesexport.h"
#include "PlatformHelpers.h"


// DirectXTex
#include "DDS.h"
#include "DDSTextureLoader.h"
#if !defined(WINAPI_FAMILY) || (WINAPI_FAMILY != WINAPI_FAMILY_PHONE_APP)
#include "WICTextureLoader.h"
#endif
#include "ScreenGrab.h"


#ifdef _PCH_BUILD
#include "DirectXTex.h"
#include "DirectXTexp.h"
// #include "scoped.h"
#include "BC.h"
#include "BCDirectCompute.h"
#include "filters.h"
#endif





