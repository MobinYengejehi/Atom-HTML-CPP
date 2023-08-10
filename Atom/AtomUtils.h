/*****************************************************************************
 *
 *  PROJECT:     Atom HTML Graphics Library for `C & CPP`
 *               (https://github.com/MobinYengejehi/Atom-HTML-CPP)
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        AtomUtils.h
 *
 *  AUTHOR:      MobinYengejehi
 *  GITHUB:      https://github.com/MobinYengejehi
 *
 *****************************************************************************/

#pragma once

#ifndef ATOM_UTILS_HEADER
#define ATOM_UTILS_HEADER

#include <string>
#include <vector>

std::string ConcatStringList(const std::vector<std::string>& list, const std::string& with);

std::string TrimString(const std::string& content);

#endif