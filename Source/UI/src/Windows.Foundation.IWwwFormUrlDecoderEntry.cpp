/**
 * Windows Native Wrapper for Windows.Foundation.IWwwFormUrlDecoderEntry
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.Foundation.IWwwFormUrlDecoderEntry.hpp"

namespace Titanium
{
	namespace Windows
	{
		namespace Foundation
		{

		IWwwFormUrlDecoderEntry::IWwwFormUrlDecoderEntry(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::Module(js_context)
		{
		}

		void IWwwFormUrlDecoderEntry::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
		}

		::Windows::Foundation::IWwwFormUrlDecoderEntry^ IWwwFormUrlDecoderEntry::unwrapWindows_Foundation_IWwwFormUrlDecoderEntry() const
		{
			return dynamic_cast<::Windows::Foundation::IWwwFormUrlDecoderEntry^>(wrapped__);
		}

		::Windows::Foundation::IWwwFormUrlDecoderEntry^ IWwwFormUrlDecoderEntry::unwrap() const
		{
			return unwrapWindows_Foundation_IWwwFormUrlDecoderEntry();
		}

		void IWwwFormUrlDecoderEntry::wrap(::Windows::Foundation::IWwwFormUrlDecoderEntry^ object)
		{
			wrapped__ = object;
		}

		void IWwwFormUrlDecoderEntry::JSExportInitialize()
		{
			JSExport<IWwwFormUrlDecoderEntry>::SetClassVersion(1);
			JSExport<IWwwFormUrlDecoderEntry>::SetParent(JSExport<Titanium::Module>::Class());

			TITANIUM_ADD_PROPERTY_READONLY(IWwwFormUrlDecoderEntry, Name);
			TITANIUM_ADD_PROPERTY_READONLY(IWwwFormUrlDecoderEntry, Value);
		}

		TITANIUM_PROPERTY_GETTER(IWwwFormUrlDecoderEntry, Name)
		{
			auto value = unwrap()->Name;
			auto context = get_context();
 			auto result = context.CreateString(TitaniumWindows::Utility::ConvertUTF8String(value));

			return result;
		}

		TITANIUM_PROPERTY_GETTER(IWwwFormUrlDecoderEntry, Value)
		{
			auto value = unwrap()->Value;
			auto context = get_context();
 			auto result = context.CreateString(TitaniumWindows::Utility::ConvertUTF8String(value));

			return result;
		}

		} // namespace Foundation
	} // namespace Windows
} // namespace Titanium
