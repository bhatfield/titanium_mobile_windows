/**
 * Windows Native Wrapper for Windows.UI.Xaml.Media.Transform
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Xaml.Media.Transform.hpp"
 // TODO Include the headers for all the native types we use in here! We'll have to go through type of every method arg, return type, type of every property

namespace Windows
{
	namespace UI
	{
		namespace Xaml
		{
			namespace Media
			{

		Transform::Transform(const JSContext& js_context, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT
			: Windows::UI::Xaml::Media::GeneralTransform(js_context, arguments)
		{
		}

		void Transform::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
			wrapped__ = ref new Windows::UI::Xaml::Media::Transform();
		}

		Windows::UI::Xaml::Media::Transform^ Transform::unwrapWindows_UI_Xaml_Media_Transform()
		{
			return dynamic_cast<Windows::UI::Xaml::Media::Transform^>(wrapped__); // downcast/sidecast. I think dynamic_cast is right here...
		}

		void Transform::wrap(Windows::UI::Xaml::Media::Transform^ object)
		{
			wrapped__ = object; // upcast/assign, should be ok without casting
		}

		void Transform::JSExportInitialize()
		{
			JSExport<Transform>::SetClassVersion(1);
			JSExport<Transform>::SetParent(JSExport<Windows::UI::Xaml::Media::GeneralTransform>::Class());

		}

			} // namespace Media
		} // namespace Xaml
	} // namespace UI
} // namespace Windows
