#pragma once

#ifndef ATOM_STYLE_MACROS_HEADER
#define ATOM_STYLE_MACROS_HEADER

#include <string>
#include "AtomStyleManager.h"

#define Css(content) std::string(#content)

#define CssStyleSheet AtomCssStyleProperties() = 

#define Query(...) AtomElementStyleQuery(#__VA_ARGS__) = 
#define SQuery(queryString) AtomElementStyleQuery(queryString) = 

#define Rule(...) AtomElementStyleRule(#__VA_ARGS__) = 
#define SRule(ruleString) AtomElementStyleRule(ruleString) = 

#define CssProperty(...) AtomElementStyleProperty(#__VA_ARGS__, false)
#define SCssProperty(propString) AtomElementStyleProperty(propString, false)

#endif