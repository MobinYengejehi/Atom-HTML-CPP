#include "AtomStyleManager.h"
#include "AtomElement.h"

AtomElementStyleProperty::AtomElementStyleProperty(const std::string& k, const bool& select) {
	key = k;
	selectKey = select;
}

AtomElementStyleProperty::AtomElementStyleProperty(const std::string& k, const std::string& v, const bool& select) {
	key = k;
	value = v;
	selectKey = select;
}

AtomElementStyleProperty::AtomElementStyleProperty(const std::string& k, const std::string& v) {
	key = k;
	value = v;
	selectKey = false;
}

AtomElementStyleProperty& AtomElementStyleProperty::operator=(const std::string& v) {
	if (selectKey) {
		key = v;

		return *this;
	}

	value = v;

	return *this;
}

AtomElementStyleProperty& AtomElementStyleProperty::operator=(const double& v) {
	if (selectKey) {
		key = std::to_string(v) + "px";
		
		return *this;
	}

	value = std::to_string(v) + "px";

	return *this;
}

AtomElementStyleQuery::AtomElementStyleQuery(const std::string& q) {
	query = q;
}

AtomElementStyleQuery& AtomElementStyleQuery::operator=(const AtomElementStylePropertyList& list) {
	options = list;

	return *this;
}

AtomElementStyleRule::AtomElementStyleRule(const std::string& r) {
	rule = r;
}

AtomElementStyleRule& AtomElementStyleRule::operator=(const AtomElementStyleQueryList& qlist) {
	queryList = qlist;

	return *this;
}


void AtomStyleBuilder::AddRule(const AtomElementStyleRule& rule) {
	rules.push_back(rule);
}

void AtomStyleBuilder::AddRules(const AtomElementStyleRuleList& ruleList) {
	for (const AtomElementStyleRule& rule : ruleList) {
		AddRule(rule);
	}
}

void AtomStyleBuilder::AddCssStyleProperty(const AtomCssStyleProperty& prop) {
	if (std::holds_alternative<AtomElementStyleRule>(prop)) {
		AddRule(std::get<AtomElementStyleRule>(prop));
	}else if (std::holds_alternative<AtomElementStyleQuery>(prop)) {
		AddRule(AtomElementStyleRule("") = { std::get<AtomElementStyleQuery>(prop) });
	}
}

void AtomStyleBuilder::AddCssStyleProperties(const AtomCssStyleProperties& props) {
	for (const AtomCssStyleProperty& prop : props) {
		AddCssStyleProperty(prop);
	}
}

AtomElementStyleRuleList& AtomStyleBuilder::GetRules() {
	return rules;
}

void AtomStyleBuilder::Build(std::string* content) {
	if (rules.empty()) {
		return;
	}

	std::string css = "";

	for (const AtomElementStyleRule& rule : rules) {
		if (!rule.rule.empty()) {
			css += rule.rule;
			css += "{";
		}

		for (const AtomElementStyleQuery& query : rule.queryList) {
			css += query.query;
			css += "{";

			for (const AtomElementStyleProperty& prop : query.options) {
				css += prop.key;
				css += ":";
				css += prop.value;
				css += ";";
			}

			css += "}";
		}

		if (!rule.rule.empty()) {
			css += "}";
		}
	}

	*content = css;
}

AtomStyleManager::AtomStyleManager() {
	reference = NULL;
}

AtomStyleManager::AtomStyleManager(const ATOM_ELEMENT_REFERENCE& elementReference) {
	TakeOwnership(elementReference);
}

ATOM_ELEMENT_REFERENCE& AtomStyleManager::GetHandle() {
	return reference;
}

std::string AtomStyleManager::GetProperty(const std::string& propertyName) {
	if (propertyName.empty()) {
		return std::string();
	}

	char* value = atom_get_element_style(reference, propertyName.c_str());

	if (!value) {
		return std::string();
	}

	std::string valueString = value;

	free((void*)value);

	return valueString;
}

void AtomStyleManager::SetProperty(const std::string& propertyName, const std::string& value) {
	if (propertyName.empty()) {
		return;
	}

	if (value.empty()) {
		return;
	}

	atom_set_element_style(reference, propertyName.c_str(), value.c_str());
}

void AtomStyleManager::TakeOwnership(const ATOM_ELEMENT_REFERENCE& elementReference) {
	reference = elementReference;
}

void AtomStyleManager::ApplyProperty(const AtomElementStyleProperty& prop) {
	SetProperty(prop.key, prop.value);
}

void AtomStyleManager::ApplyProperties(const AtomElementStylePropertyList& props) {
	if (props.empty()) {
		return;
	}

	for (const AtomElementStyleProperty& prop : props) {
		ApplyProperty(prop);
	}
}

std::string AtomStyleManager::operator [](const std::string& propertyName) {
	return GetProperty(propertyName);
}

AtomStyleManager::operator bool() {
	return reference == NULL ? false : atom_element_exists(reference);
}

AtomElement AtomCreateStyleElement(const AtomCssStyleProperties& props) {
	if (props.empty()) {
		return AtomElement();
	}

	AtomStyleBuilder cssBuilder;

	cssBuilder.AddCssStyleProperties(props);

	std::string cssCode = "";

	cssBuilder.Build(&cssCode);

	AtomElement style("style");

	style.SetProperty("innerHTML", cssCode);

	AtomGetDocumentHeadElement() += style;

	return style;
}