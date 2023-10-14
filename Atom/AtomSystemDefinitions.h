/*****************************************************************************
 *
 *  PROJECT:     Atom HTML Graphics Library for `C & CPP`
 *               (https://github.com/MobinYengejehi/Atom-HTML-CPP)
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        AtomSystemDefinitions.h
 *
 *  AUTHOR:      MobinYengejehi
 *  GITHUB:      https://github.com/MobinYengejehi
 *
 *****************************************************************************/

#pragma once

#ifndef ATOM_SYSTEM_DEFINITIONS_HEADER
#define ATOM_SYSTEM_DEFINITIONS_HEADER

#ifdef __cplusplus
#define ATOM_C_API extern "C"
#define ATOM_C_ENV_OPEN extern "C" {
#define ATOM_C_ENV_CLOSE }
#else
#define ATOM_C_API
#define ATOM_C_ENV_OPEN
#define ATOM_C_ENV_CLOSE
#endif

#ifndef NULL
#define NULL 0
#endif

#ifdef EMSCRIPTEN
#define ATOM_SYSTEM_OS_WASM 1
#else
#define ATOM_SYSTEM_OS_WASM 0
#endif

#if ATOM_SOURCE_DEVELOPEMENT_MODE
#define ATOM_API_EXPORT
#define ATOM_API_IMPORT
#else
#if defined(ATOM_SYSTEM_OS_WINDOWS)
#define ATOM_API_EXPORT __declspec(dllexport)
#define ATOM_API_IMPORT __declspec(dllimport)
#elif defined(ATOM_SYSTEM_OS_UNIX_AND_LINUX)
#define ATOM_API_EXPORT __attribute__((visibility("default")))
#define ATOM_API_IMPORT
#else
#define ATOM_API_EXPORT
#define ATOM_API_IMPORT
#pragma warning [ATOM]: Unknown dynamic link import/export semantics.
#endif
#endif

#if ATOM_COMPILING_LIBRARY
#define ATOM_LIB_SHARE ATOM_API_EXPORT
#else
#define ATOM_LIB_SHARE ATOM_API_IMPORT
#endif

#if ATOM_SYSTEM_OS_WASM
 // if you define `ATOM_WASM_USE_MULTI_THREAD_DEFINITION` then you can use element functions on other threads too in wasm
 //#define ATOM_WASM_USE_MULTI_THREAD_DEFINITION
#endif

#define ATOM_GLSL(...) "" #__VA_ARGS__ ""

#define ATOM_FREE_SAFE(ptr) free((void*)ptr)

#endif