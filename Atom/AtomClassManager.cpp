/*****************************************************************************
 *
 *  PROJECT:     Atom HTML Graphics Library for `C & CPP`
 *               (https://github.com/MobinYengejehi/Atom-HTML-CPP)
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        AtomClassManager.cpp
 *
 *  AUTHOR:      MobinYengejehi
 *  GITHUB:      https://github.com/MobinYengejehi
 *
 *****************************************************************************/

#include "AtomClassManager.h"

AtomClassManager::AtomClassManager() {
	reference = NULL;
}

AtomClassManager::AtomClassManager(const ATOM_ELEMENT_REFERENCE& elementReference) {
	TakeOwnership(elementReference);
}

ATOM_ELEMENT_REFERENCE& AtomClassManager::GetHandle() {
	return reference;
}

void AtomClassManager::GetList(AtomClassList* list) {
	if (!list) {
		return;
	}

	char* classNamePointer = atom_get_element_property(reference, "className");
	
	if (!classNamePointer) {
		return;
	}

	std::string className = classNamePointer;

	free((void*)classNamePointer);

	if (className.empty()) {
		return;
	}

	size_t length = className.length();
	size_t last = 0;

	for (size_t i = 0; i < length; i++) {
		char byte = className[i];

		if (byte == 0x20) {
			list->push_back(className.substr(last, i - last));
			last = i + 1;
		}
	}

	std::string lastClass = className.substr(last);
	if (lastClass.empty()) {
		return;
	}

	list->push_back(lastClass);
}

std::string AtomClassManager::GetClassName() {
	char* className = atom_get_element_property(reference, "className");

	if (!className) {
		return std::string();
	}

	std::string classNameString = className;

	free((void*)className);

	return classNameString;
}

void AtomClassManager::TakeOwnership(const ATOM_ELEMENT_REFERENCE& elementReference) {
	reference = elementReference;
}

void AtomClassManager::AddClass(const std::string& className) {
	if (className.empty()) {
		return;
	}

	atom_add_element_class(reference, className.c_str());
}

void AtomClassManager::RemoveClass(const std::string& className) {
	if (className.empty()) {
		return;
	}

	atom_remove_element_class(reference, className.c_str());
}

void AtomClassManager::SetClassName(const std::string& className) {
	if (className.empty()) {
		return;
	}

	atom_set_element_property(reference, "className", className.c_str());
}

bool AtomClassManager::Contains(const std::string& className) {
	if (className.empty()) {
		return false;
	}

	return atom_element_class_exists(reference, className.c_str());
}

void AtomClassManager::operator+=(const std::string& className) {
	AddClass(className);
}

void AtomClassManager::operator-=(const std::string& className) {
	RemoveClass(className);
}

AtomClassManager::operator bool() {
	return reference == NULL ? false : atom_element_exists(reference);
}