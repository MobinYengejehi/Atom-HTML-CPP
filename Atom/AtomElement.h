/*****************************************************************************
 *
 *  PROJECT:     Atom HTML Graphics Library for `C & CPP`
 *               (https://github.com/MobinYengejehi/Atom-HTML-CPP)
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        AtomElement.h
 *
 *  AUTHOR:      MobinYengejehi
 *  GITHUB:      https://github.com/MobinYengejehi
 *
 *****************************************************************************/

#pragma once

#ifndef ATOM_ELEMENT_HEADER
#define ATOM_ELEMENT_HEADER

#include "AtomJSDefinitions.h"
#include "AtomClassManager.h"
#include "AtomStyleManager.h"
#include "AtomElementOptions.h"

#include <string>
#include <vector>

class AtomElement;

typedef std::vector<AtomElement> AtomElementList;

class AtomElement {
public:
	AtomElement();
	AtomElement(const std::string& type);
	AtomElement(const std::string& type, const bool& lock);
	AtomElement(const std::string& type, const bool& lock, const bool& keep);
	AtomElement(const ATOM_ELEMENT_REFERENCE& elementReference);
	AtomElement(const ATOM_ELEMENT_REFERENCE& elementReference, const bool& lock);
	AtomElement(const ATOM_ELEMENT_REFERENCE& elementReference, const bool& lock, const bool& keep);
	AtomElement(const AtomElementOptions& options);
	~AtomElement();

	std::string            GetNodeName() const;
	std::string            GetAttribute(const std::string& attribute) const;
	std::string            GetProperty(const std::string& propertyName) const;
	ATOM_ELEMENT_REFERENCE GetHandle() const;
	ATOM_BOUNDING_BOX      GetBoundingBox() const;
	AtomClassManager&      GetClassManager();
	AtomStyleManager&      GetStyleManager();
	void                   GetParent(AtomElement* parent);

	void QuerySelector(const std::string& query , AtomElement* element);
	void QuerySelectorAll(const std::string& query, AtomElementList* elementList);

	void AppendChild(const AtomElement& child);
	void SetParent(const AtomElement& parent);
	void SetAttribute(const std::string& attribute, const std::string& value);
	void SetProperty(const std::string& propertyName, const std::string& value);
	void SetLockedState(const bool& lock);
	void KeepAlive(const bool& keep);

	void TakeOwnership(const ATOM_ELEMENT_REFERENCE& elementReference);
	void TakeOwnership(const AtomElement& element);

	void Destroy();

	void AddEvent(const std::string& eventName, ATOM_EVENT_HANDLER handler);

	void ApplyOption(const AtomElementOption& option);
	void ApplyOptions(const AtomElementOptions& options);

	bool IsLocked() const;
	bool IsKeepingAliveReference() const;

	std::string  operator[](const std::string& propertyName) const;
	AtomElement& operator+=(const AtomElement& child);
	bool         operator==(const AtomElement& target) const;
	bool         operator==(const ATOM_ELEMENT_REFERENCE& target) const;

	AtomElement& operator=(const AtomElement& element);
	AtomElement& operator=(const AtomElementOptions& options);

	operator bool();

private:
	bool locked;
	bool keepReference;

	ATOM_ELEMENT_REFERENCE reference;

	AtomClassManager classManager;
	AtomStyleManager styleManager;
};

AtomElement AtomGetDocumentElement();
AtomElement AtomGetDocumentHeadElement();
AtomElement AtomGetDocumentBodyElement();

#endif