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
#include <ctime>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#ifndef M_PI_2
#define M_PI_2 1.57079632679489661923
#endif

#ifndef M_PI_4
#define M_PI_4 0.78539816339744830962
#endif

#ifndef M_1_PI
#define M_1_PI 0.31830988618379067154
#endif

#ifndef M_2_PI
#define M_2_PI 0.63661977236758134308
#endif

std::string ConcatStringList(const std::vector<std::string>& list, const std::string& with);

std::string TrimString(const std::string& content);

void SplitString(const std::string& str, const std::string& with, std::vector<std::string>* list);

std::string ReplaceString(const std::string& str, const std::string& what, const std::string& with);

void ReverseString(std::string* str);

size_t GetStringSectionCount(const std::string& str, const std::string& with);
long FindStringSection(const std::string& str, const std::string& what, size_t where = 0);

std::string RepeatString(const std::string& str, const size_t& times, std::string concat = "");

float Random();
void  UpdateRandomSeed(unsigned int seed = static_cast<unsigned int>(std::time(NULL)));

double Round(const double& number);

double ToRadian(const double& a);

#endif