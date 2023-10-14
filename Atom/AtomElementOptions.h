/*****************************************************************************
 *
 *  PROJECT:     Atom HTML Graphics Library for `C & CPP`
 *               (https://github.com/MobinYengejehi/Atom-HTML-CPP)
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        AtomElementOptions.h
 *
 *  AUTHOR:      MobinYengejehi
 *  GITHUB:      https://github.com/MobinYengejehi
 *
 *****************************************************************************/

#pragma once

#ifndef ATOM_ELEMENT_OPTIONS_HEADER
#define ATOM_ELEMENT_OPTIONS_HEADER

#include "AtomCAPI.h"
#include "AtomStyleManager.h"

#include <variant>
#include <vector>
#include <string>

class AtomElement;

#define AtomGetElementOption std::get

#define ATOM_ELEMENT_OPTION std::variant< \
								AtomComponent, \
                                AtomComponentList, \
                                AtomElementOptionNodeName, \
                                AtomElementOptionId, \
                                AtomElementOptionClassName, \
                                AtomElementOptionAttribute, \
                                AtomElementOptionProperty, \
                                AtomElementOptionTextContent, \
                                AtomElementOptionEvent, \
                                AtomElementOptionLockable, \
                                AtomElementOptionKeepAlive, \
                                AtomElementOptionReference, \
                                AtomElementOptionInnerHTML, \
                                AtomElementStylePropertyList, \
                                AtomElementOptionNamespace, \
                                AtomElementOptionUseRef \
                            >

typedef AtomElement (*AtomElementComponent)();
typedef std::variant<AtomElement, AtomElementComponent> AtomComponent;
typedef std::vector<AtomComponent> AtomComponentList;

typedef void (*AtomElementUseRefFunctionOpiton)(AtomElement*);

struct AtomElementOptionNodeName {
	std::string value;

	AtomElementOptionNodeName& operator=(const AtomElementOptionNodeName& option);
	AtomElementOptionNodeName& operator=(const std::string& v);
};

struct AtomElementOptionId {
	std::string value;

	AtomElementOptionId& operator=(const AtomElementOptionId& option);
	AtomElementOptionId& operator=(const std::string& v);
};

struct AtomElementOptionClassName {
	std::string value;

	AtomElementOptionClassName& operator=(const AtomElementOptionClassName& option);
	AtomElementOptionClassName& operator=(const std::string& v);
};

class AtomElementOptionAttribute {
public:
	std::string key;
	std::string value;

	bool selectKey;

	AtomElementOptionAttribute();
	AtomElementOptionAttribute(const std::string& k, const bool& select);
	AtomElementOptionAttribute(const std::string& k, const std::string& v, const bool& select);

	AtomElementOptionAttribute& operator=(const std::string& v);
	AtomElementOptionAttribute& operator=(const std::vector<std::string>& option);
};

class AtomElementOptionProperty {
public:
	std::string key;
	std::string value;

	bool selectKey;

	AtomElementOptionProperty();
	AtomElementOptionProperty(const std::string& k, const bool& select);
	AtomElementOptionProperty(const std::string& k, const std::string& v, const bool& select);

	AtomElementOptionProperty& operator=(const std::string& v);
	AtomElementOptionProperty& operator=(const std::vector<std::string>& option);
};

struct AtomElementOptionTextContent {
	std::string value;

	AtomElementOptionTextContent& operator=(const AtomElementOptionTextContent& content);
	AtomElementOptionTextContent& operator=(const std::string& v);
};

struct AtomElementOptionEvent {
	std::string        name;
	ATOM_EVENT_HANDLER handler;
	
	AtomElementOptionEvent() = default;
	AtomElementOptionEvent(const std::string& n);
	AtomElementOptionEvent(const std::string& n, ATOM_EVENT_HANDLER h);

	AtomElementOptionEvent& operator=(const AtomElementOptionEvent& e);
	AtomElementOptionEvent& operator=(const std::string& n);
	AtomElementOptionEvent& operator=(ATOM_EVENT_HANDLER h);
};

struct AtomElementOptionLockable {
	bool value;

	AtomElementOptionLockable& operator=(const AtomElementOptionLockable& lock);
	AtomElementOptionLockable& operator=(const bool& v);
};

struct AtomElementOptionKeepAlive {
	bool value;

	AtomElementOptionKeepAlive& operator=(const AtomElementOptionKeepAlive& keep);
	AtomElementOptionKeepAlive& operator=(const bool& v);
};

struct AtomElementOptionReference {
	ATOM_ELEMENT_REFERENCE value;

	AtomElementOptionReference& operator=(const AtomElementOptionReference& ref);
	AtomElementOptionReference& operator=(const AtomElement& element);
	AtomElementOptionReference& operator=(const ATOM_ELEMENT_REFERENCE& v);
};

struct AtomElementOptionInnerHTML {
	std::string value;

	AtomElementOptionInnerHTML& operator=(const AtomElementOptionInnerHTML& inner);
	AtomElementOptionInnerHTML& operator=(const std::string& v);
};

struct AtomElementOptionNamespace {
	std::string value;

	AtomElementOptionNamespace& operator=(const AtomElementOptionNamespace& Namespace);
	AtomElementOptionNamespace& operator=(const std::string& v);
};

struct AtomElementOptionUseRef {
	AtomElementUseRefFunctionOpiton function;

	AtomElementOptionUseRef& operator=(const AtomElementOptionUseRef& useRef);
	AtomElementOptionUseRef& operator=(AtomElementUseRefFunctionOpiton func);
};

enum class AtomElementOptionType {
	Unknown = 0,
	Component = 1,
	ComponentList = 2,
	NodeName = 3,
	Id = 4,
	ClassName = 5,
	Attribute = 6,
	Property = 7,
	TextContent = 8,
	Event = 9,
	Lockable = 10,
	KeepAlive = 11,
	Reference = 12,
	InnerHTML = 13,
	Style = 14,
	Namespace = 15,
	UseRef = 16
};

typedef ATOM_ELEMENT_OPTION AtomElementOption;
typedef std::vector<AtomElementOption> AtomElementOptions;

AtomElementOptionType AtomGetElementOptionType(const AtomElementOption& option);

AtomElement ExtractElementFromComponent(const AtomComponent& component);

#endif