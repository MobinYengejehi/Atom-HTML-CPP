/*****************************************************************************
 *
 *  PROJECT:     Atom HTML Graphics Library for `C & CPP`
 *               (https://github.com/MobinYengejehi/Atom-HTML-CPP)
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        AtomUtils.cpp
 *
 *  AUTHOR:      MobinYengejehi
 *  GITHUB:      https://github.com/MobinYengejehi
 *
 *****************************************************************************/

#include "AtomUtils.h"
#include "AtomCAPI.h"

#include <cmath>

std::string ConcatStringList(const std::vector<std::string>& list, const std::string& with) {
	std::string result;

	for (const std::string& str : list) {
		result += str;
		result += with;
	}

	size_t withLength = with.length();

	if (!result.empty()) for (size_t i = 0; i < withLength; i++, result.pop_back());

	return result;
}

std::string TrimString(const std::string& content) {
	std::string result;

	if (content.empty()) {
		return result;
	}
	
	size_t length = content.length();

	size_t startPos = 0;
	size_t endPos = length - 1;

	for (size_t i = 0; i < length; i++) {
		char byte = content[i];
		if (byte != 0x20) {
			startPos = i;
			break;
		}
	}

	for (size_t i = length - 1; i >= 0; i--) {
		char byte = content[i];
		if (byte != 0x20) {
			endPos = i;
			break;
		}
	}

	result = content.substr(startPos, endPos - startPos + 1);

	return result;
}

void SplitString(const std::string& str, const std::string& with, std::vector<std::string>* list) {
	if (str.empty()) {
		return;
	}

	if (with.empty()) {
		return;
	}

	if (!list) {
		return;
	}

	size_t stringLength = str.length();
	size_t withLength = with.length();

	size_t last = 0;

	for (size_t i = 0; i < stringLength; i++) {
		if (str.substr(i, withLength) == with) {
			list->push_back(str.substr(last, i - last));
			last = i + withLength;
		}
	}

	if (last > 0 && last < stringLength) {
		list->push_back(str.substr(last));
	}
}

std::string ReplaceString(const std::string& str, const std::string& what, const std::string& with) {
	std::string result;

	if (str.empty()) {
		return result;
	}

	if (what.empty()) {
		return str;
	}

	std::vector<std::string> list;
	SplitString(str, what, &list);

	if (list.empty()) {
		return str;
	}

	for (const std::string& part : list) {
		result += part;
		result += with;
	}
	
	if (!result.empty()) {
		size_t withLength = with.length();

		if (withLength > 0) {
			result = result.substr(0, result.length() - withLength);
		}
	}

	return result;
}

void ReverseString(std::string* str) {
	if (!str) {
		return;
	}

	size_t length = str->size();
	
	//char copy[length];
	//char result[length];

	char* copy = new char[length];
	char* result = new char[length];

	str->copy(copy, length);

	for (int i = 0, ci = length - 1; i < length; i++, ci--) {
		result[i] = copy[ci];
	}

	*str = std::string(result, length);

	free((void*)copy);
	free((void*)result);
}

size_t GetStringSectionCount(const std::string& str, const std::string& with) {
	if (str.empty()) {
		return 0;
	}

	if (with.empty()) {
		return 0;
	}

	size_t count = 0;

	size_t stringLength = str.length();
	size_t withLength = with.length();

	for (size_t i = 0; i < stringLength; i++) {
		if (str.substr(i, withLength) == with) {
			count++;
		}
	}

	return count;
}

long FindStringSection(const std::string& str, const std::string& what, size_t where) {
	if (str.empty()) {
		return -1;
	}

	if (what.empty()) {
		return -1;
	}

	size_t stringLength = str.length();
	size_t whatLength = what.length();

	for (size_t i = where; i < stringLength; i++) {
		if (str.substr(i, whatLength) == what) {
			return i;
		}
	}

	return -1;
}

std::string RepeatString(const std::string& str, const size_t& times, std::string concat) {
	std::string result;

	if (str.empty()) {
		return result;
	}

	if (times < 1) {
		return result;
	}

	for (size_t i = 0; i < times; i++, result += str + concat);

	size_t conLength = concat.length();

	if (!result.empty() && conLength > 0) {
		result = result.substr(0, result.length() - conLength);
	}

	return result;
}

float Random() {
	return (float)std::rand() / (float)RAND_MAX;
}

void UpdateRandomSeed(unsigned int seed) {
	std::srand(seed);
}

double Round(const double& number) {
	if (number >= 0) {
		return std::round(number);
	}

	return atom_mod_number(number, 0.5) == 0 ? std::floor(number) : std::round(number);
}

double ToRadian(const double& a) {
	return a * (M_PI / 180.0f);
}
