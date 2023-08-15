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
			last = i + 1;
		}
	}

	if (last > 0 && last < stringLength) {
		list->push_back(str.substr(last));
	}
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