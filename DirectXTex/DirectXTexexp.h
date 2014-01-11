//--------------------------------------------------------------------------------------
// File: DirectXTexexp.h
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved.
//
// http://go.microsoft.com/fwlink/?LinkId=248926
//--------------------------------------------------------------------------------------
#pragma once

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

#ifndef _WINDOWS_
#include <windows.h>
#endif

#define namespace_DirectX namespace DirectX {
#define namespace_DirectX_end }

#define namespace_DirectXTex namespace DirectXTex {
#define namespace_DirectXTex_end }

#define namespace_TriangleFilter namespace TriangleFilter {
#define namespace_TriangleFilter_end }

#define namespace_std namespace std {
#define namespace_std_end }

#define namespace_DDSTextureLoader namespace DDSTextureLoader {
#define namespace_DDSTextureLoader_end }

#define namespace_WICTextureLoader namespace WICTextureLoader {
#define namespace_WICTextureLoader_end }

#define namespace_ScreenGrab namespace ScreenGrab {
#define namespace_ScreenGrab_end }


//#define extern_cplus

// Defined for Templates functions export
#define extern_cplusplus

#ifndef EXTERN_C_BEGIN
#ifdef __cplusplus
#ifdef extern_cplus
#define EXTERN_C_BEGIN extern "C" {
#define EXTERN_C_END }
#endif
#ifdef extern_cplusplus
#define EXTERN_C_BEGIN extern "C++" {
#define EXTERN_C_END }
#endif
#else
#define EXTERN_C_BEGIN
#define EXTERN_C_END
#endif
#endif

#ifdef __cplusplus
EXTERN_C_BEGIN
#endif

#ifdef __cplusplus
EXTERN_C_END
#endif

#ifdef __cplusplus
#if defined(extern_cplus)
#define _EXTERN extern "C"
#elif defined(extern_cplusplus)
#define _EXTERN extern "C++"
#endif
#else
#define _EXTERN extern
#endif

#ifdef __cplusplus
#if defined(extern_cplus)
#define DXTEXEXTERN extern "C"
#elif defined(extern_cplusplus)
#define DXTEXEXTERN extern "C++"
#endif
#else
#define DXTEXEXTERN extern
#endif

#if defined(_WINDOWS) || defined(_WIN32)
/* If building or using DXTEXlib as a DLL, define DXTEXLIB_DLL.
* This is not mandatory, but it offers a little performance increase.
*/

#if defined(LIB_EXPORTS) || defined(DXTEXLIB_EXPORTS)
#ifndef DXTEXLIB_IMPORTS
#ifndef DXTEXLIB_EXPORTS
#define DXTEXLIB_EXPORTS 1
#endif
#endif
#endif

#if defined(LIB_IMPORTS) || defined(DXTEXLIB_IMPORTS)
#if defined(DXTEXLIB_EXPORTS)
#error ("!!!You are bulding DXTEX export and import simultaniously")
#else
#ifndef DXTEXLIB_IMPORTS
#define DXTEXLIB_IMPORTS 1
#endif
#endif
#endif

#if defined(LIB_STATIC) || defined(DXTEXLIB_STATIC)
#ifndef DXTEXLIB_DLL
#ifndef DXTEXLIB_STATIC 
#define DXTEXLIB_STATIC 1
#endif
#endif
#endif

#if (defined(_DLL) || defined(_USRDLL) || defined(_WINDLL) || defined(LIB_DYNAMIC) || defined(DXTEXLIB_DLL)) && !defined(_LIB) && !defined(DXTEXLIB_STATIC)
#ifndef DXTEXLIB_STATIC
#ifndef DXTEXLIB_DLL
#define DXTEXLIB_DLL 1
#endif
#endif
#endif

#if !defined(DXTEXLIB_DLL) && !defined(DXTEXLIB_STATIC)
#error ("!!!Your DXTEX lib type static or dll aren't defined")
#endif


#  ifdef DXTEXLIB_DLL
#    if defined(WIN32) && (!defined(__BORLANDC__) || (__BORLANDC__ >= 0x500))
#      if defined(DXTEXLIB_EXPORTS) && !defined(DXTEXLIB_STATIC)
#        define DXTEXAPI __declspec(dllexport)
#      elif defined(DXTEXLIB_IMPORTS) && (defined(_DLL) || defined(_WINDLL) || defined(_USRDLL)) && !defined(DXTEXLIB_STATIC)
#        define DXTEXAPI __declspec(dllimport)
#      else // DXTEXLIB_STATIC  _LIB
#        define DXTEXAPI
#      endif
#    endif
#  else  // DXTEXLIB_LIB
#      define DXTEXAPI
#  endif  /* ! DXTEXLIB_DLL */

#else
#	define DXTEXAPI
#endif // _WINDOWS



//#define DXSTDAPI                  EXTERN_C EFFECTSAPI HRESULT STDAPICALLTYPE
//#define DXSTDAPI_(type)           EXTERN_C EFFECTSAPI type STDAPICALLTYPE


