/*****************************************************************************
 *
 *  PROJECT:     Atom HTML Graphics Library for `C & CPP`
 *               (https://github.com/MobinYengejehi/Atom-HTML-CPP)
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        AtomElement.cpp
 *
 *  AUTHOR:      MobinYengejehi
 *  GITHUB:      https://github.com/MobinYengejehi
 *
 *****************************************************************************/

#include "AtomElement.h"

AtomElement::AtomElement() {
	SetLockedState(false);
	KeepAlive(false);
	SetLastUseState(false);
	TakeOwnership(NULL);
}

AtomElement::AtomElement(const std::string& type) {
	SetLockedState(false);
	KeepAlive(false);
	SetLastUseState(false);

	if (type.empty()) {
		TakeOwnership(NULL);
		return;
	}

	TakeOwnership(atom_create_element(type.c_str()));
}

AtomElement::AtomElement(const std::string& type, const std::string& ns) {
	SetLockedState(false);
	KeepAlive(false);
	SetLastUseState(false);

	Namespace = ns;

	if (type.empty() || Namespace.empty()) {
		TakeOwnership(NULL);
		return;
	}

	TakeOwnership(atom_create_element(type.c_str(), Namespace.c_str()));
}

AtomElement::AtomElement(const std::string& type, const bool& lock) {
	SetLockedState(lock);
	KeepAlive(false);
	SetLastUseState(false);

	if (type.empty()) {
		TakeOwnership(NULL);
		return;
	}

	TakeOwnership(atom_create_element(type.c_str()));
}

AtomElement::AtomElement(const std::string& type, const std::string& ns, const bool& lock) {
	SetLockedState(lock);
	KeepAlive(false);
	SetLastUseState(false);

	Namespace = ns;

	if (type.empty() || Namespace.empty()) {
		TakeOwnership(NULL);
		return;
	}

	TakeOwnership(atom_create_element(type.c_str(), Namespace.c_str()));
}

AtomElement::AtomElement(const std::string& type, const bool& lock, const bool& keep) {
	SetLockedState(lock);
	KeepAlive(keep);
	SetLastUseState(false);

	if (type.empty()) {
		TakeOwnership(NULL);
		return;
	}

	TakeOwnership(atom_create_element(type.c_str()));
}

AtomElement::AtomElement(const std::string& type, const bool& lock, const bool& keep, const bool& use) {
	SetLockedState(lock);
	KeepAlive(keep);
	SetLastUseState(use);

	if (type.empty()) {
		TakeOwnership(NULL);
		return;
	}

	TakeOwnership(atom_create_element(type.c_str()));
}

AtomElement::AtomElement(const std::string& type, const std::string& ns, const bool& lock, const bool& keep) {
	SetLockedState(lock);
	KeepAlive(keep);
	SetLastUseState(false);

	Namespace = ns;

	if (type.empty() || Namespace.empty()) {
		TakeOwnership(NULL);
		return;
	}

	TakeOwnership(atom_create_element(type.c_str(), Namespace.c_str()));
}

AtomElement::AtomElement(const std::string& type, const std::string& ns, const bool& lock, const bool& keep, const bool& use) {
	SetLockedState(lock);
	KeepAlive(keep);
	SetLastUseState(use);

	Namespace = ns;

	if (type.empty() || Namespace.empty()) {
		TakeOwnership(NULL);
		return;
	}

	TakeOwnership(atom_create_element(type.c_str(), Namespace.c_str()));
}

AtomElement::AtomElement(const ATOM_ELEMENT_REFERENCE& elementReference) {
	SetLockedState(false);
	KeepAlive(false);
	SetLastUseState(false);
	TakeOwnership(elementReference);
}

AtomElement::AtomElement(const ATOM_ELEMENT_REFERENCE& elementReference, const bool& lock) {
	SetLockedState(lock);
	KeepAlive(false);
	SetLastUseState(false);
	TakeOwnership(elementReference);
}

AtomElement::AtomElement(const ATOM_ELEMENT_REFERENCE& elementReference, const bool& lock, const bool& keep) {
	SetLockedState(lock);
	KeepAlive(keep);
	SetLastUseState(false);
	TakeOwnership(elementReference);
}

AtomElement::AtomElement(const ATOM_ELEMENT_REFERENCE& elementReference, const bool& lock, const bool& keep, const bool& use) {
	SetLockedState(lock);
	KeepAlive(keep);
	SetLastUseState(use);
	TakeOwnership(elementReference);
}

AtomElement::AtomElement(const AtomElementOptions& options) {
	ApplyOptions(options);
}

AtomElement::~AtomElement() {
	if (keepReference) {
		return;
	}

	if (reference == NULL) {
		return;
	}

	if (locked) {
		Destroy();
		return;
	}

	atom_free_element(reference);
}

std::string AtomElement::GetNodeName() const {
	char* nodeName = atom_get_element_node_name(reference);
	
	if (!nodeName) {
		return std::string();
	}

	std::string nodeNameString = nodeName;

	free((void*)nodeName);

	return nodeNameString;
}

std::string AtomElement::GetAttribute(const std::string& attribute) const {
	if (attribute.empty()) {
		return std::string();
	}

	char* value = atom_get_element_attribute(reference, attribute.c_str());

	if (!value) {
		return std::string();
	}

	std::string valueString = value;

	free((void*)value);

	return valueString;
}

std::string AtomElement::GetProperty(const std::string& propertyName) const {
	if (propertyName.empty()) {
		return std::string();
	}

	char* value = atom_get_element_property(reference, propertyName.c_str());

	if (!value) {
		return std::string();
	}

	std::string valueString = value;

	free((void*)value);

	return valueString;
}

ATOM_ELEMENT_REFERENCE AtomElement::GetHandle() const {
	return reference;
}

ATOM_BOUNDING_BOX AtomElement::GetBoundingBox() const {
	return atom_get_element_bounding_box(reference);
}

AtomClassManager& AtomElement::GetClassManager() {
	return classManager;
}

AtomStyleManager& AtomElement::GetStyleManager() {
	return styleManager;
}

void AtomElement::GetParent(AtomElement* parentElement) {
	if (!parentElement) {
		return;
	}

	ATOM_ELEMENT_REFERENCE parent = atom_get_element_parent(reference);

	if (parent == NULL) {
		parentElement->TakeOwnership(NULL);
		return;
	}

	parentElement->TakeOwnership(parent);
}

size_t AtomElement::GetChildCount() {
	return atom_get_element_child_count(reference);
}

void AtomElement::QuerySelector(const std::string& query, AtomElement* element) {
	if (query.empty()) {
		return;
	}

	if (!element) {
		return;
	}

	ATOM_ELEMENT_REFERENCE elementReference = atom_query_selector(reference, query.c_str());

	if (elementReference == NULL) {
		element->TakeOwnership(NULL);
		return;
	}

	element->TakeOwnership(elementReference);
}

void AtomElement::QuerySelectorAll(const std::string& query, AtomElementList* elementList) {
	if (query.empty()) {
		return;
	}

	if (!elementList) {
		return;
	}

	ATOM_ELEMENT_REFERENCE_LIST list = atom_query_selector_all(reference, query.c_str());

	if (list.empty()) {
		return;
	}

	for (const ATOM_ELEMENT_REFERENCE& element : list) {
		elementList->push_back(AtomElement(element, false, true));
	}
}

void AtomElement::AppendChild(const AtomElement& child) {
	atom_element_append_child(reference, child.GetHandle());
}

void AtomElement::SetParent(const AtomElement& parent) {
	atom_element_append_child(parent.GetHandle(), reference);
}

void AtomElement::SetAttribute(const std::string& attribute, const std::string& value) {
	if (attribute.empty()) {
		return;
	}

	if (value.empty()) {
		return;
	}

	atom_set_element_attribute(reference, attribute.c_str(), value.c_str());
}

void AtomElement::SetProperty(const std::string& propertyName, const std::string& value) {
	if (propertyName.empty()) {
		return;
	}

	if (value.empty()) {
		return;
	}

	atom_set_element_property(reference, propertyName.c_str(), value.c_str());
}

void AtomElement::SetLockedState(const bool& lock) {
	locked = lock;
}

void AtomElement::KeepAlive(const bool& keep) {
	keepReference = keep;
}


void AtomElement::SetLastUseState(const bool& use) {
	lastUse = use;
}

AtomElement AtomElement::RemovableCopy() {
	AtomElement copy;
	
	copy.TakeOwnership(reference);
	copy.SetLockedState(locked);
	copy.KeepAlive(false);
	copy.SetLastUseState(false);
	
	return copy;
}

ATOM_ELEMENT_REFERENCE AtomElement::CloneReference() {
	return (ATOM_ELEMENT_REFERENCE)ATOM_DIRECT_ASM({
		const element = atom_get_element_by_reference($0);
		
		if (!element) {
			return NULL;
		}

		return atom_create_element_reference(element);
	}, reference);
}

void AtomElement::TakeOwnership(const ATOM_ELEMENT_REFERENCE& elementReference) {
	reference = elementReference;
	
	classManager = AtomClassManager(elementReference);
	styleManager = AtomStyleManager(elementReference);
}

void AtomElement::TakeOwnership(const AtomElement& element) {
	SetLockedState(element.IsLocked());
	KeepAlive(element.IsLastUsed() ? false : element.IsKeepingAliveReference());
	TakeOwnership(element.GetHandle());
}

void AtomElement::Destroy() {
	atom_destroy_element(reference);
}

void AtomElement::Clear() {
	ATOM_DIRECT_ASM({
		const reference = $0;

		const element = atom_get_element_by_reference(reference);
		if (!element) {
			return;
		}

		element.innerHTML = "";
	}, reference);
}

void AtomElement::ScrollToView(std::string viewType) {
	if (viewType.empty()) {
		atom_scroll_to_element(reference);
		return;
	}

	atom_scroll_to_element(reference, viewType.c_str());
}

void AtomElement::AddEvent(const std::string& eventName, ATOM_EVENT_HANDLER handler) {
	if (eventName.empty()) {
		return;
	}

	if (!handler) {
		return;
	}

	atom_add_event_listener(reference, eventName.c_str(), handler);
}

void AtomElement::ApplyOption(const AtomElementOption& option) {
	AtomElementOptionType type = AtomGetElementOptionType(option);

	if (type == AtomElementOptionType::Element) {
		AtomElement child = AtomGetElementOption<AtomElement>(option);

		AppendChild(child);

		atom_free_element(child.GetHandle());
	}else if (type == AtomElementOptionType::ElementList) {
		AtomElementList children = AtomGetElementOption<AtomElementList>(option);

		if (children.empty()) {
			return;
		}

		for (const AtomElement& child : children) {
			AppendChild(child);
		}

		AtomFreeElementList(children);
	}else if (type == AtomElementOptionType::NodeName) {
		AtomElementOptionNodeName nodeNameOption = AtomGetElementOption<AtomElementOptionNodeName>(option);
			
		std::string nodeName = nodeNameOption.value;

		if (nodeName.empty()) {
			return;
		}

		ATOM_ELEMENT_REFERENCE ref = NULL;

		if (!Namespace.empty()) {
			ref = atom_create_element(nodeName.c_str(), Namespace.c_str());
		}else{
			ref = atom_create_element(nodeName.c_str());
		}

		atom_free_element(reference);

		TakeOwnership(ref);
	}else if (type == AtomElementOptionType::Id) {
		AtomElementOptionId id = AtomGetElementOption<AtomElementOptionId>(option);

		SetProperty("id", id.value);
	}else if (type == AtomElementOptionType::ClassName) {
		AtomElementOptionClassName className = AtomGetElementOption<AtomElementOptionClassName>(option);

		classManager.SetClassName(className.value);
	}else if (type == AtomElementOptionType::Attribute) {
		AtomElementOptionAttribute attribute = AtomGetElementOption<AtomElementOptionAttribute>(option);

		SetAttribute(attribute.key, attribute.value);
	}else if (type == AtomElementOptionType::Property) {
		AtomElementOptionProperty prop = AtomGetElementOption<AtomElementOptionProperty>(option);

		SetProperty(prop.key, prop.value);
	}else if (type == AtomElementOptionType::TextContent) {
		AtomElementOptionTextContent content = AtomGetElementOption<AtomElementOptionTextContent>(option);

		SetProperty("textContent", content.value);
	}else if (type == AtomElementOptionType::Event) {
		AtomElementOptionEvent e = AtomGetElementOption<AtomElementOptionEvent>(option);

		AddEvent(e.name, e.handler);
	}else if (type == AtomElementOptionType::Lockable) {
		AtomElementOptionLockable state = AtomGetElementOption<AtomElementOptionLockable>(option);

		SetLockedState(state.value);
	}else if (type == AtomElementOptionType::KeepAlive) {
		AtomElementOptionKeepAlive state = AtomGetElementOption<AtomElementOptionKeepAlive>(option);

		KeepAlive(state.value);
	}else if (type == AtomElementOptionType::Reference) {
		AtomElementOptionReference ref = AtomGetElementOption<AtomElementOptionReference>(option);

		reference = ref.value;
	}else if (type == AtomElementOptionType::InnerHTML) {
		AtomElementOptionInnerHTML inner = AtomGetElementOption<AtomElementOptionInnerHTML>(option);

		SetProperty("innerHTML", GetProperty("innerHTML") + inner.value);
	}else if (type == AtomElementOptionType::Style) {
		AtomElementStylePropertyList properties = AtomGetElementOption<AtomElementStylePropertyList>(option);

		styleManager.ApplyProperties(properties);
	}else if (type == AtomElementOptionType::Namespace) {
		AtomElementOptionNamespace NamespaceO = AtomGetElementOption<AtomElementOptionNamespace>(option);

		Namespace = NamespaceO.value;
	}
}

void AtomElement::ApplyOptions(const AtomElementOptions& options) {
	if (options.empty()) {
		return;
	}

	for (const AtomElementOption& option : options) {
		ApplyOption(option);
	}
}

bool AtomElement::IsLocked() const {
	return locked;
}

bool AtomElement::IsKeepingAliveReference() const {
	return keepReference;
}

bool AtomElement::IsLastUsed() const {
	return lastUse;
}

std::string AtomElement::operator[](const std::string& propertyName) const {
	return GetProperty(propertyName);
}

AtomElement& AtomElement::operator+=(const AtomElement& child) {
	AppendChild(child);
	return *this;
}

AtomElement& AtomElement::operator=(const AtomElement& element) {
	SetLockedState(element.IsLocked());
	KeepAlive(element.IsLastUsed() ? false : element.IsKeepingAliveReference());
	TakeOwnership(element.GetHandle());

	return *this;
}

AtomElement& AtomElement::operator=(const AtomElementOptions& options) {
	ApplyOptions(options);
	return *this;
}

bool AtomElement::operator==(const AtomElement& target) const {
	return atom_is_same_element(reference, target.GetHandle());
}

bool AtomElement::operator==(const ATOM_ELEMENT_REFERENCE& target) const {
	return atom_is_same_element(reference, target);
}

AtomElement::operator bool() {
	return reference == NULL ? false : atom_element_exists(reference);
}

AtomElement AtomGetDocumentElement() {
	ATOM_ELEMENT_REFERENCE ref = atom_query_selector("html");

	return AtomElement(ref);
}

AtomElement AtomGetDocumentHeadElement() {
	ATOM_ELEMENT_REFERENCE ref = atom_get_document_head();

	return AtomElement(ref, false, true);
}

AtomElement AtomGetDocumentBodyElement() {
	ATOM_ELEMENT_REFERENCE ref = atom_get_document_body();

	return AtomElement(ref, false ,true);
}

AtomElement AtomGetElementFromJS(ATOM_JS_VARIABLE val) {
	if (val.isNull()) {
		return NULL;
	}

	return ATOM_JS_VARIABLE::global(NULL).call<ATOM_ELEMENT_REFERENCE>("atom_create_element_reference", val);
}

void AtomFreeElementList(const AtomElementList& elements) {
	if (elements.empty()) {
		return;
	}

	for (const AtomElement& element : elements) {
		atom_free_element(element.GetHandle());
	}
}