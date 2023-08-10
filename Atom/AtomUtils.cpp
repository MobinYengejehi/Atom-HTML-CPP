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