/*****************************************************************************
 *
 *  PROJECT:     Atom HTML Graphics Library for `C & CPP`
 *               (https://github.com/MobinYengejehi/Atom-HTML-CPP)
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        AtomElementOptions.cpp
 *
 *  AUTHOR:      MobinYengejehi
 *  GITHUB:      https://github.com/MobinYengejehi
 *
 *****************************************************************************/

#include "AtomElementOptions.h"
#include "AtomElement.h"

AtomElementOptionNodeName& AtomElementOptionNodeName::operator=(const AtomElementOptionNodeName& node) {
	value = node.value;
	return *this;
}

AtomElementOptionNodeName& AtomElementOptionNodeName::operator=(const std::string& v) {
	value = v;
	return *this;
}

AtomElementOptionId& AtomElementOptionId::operator=(const AtomElementOptionId& id) {
	value = id.value;
	return *this;
}

AtomElementOptionId& AtomElementOptionId::operator=(const std::string& v) {
	value = v;
	return *this;
}

AtomElementOptionClassName& AtomElementOptionClassName::operator=(const AtomElementOptionClassName& c) {
	value = c.value;
	return *this;
}

AtomElementOptionClassName& AtomElementOptionClassName::operator=(const std::string& v) {
	value = v;
	return *this;
}

AtomElementOptionAttribute::AtomElementOptionAttribute() {
	selectKey = false;
}

AtomElementOptionAttribute::AtomElementOptionAttribute(const std::string& k, const bool& select) {
	key = k;
	selectKey = select;
}

AtomElementOptionAttribute::AtomElementOptionAttribute(const std::string& k, const std::string& v, const bool& select) {
	key = k;
	value = v;
	selectKey = select;
}

AtomElementOptionAttribute& AtomElementOptionAttribute::operator=(const std::string& v) {
	if (selectKey) {
		key = v;
		return *this;
	}

	value = v;

	return *this;
}

AtomElementOptionAttribute& AtomElementOptionAttribute::operator=(const std::vector<std::string>& option) {
	if (option.size() < 2) {
		return *this;
	}

	key = option[0];
	value = option[1];

	return *this;
}

AtomElementOptionProperty::AtomElementOptionProperty() {
	selectKey = false;
}

AtomElementOptionProperty::AtomElementOptionProperty(const std::string& k, const bool& select) {
	key = k;
	selectKey = select;
}

AtomElementOptionProperty::AtomElementOptionProperty(const std::string& k, const std::string& v, const bool& select) {
	key = k;
	value = v;
	selectKey = select;
}

AtomElementOptionProperty& AtomElementOptionProperty::operator=(const std::string& v) {
	if (selectKey) {
		key = v;
		return *this;
	}

	value = v;
	
	return *this;
}

AtomElementOptionProperty& AtomElementOptionProperty::operator=(const std::vector<std::string>& option) {
	if (option.size() < 2) {
		return *this;
	}

	key = option[0];
	value = option[1];

	return *this;
}

AtomElementOptionTextContent& AtomElementOptionTextContent::operator=(const AtomElementOptionTextContent& content) {
	value = content.value;
	
	return *this;
}

AtomElementOptionTextContent& AtomElementOptionTextContent::operator=(const std::string& v) {
	value = v;

	return *this;
}

AtomElementOptionEvent::AtomElementOptionEvent(const std::string& n) {
	name = n;
}

AtomElementOptionEvent::AtomElementOptionEvent(const std::string& n, ATOM_EVENT_HANDLER h) {
	name = n;
	handler = h;
}

AtomElementOptionEvent& AtomElementOptionEvent::operator=(const AtomElementOptionEvent& e) {
	name = e.name;
	handler = e.handler;

	return *this;
}

AtomElementOptionEvent& AtomElementOptionEvent::operator=(const std::string& n) {
	name = n;

	return *this;
}

AtomElementOptionEvent& AtomElementOptionEvent::operator=(ATOM_EVENT_HANDLER h) {
	handler = h;

	return *this;
}

AtomElementOptionLockable& AtomElementOptionLockable::operator=(const AtomElementOptionLockable& lock) {
	value = lock.value;
	
	return *this;
}

AtomElementOptionLockable& AtomElementOptionLockable::operator=(const bool& v) {
	value = v;
	
	return *this;
}

AtomElementOptionKeepAlive& AtomElementOptionKeepAlive::operator=(const AtomElementOptionKeepAlive& keep) {
	value = keep.value;
	
	return *this;
}

AtomElementOptionKeepAlive& AtomElementOptionKeepAlive::operator=(const bool& v) {
	value = v;

	return *this;
}

AtomElementOptionReference& AtomElementOptionReference::operator=(const AtomElementOptionReference& ref) {
	value = ref.value;

	return *this;
}

AtomElementOptionReference& AtomElementOptionReference::operator=(const AtomElement& element) {
	value = element.GetHandle();

	return *this;
}

AtomElementOptionReference& AtomElementOptionReference::operator=(const ATOM_ELEMENT_REFERENCE& v) {
	value = v;

	return *this;
}

AtomElementOptionInnerHTML& AtomElementOptionInnerHTML::operator=(const AtomElementOptionInnerHTML& inner) {
	value = inner.value;

	return *this;
}

AtomElementOptionInnerHTML& AtomElementOptionInnerHTML::operator=(const std::string& v) {
	value = v;

	return *this;
}

AtomElementOptionNamespace& AtomElementOptionNamespace::operator=(const AtomElementOptionNamespace& Namespace) {
	value = Namespace.value;

	return *this;
}

AtomElementOptionNamespace& AtomElementOptionNamespace::operator=(const std::string& v) {
	value = v;

	return *this;
}

AtomElementOptionType AtomGetElementOptionType(const AtomElementOption& option) {
	if (std::holds_alternative<AtomElement>(option)) {
		return AtomElementOptionType::Element;
	}else if (std::holds_alternative<AtomElementList>(option)) {
		return AtomElementOptionType::ElementList;
	}else if (std::holds_alternative<AtomElementOptionNodeName>(option)) {
		return AtomElementOptionType::NodeName;
	}else if (std::holds_alternative<AtomElementOptionId>(option)) {
		return AtomElementOptionType::Id;
	}else if (std::holds_alternative<AtomElementOptionClassName>(option)) {
		return AtomElementOptionType::ClassName;
	}else if (std::holds_alternative<AtomElementOptionAttribute>(option)) {
		return AtomElementOptionType::Attribute;
	}else if (std::holds_alternative<AtomElementOptionProperty>(option)) {
		return AtomElementOptionType::Property;
	}else if (std::holds_alternative<AtomElementOptionTextContent>(option)) {
		return AtomElementOptionType::TextContent;
	}else if (std::holds_alternative<AtomElementOptionEvent>(option)) {
		return AtomElementOptionType::Event;
	}else if (std::holds_alternative<AtomElementOptionLockable>(option)) {
		return AtomElementOptionType::Lockable;
	}else if (std::holds_alternative<AtomElementOptionKeepAlive>(option)) {
		return AtomElementOptionType::KeepAlive;
	}else if (std::holds_alternative<AtomElementOptionReference>(option)) {
		return AtomElementOptionType::Reference;
	}else if (std::holds_alternative<AtomElementOptionInnerHTML>(option)) {
		return AtomElementOptionType::InnerHTML;
	}else if (std::holds_alternative<AtomElementStylePropertyList>(option)) {
		return AtomElementOptionType::Style;
	}else if (std::holds_alternative<AtomElementOptionNamespace>(option)) {
		return AtomElementOptionType::Namespace;
	}

	return AtomElementOptionType::Unknown;
}