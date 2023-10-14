/*****************************************************************************
 *
 *  PROJECT:     Atom HTML Graphics Library for `C & CPP`
 *               (https://github.com/MobinYengejehi/Atom-HTML-CPP)
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        AtomClassManager.h
 *
 *  AUTHOR:      MobinYengejehi
 *  GITHUB:      https://github.com/MobinYengejehi
 *
 *****************************************************************************/

#pragma once

#ifndef ATOM_CLASS_MANAGER
#define ATOM_CLASS_MANAGER

#include "AtomCAPI.h"

#include <string>
#include <vector>

typedef std::vector<std::string> AtomClassList;

class AtomClassManager {
public:
	AtomClassManager();
	AtomClassManager(const ATOM_ELEMENT_REFERENCE& elementReference);
	~AtomClassManager() = default;

	ATOM_ELEMENT_REFERENCE& GetHandle();
	void                    GetList(AtomClassList* classList);
	std::string             GetClassName();

	void TakeOwnership(const ATOM_ELEMENT_REFERENCE& elementReference);
	void AddClass(const std::string& className);
	void RemoveClass(const std::string& className);
	void ToggleClass(const std::string& className);
	void SetClassName(const std::string& className);

	bool Contains(const std::string& className);

	void operator+=(const std::string& className);
	void operator-=(const std::string& className);

	operator bool();

private:
	ATOM_ELEMENT_REFERENCE reference;
};

#endif