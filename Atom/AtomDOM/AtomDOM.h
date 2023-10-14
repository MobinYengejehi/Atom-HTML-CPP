/*****************************************************************************
 *
 *  PROJECT:     Atom HTML Graphics Library for `C & CPP`
 *               (https://github.com/MobinYengejehi/Atom-HTML-CPP)
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        AtomDOM/AtomDOM.h
 *
 *  AUTHOR:      MobinYengejehi
 *  GITHUB:      https://github.com/MobinYengejehi
 *
 *****************************************************************************/

#pragma once

#ifndef ATOM_DOM_HEADER
#define ATOM_DOM_HEADER

#include "../AtomSystemDefinitions.h"

ATOM_C_ENV_OPEN

ATOM_LIB_SHARE void atom_dom_init();
ATOM_LIB_SHARE void atom_dom_uninit();

ATOM_LIB_SHARE void atom_dom_create_element(const char* type, const char* ns = NULL);

ATOM_C_ENV_CLOSE

#endif