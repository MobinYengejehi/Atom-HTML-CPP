#pragma once

#ifndef ATOM_STYLE_MANAGER
#define ATOM_STYLE_MANAGER

#include "AtomJSDefinitions.h"

#include <string>
#include <vector>
#include <variant>

class AtomElement;

struct AtomElementStyleProperty {
	std::string key;
	std::string value;

	bool selectKey;

	AtomElementStyleProperty(const std::string& k, const bool& select);
	AtomElementStyleProperty(const std::string& k, const std::string& v, const bool& select);
	AtomElementStyleProperty(const std::string& k, const std::string& v);

	AtomElementStyleProperty& operator=(const std::string& v);
	AtomElementStyleProperty& operator=(const double& v);
};

typedef std::vector<AtomElementStyleProperty> AtomElementStylePropertyList;

struct AtomElementStyleQuery {
	std::string                  query;
	AtomElementStylePropertyList options;

	AtomElementStyleQuery(const std::string& q);

	AtomElementStyleQuery& operator=(const AtomElementStylePropertyList& list);
};

typedef std::vector<AtomElementStyleQuery> AtomElementStyleQueryList;

struct AtomElementStyleRule {
	std::string               rule;
	AtomElementStyleQueryList queryList;

	AtomElementStyleRule(const std::string& r);

	AtomElementStyleRule& operator=(const AtomElementStyleQueryList& qlist);
};

typedef std::vector<AtomElementStyleRule> AtomElementStyleRuleList;

typedef std::variant<AtomElementStyleRule, AtomElementStyleQuery> AtomCssStyleProperty;
typedef std::vector<AtomCssStyleProperty> AtomCssStyleProperties;

class AtomStyleBuilder {
public:
	AtomStyleBuilder() = default;
	~AtomStyleBuilder() = default;

	void AddRule(const AtomElementStyleRule& rule);
	void AddRules(const AtomElementStyleRuleList& ruleList);

	void AddCssStyleProperty(const AtomCssStyleProperty& prop);
	void AddCssStyleProperties(const AtomCssStyleProperties& props);

	AtomElementStyleRuleList& GetRules();

	void Build(std::string* content);

private:
	AtomElementStyleRuleList rules;
};

class AtomStyleManager {
public:
	AtomStyleManager();
	AtomStyleManager(const ATOM_ELEMENT_REFERENCE& elementReference);
	~AtomStyleManager() = default;

	ATOM_ELEMENT_REFERENCE& GetHandle();
	std::string             GetProperty(const std::string& propertyName);

	void SetProperty(const std::string& propertyName, const std::string& value);

	void TakeOwnership(const ATOM_ELEMENT_REFERENCE& elementReference);

	void ApplyProperty(const AtomElementStyleProperty& prop);
	void ApplyProperties(const AtomElementStylePropertyList& props);

	std::string operator[](const std::string& propertyName);

	operator bool();

private:
	ATOM_ELEMENT_REFERENCE reference;
};

AtomElement AtomCreateStyleElement(const AtomCssStyleProperties& props);

#endif