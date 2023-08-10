/*****************************************************************************
 *
 *  PROJECT:     Atom HTML Graphics Library for `C & CPP`
 *               (https://github.com/MobinYengejehi/Atom-HTML-CPP)
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        AtomStyleMacros.h
 *
 *  AUTHOR:      MobinYengejehi
 *  GITHUB:      https://github.com/MobinYengejehi
 *
 *****************************************************************************/

#pragma once

#ifndef ATOM_STYLE_MACROS_HEADER
#define ATOM_STYLE_MACROS_HEADER

#include <string>

#include "AtomStyleManager.h"
#include "AtomUtils.h"

#define Css(...) ConcatStringList(std::vector<std::string>{ #__VA_ARGS__ }, ",")

#define CssStyleSheet AtomCssStyleProperties() = 

#define Query(...) AtomElementStyleQuery(ConcatStringList(std::vector<std::string>{ #__VA_ARGS__ }, ",")) = 
#define SQuery(queryString) AtomElementStyleQuery(queryString) = 

#define Rule(...) AtomElementStyleRule(ConcatStringList(std::vector<std::string>{ #__VA_ARGS__ }, ",")) = 
#define SRule(ruleString) AtomElementStyleRule(ruleString) = 

#define CssProperty(...) AtomElementStyleProperty(ConcatStringList(std::vector<std::string>{ #__VA_ARGS__ }, ","), false)
#define SCssProperty(propString) AtomElementStyleProperty(propString, false)

#endif