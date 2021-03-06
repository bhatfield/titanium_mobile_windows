/**
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/Locale.hpp"
#include "Titanium/detail/TiImpl.hpp"

namespace Titanium
{
	Locale::Locale(const JSContext& js_context) TITANIUM_NOEXCEPT
		: Module(js_context)
		, currentLanguage__("en")
		, currentCountry__("US")
		, currentLocale__("en-US")
	{
		TITANIUM_LOG_DEBUG("Locale:: ctor ", this);
	}

	TITANIUM_PROPERTY_READ(Locale, std::string, currentCountry)
	TITANIUM_PROPERTY_READ(Locale, std::string, currentLanguage)
	TITANIUM_PROPERTY_READ(Locale, std::string, currentLocale)

	std::string Locale::formatTelephoneNumber(const std::string& number) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("Locale::formatTelephoneNumber: Unimplemented");
		return number;
	}

	std::string Locale::getCurrencyCode(const std::string& locale) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("Locale::getCurrencyCode: Unimplemented");
		return "";
	}

	std::string Locale::getCurrencySymbol(const std::string& currencyCode) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("Locale::getCurrencySymbol: Unimplemented");
		return "";
	}

	std::string Locale::getLocaleCurrencySymbol(const std::string& locale) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("Locale::getLocaleCurrencySymbol: Unimplemented");
		return "";
	}

	std::string Locale::getString(const std::string& key, const std::string& hint) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("Locale::getString: Unimplemented");
		return hint.empty() ? key : hint;
	}

	void Locale::JSExportInitialize() 
	{
		JSExport<Locale>::SetClassVersion(1);
		JSExport<Locale>::SetParent(JSExport<Module>::Class());

		TITANIUM_ADD_PROPERTY_READONLY(Locale, currentCountry);
		TITANIUM_ADD_PROPERTY_READONLY(Locale, currentLanguage);
		TITANIUM_ADD_PROPERTY_READONLY(Locale, currentLocale);

		TITANIUM_ADD_FUNCTION(Locale, formatTelephoneNumber);
		TITANIUM_ADD_FUNCTION(Locale, getCurrencyCode);
		TITANIUM_ADD_FUNCTION(Locale, getCurrencySymbol);
		TITANIUM_ADD_FUNCTION(Locale, getLocaleCurrencySymbol);
		TITANIUM_ADD_FUNCTION(Locale, getCurrentCountry);
		TITANIUM_ADD_FUNCTION(Locale, getCurrentLanguage);
		TITANIUM_ADD_FUNCTION(Locale, getCurrentLocale);
		TITANIUM_ADD_FUNCTION(Locale, getString);
	}

	JSObject Locale::GetStaticObject(const JSContext& js_context) TITANIUM_NOEXCEPT
	{
		JSValue Titanium_property = js_context.get_global_object().GetProperty("Titanium");
		TITANIUM_ASSERT(Titanium_property.IsObject());  // precondition
		JSObject Titanium = static_cast<JSObject>(Titanium_property);

		JSValue Object_property = Titanium.GetProperty("Locale");
		TITANIUM_ASSERT(Object_property.IsObject());  // precondition
		return static_cast<JSObject>(Object_property);
	}

	TITANIUM_PROPERTY_GETTER(Locale, currentCountry)
	{
		return get_context().CreateString(get_currentCountry());
	}

	TITANIUM_PROPERTY_GETTER(Locale, currentLanguage)
	{
		return get_context().CreateString(get_currentLanguage());
	}

	TITANIUM_PROPERTY_GETTER(Locale, currentLocale)
	{
		return get_context().CreateString(get_currentLocale());
	}

	TITANIUM_FUNCTION(Locale, formatTelephoneNumber)
	{
		ENSURE_STRING_AT_INDEX(number, 0);
		const auto ctx = this_object.get_context();
		return this_object.get_context().CreateString(GetStaticObject(ctx).GetPrivate<Locale>()->formatTelephoneNumber(number));
	}

	TITANIUM_FUNCTION(Locale, getCurrencyCode)
	{
		ENSURE_STRING_AT_INDEX(locale, 0);
		const auto ctx = this_object.get_context();
		return this_object.get_context().CreateString(GetStaticObject(ctx).GetPrivate<Locale>()->getCurrencyCode(locale));
	}

	TITANIUM_FUNCTION(Locale, getCurrencySymbol)
	{
		ENSURE_STRING_AT_INDEX(code, 0);
		const auto ctx = this_object.get_context();
		return this_object.get_context().CreateString(GetStaticObject(ctx).GetPrivate<Locale>()->getCurrencySymbol(code));
	}

	TITANIUM_FUNCTION(Locale, getLocaleCurrencySymbol)
	{
		ENSURE_STRING_AT_INDEX(locale, 0);
		const auto ctx = this_object.get_context();
		return ctx.CreateString(GetStaticObject(ctx).GetPrivate<Locale>()->getLocaleCurrencySymbol(locale));
	}

	TITANIUM_FUNCTION(Locale, getString)
	{
		ENSURE_STRING_AT_INDEX(key, 0);
		ENSURE_OPTIONAL_STRING_AT_INDEX(hint, 1, "");
		const auto ctx = this_object.get_context();
		return ctx.CreateString(GetStaticObject(ctx).GetPrivate<Locale>()->getString(key, hint));
	}

	TITANIUM_FUNCTION_AS_GETTER(Locale, getCurrentCountry, currentCountry)
	TITANIUM_FUNCTION_AS_GETTER(Locale, getCurrentLanguage, currentLanguage)
	TITANIUM_FUNCTION_AS_GETTER(Locale, getCurrentLocale, currentLocale)

}  // namespace Titanium
