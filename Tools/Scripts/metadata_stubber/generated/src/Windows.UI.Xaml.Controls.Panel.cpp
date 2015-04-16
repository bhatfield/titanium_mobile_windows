/**
 * Windows Native Wrapper for Windows.UI.Xaml.Controls.Panel
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Xaml.Controls.Panel.hpp"
 // TODO Include the headers for all the native types we use in here! We'll have to go through type of every method arg, return type, type of every property

namespace Windows
{
	namespace UI
	{
		namespace Xaml
		{
			namespace Controls
			{

		Panel::Panel(const JSContext& js_context, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT
			: Windows::UI::Xaml::FrameworkElement(js_context, arguments)
		{
		}

		void Panel::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
			wrapped__ = ref new Windows::UI::Xaml::Controls::Panel();
		}

		Windows::UI::Xaml::Controls::Panel^ Panel::unwrapWindows_UI_Xaml_Controls_Panel()
		{
			return dynamic_cast<Windows::UI::Xaml::Controls::Panel^>(wrapped__); // downcast/sidecast. I think dynamic_cast is right here...
		}

		void Panel::wrap(Windows::UI::Xaml::Controls::Panel^ object)
		{
			wrapped__ = object; // upcast/assign, should be ok without casting
		}

		void Panel::JSExportInitialize()
		{
			JSExport<Panel>::SetClassVersion(1);
			JSExport<Panel>::SetParent(JSExport<Windows::UI::Xaml::FrameworkElement>::Class());

			TITANIUM_ADD_PROPERTY(Panel, ChildrenTransitions);
			TITANIUM_ADD_PROPERTY(Panel, Background);
			TITANIUM_ADD_PROPERTY_READONLY(Panel, Children);
			TITANIUM_ADD_PROPERTY_READONLY(Panel, IsItemsHost);
			TITANIUM_ADD_PROPERTY_READONLY(Panel, BackgroundProperty);
			TITANIUM_ADD_PROPERTY_READONLY(Panel, ChildrenTransitionsProperty);
			TITANIUM_ADD_PROPERTY_READONLY(Panel, IsItemsHostProperty);
		}

		TITANIUM_PROPERTY_SETTER(Panel, ChildrenTransitions)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object = static_cast<JSObject>(argument);
			auto wrapper = object.GetPrivate<Windows::UI::Xaml::Media::Animation::TransitionCollection>();
			// FIXME What if the type we want here is some parent class of the actual wrapper class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper->unwrapWindows_UI_Xaml_Media_Animation_TransitionCollection();
			wrapped__->ChildrenTransitions = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Panel, ChildrenTransitions)
		{
			auto value = wrapped__->ChildrenTransitions;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::Media::Animation::TransitionCollection>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::Media::Animation::TransitionCollection>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_SETTER(Panel, Background)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object = static_cast<JSObject>(argument);
			auto wrapper = object.GetPrivate<Windows::UI::Xaml::Media::Brush>();
			// FIXME What if the type we want here is some parent class of the actual wrapper class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper->unwrapWindows_UI_Xaml_Media_Brush();
			wrapped__->Background = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Panel, Background)
		{
			auto value = wrapped__->Background;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::Media::Brush>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::Media::Brush>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(Panel, Children)
		{
			auto value = wrapped__->Children;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::Controls::UIElementCollection>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::Controls::UIElementCollection>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(Panel, IsItemsHost)
		{
			auto value = wrapped__->IsItemsHost;
			auto context = get_context();
 			return context.CreateBoolean(value); 
		}

		TITANIUM_PROPERTY_GETTER(Panel, BackgroundProperty)
		{
			auto value = wrapped__->BackgroundProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(Panel, ChildrenTransitionsProperty)
		{
			auto value = wrapped__->ChildrenTransitionsProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(Panel, IsItemsHostProperty)
		{
			auto value = wrapped__->IsItemsHostProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

			} // namespace Controls
		} // namespace Xaml
	} // namespace UI
} // namespace Windows
