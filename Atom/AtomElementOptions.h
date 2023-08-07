#pragma once

#ifndef ATOM_ELEMENT_OPTIONS_HEADER
#define ATOM_ELEMENT_OPTIONS_HEADER

#include "AtomJSDefinitions.h"
#include "AtomStyleManager.h"

#include <variant>
#include <vector>
#include <string>

class AtomElement;

#define AtomGetElementOption std::get

#define ATOM_ELEMENT_OPTION std::variant< \
                                AtomElement, \
                                std::vector<AtomElement>, \
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
                                AtomElementStylePropertyList \
                            >

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

enum class AtomElementOptionType {
	Unknown = 0,
	Element = 1,
	ElementList = 2,
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
	Style = 14
};

typedef ATOM_ELEMENT_OPTION AtomElementOption;
typedef std::vector<AtomElementOption> AtomElementOptions;

AtomElementOptionType AtomGetElementOptionType(const AtomElementOption& option);

#endif