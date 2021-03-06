/**
* Titanium for Windows
*
* Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License.
* Please see the LICENSE included with this distribution for details.
*/
#include "RequireHook.hpp"
#include "TitaniumWindows/Utility.hpp"
#include "Titanium/detail/TiImpl.hpp"
#include "HAL/HAL.hpp"
#include <collection.h>

//// NATIVE_MODULE_INCLUDES START
#include "Platform.Object.hpp"
#include "Windows.Foundation.AsyncActionCompletedHandler.hpp"
#include "Windows.Foundation.Collections.IPropertySet.hpp"
#include "Windows.Foundation.IAsyncAction.hpp"
#include "Windows.Foundation.IWwwFormUrlDecoderEntry.hpp"
#include "Windows.Foundation.Uri.hpp"
#include "Windows.Foundation.WwwFormUrlDecoder.hpp"
#include "Windows.UI.Colors.hpp"
#include "Windows.UI.Core.CoreCursor.hpp"
#include "Windows.UI.Core.CoreDispatcher.hpp"
#include "Windows.UI.Core.CoreWindow.hpp"
#include "Windows.UI.Core.DispatchedHandler.hpp"
#include "Windows.UI.Core.IdleDispatchedHandler.hpp"
#include "Windows.UI.Core.IdleDispatchedHandlerArgs.hpp"
#include "Windows.UI.Xaml.Controls.AppBar.hpp"
#include "Windows.UI.Xaml.Controls.Canvas.hpp"
#include "Windows.UI.Xaml.Controls.ContentControl.hpp"
#include "Windows.UI.Xaml.Controls.Control.hpp"
#include "Windows.UI.Xaml.Controls.ControlTemplate.hpp"
#include "Windows.UI.Xaml.Controls.DataTemplateSelector.hpp"
#include "Windows.UI.Xaml.Controls.Frame.hpp"
#include "Windows.UI.Xaml.Controls.Page.hpp"
#include "Windows.UI.Xaml.Controls.Panel.hpp"
#include "Windows.UI.Xaml.Controls.TextBlock.hpp"
#include "Windows.UI.Xaml.Controls.UIElementCollection.hpp"
#include "Windows.UI.Xaml.Controls.UserControl.hpp"
#include "Windows.UI.Xaml.CreateDefaultValueCallback.hpp"
#include "Windows.UI.Xaml.Data.Binding.hpp"
#include "Windows.UI.Xaml.Data.BindingBase.hpp"
#include "Windows.UI.Xaml.Data.BindingExpression.hpp"
#include "Windows.UI.Xaml.Data.BindingExpressionBase.hpp"
#include "Windows.UI.Xaml.Data.IValueConverter.hpp"
#include "Windows.UI.Xaml.Data.RelativeSource.hpp"
#include "Windows.UI.Xaml.DataTemplate.hpp"
#include "Windows.UI.Xaml.DependencyObject.hpp"
#include "Windows.UI.Xaml.DependencyProperty.hpp"
#include "Windows.UI.Xaml.DependencyPropertyChangedEventArgs.hpp"
#include "Windows.UI.Xaml.Documents.Inline.hpp"
#include "Windows.UI.Xaml.Documents.InlineCollection.hpp"
#include "Windows.UI.Xaml.Documents.TextElement.hpp"
#include "Windows.UI.Xaml.Documents.TextPointer.hpp"
#include "Windows.UI.Xaml.FrameworkElement.hpp"
#include "Windows.UI.Xaml.FrameworkTemplate.hpp"
#include "Windows.UI.Xaml.Input.Pointer.hpp"
#include "Windows.UI.Xaml.Media.Animation.NavigationTransitionInfo.hpp"
#include "Windows.UI.Xaml.Media.Animation.Transition.hpp"
#include "Windows.UI.Xaml.Media.Animation.TransitionCollection.hpp"
#include "Windows.UI.Xaml.Media.Brush.hpp"
#include "Windows.UI.Xaml.Media.CacheMode.hpp"
#include "Windows.UI.Xaml.Media.FontFamily.hpp"
#include "Windows.UI.Xaml.Media.GeneralTransform.hpp"
#include "Windows.UI.Xaml.Media.Geometry.hpp"
#include "Windows.UI.Xaml.Media.Projection.hpp"
#include "Windows.UI.Xaml.Media.RectangleGeometry.hpp"
#include "Windows.UI.Xaml.Media.SolidColorBrush.hpp"
#include "Windows.UI.Xaml.Media.Transform.hpp"
#include "Windows.UI.Xaml.Navigation.PageStackEntry.hpp"
#include "Windows.UI.Xaml.PropertyChangedCallback.hpp"
#include "Windows.UI.Xaml.PropertyMetadata.hpp"
#include "Windows.UI.Xaml.PropertyPath.hpp"
#include "Windows.UI.Xaml.ResourceDictionary.hpp"
#include "Windows.UI.Xaml.RoutedEvent.hpp"
#include "Windows.UI.Xaml.SetterBase.hpp"
#include "Windows.UI.Xaml.SetterBaseCollection.hpp"
#include "Windows.UI.Xaml.Style.hpp"
#include "Windows.UI.Xaml.TriggerBase.hpp"
#include "Windows.UI.Xaml.TriggerCollection.hpp"
#include "Windows.UI.Xaml.UIElement.hpp"
#include "Windows.UI.Xaml.Window.hpp"
//// NATIVE_MODULE_INCLUDES END

namespace TitaniumWindows_Native
{

	using namespace HAL;

	RequireHook::RequireHook()
		: native_module_loader__(std::make_shared<TitaniumWindows::WindowsNativeModuleLoader>())
	{
	}

	RequireHook::~RequireHook()
	{
		app__->TitaniumModulePreload -= preload__;
		app__->TitaniumModuleRequire -= require__;
		app__->TitaniumModuleNames   -= names__;
	}

	void RequireHook::Register(TitaniumWindows::Application^ app)
	{
		app__ = app;
		preload__ = app__->TitaniumModulePreload += ref new TitaniumWindows::TitaniumModulePreloadHandler(this, &TitaniumWindows_Native::RequireHook::OnTitaniumModulePreload);
		require__ = app__->TitaniumModuleRequire += ref new TitaniumWindows::TitaniumModuleRequireHandler(this, &TitaniumWindows_Native::RequireHook::OnTitaniumModuleRequire);
		names__   = app__->TitaniumModuleNames   += ref new TitaniumWindows::TitaniumModuleNamesHandler(this, &TitaniumWindows_Native::RequireHook::OnTitaniumModuleNames);

		app__->SaveRequireHook(this);
	}

	// This should return pointer to JSObject (key-value) which consists of module name & preloaded JSObject
	std::intptr_t RequireHook::OnTitaniumModulePreload(std::intptr_t js_context_ref)
	{
		const auto js_context = JSContext(reinterpret_cast<JSContextRef>(js_context_ref));

		auto js_preloaded_module_map = js_context.CreateObject();


		//// TODO: native module initialization 
		//// js_preloaded_module_map.SetProperty("com.example.test", js_context.CreateObject(JSExport<Com::Example::Test>::Class()));

		//// INITIALLIZE PRELOADED NATIVE MODULE START
		//// INITIALLIZE PRELOADED NATIVE MODULE END

		return reinterpret_cast<std::intptr_t>(static_cast<JSValueRef>(js_preloaded_module_map));
	}

	// This will be called when native module with supported name is not loaded. Return pointer to JSValue as the result of require.
	std::intptr_t RequireHook::OnTitaniumModuleRequire(std::intptr_t js_context_ref, Platform::String^ moduleId)
	{
		const auto js_context = JSContext(reinterpret_cast<JSContextRef>(js_context_ref));

		auto value = native_module_loader__->registerNativeModule(js_context, TitaniumWindows::Utility::ConvertString(moduleId));

		return reinterpret_cast<std::intptr_t>(static_cast<JSValueRef>(value));
	}

	// This should return collections of supported name module names such as Windows.Xaml.Controls.Button etc.
	Windows::Foundation::Collections::IVector<Platform::String^>^ RequireHook::OnTitaniumModuleNames(int js_context_ref)
	{
		auto names = ref new ::Platform::Collections::Vector<::Platform::String^>();


		//// TODO: Insert supported module names here
		//// names->Append("com.example.test");
		//// names->Append("Windows.UI.Xaml.Controls.Button");
		//// names->Append("Windows.UI.Xaml.Controls.ListView");

		//// INSERT SUPPORTED NATIVE MODULE NAMES START
		names->Append("Platform.Object");
		names->Append("Windows.Foundation.AsyncActionCompletedHandler");
		names->Append("Windows.Foundation.Collections.IPropertySet");
		names->Append("Windows.Foundation.IAsyncAction");
		names->Append("Windows.Foundation.IWwwFormUrlDecoderEntry");
		names->Append("Windows.Foundation.Uri");
		names->Append("Windows.Foundation.WwwFormUrlDecoder");
		names->Append("Windows.UI.Colors");
		names->Append("Windows.UI.Core.CoreCursor");
		names->Append("Windows.UI.Core.CoreDispatcher");
		names->Append("Windows.UI.Core.CoreWindow");
		names->Append("Windows.UI.Core.DispatchedHandler");
		names->Append("Windows.UI.Core.IdleDispatchedHandler");
		names->Append("Windows.UI.Core.IdleDispatchedHandlerArgs");
		names->Append("Windows.UI.Xaml.Controls.AppBar");
		names->Append("Windows.UI.Xaml.Controls.Canvas");
		names->Append("Windows.UI.Xaml.Controls.ContentControl");
		names->Append("Windows.UI.Xaml.Controls.Control");
		names->Append("Windows.UI.Xaml.Controls.ControlTemplate");
		names->Append("Windows.UI.Xaml.Controls.DataTemplateSelector");
		names->Append("Windows.UI.Xaml.Controls.Frame");
		names->Append("Windows.UI.Xaml.Controls.Page");
		names->Append("Windows.UI.Xaml.Controls.Panel");
		names->Append("Windows.UI.Xaml.Controls.TextBlock");
		names->Append("Windows.UI.Xaml.Controls.UIElementCollection");
		names->Append("Windows.UI.Xaml.Controls.UserControl");
		names->Append("Windows.UI.Xaml.CreateDefaultValueCallback");
		names->Append("Windows.UI.Xaml.Data.Binding");
		names->Append("Windows.UI.Xaml.Data.BindingBase");
		names->Append("Windows.UI.Xaml.Data.BindingExpression");
		names->Append("Windows.UI.Xaml.Data.BindingExpressionBase");
		names->Append("Windows.UI.Xaml.Data.IValueConverter");
		names->Append("Windows.UI.Xaml.Data.RelativeSource");
		names->Append("Windows.UI.Xaml.DataTemplate");
		names->Append("Windows.UI.Xaml.DependencyObject");
		names->Append("Windows.UI.Xaml.DependencyProperty");
		names->Append("Windows.UI.Xaml.DependencyPropertyChangedEventArgs");
		names->Append("Windows.UI.Xaml.Documents.Inline");
		names->Append("Windows.UI.Xaml.Documents.InlineCollection");
		names->Append("Windows.UI.Xaml.Documents.TextElement");
		names->Append("Windows.UI.Xaml.Documents.TextPointer");
		names->Append("Windows.UI.Xaml.FrameworkElement");
		names->Append("Windows.UI.Xaml.FrameworkTemplate");
		names->Append("Windows.UI.Xaml.Input.Pointer");
		names->Append("Windows.UI.Xaml.Media.Animation.NavigationTransitionInfo");
		names->Append("Windows.UI.Xaml.Media.Animation.Transition");
		names->Append("Windows.UI.Xaml.Media.Animation.TransitionCollection");
		names->Append("Windows.UI.Xaml.Media.Brush");
		names->Append("Windows.UI.Xaml.Media.CacheMode");
		names->Append("Windows.UI.Xaml.Media.FontFamily");
		names->Append("Windows.UI.Xaml.Media.GeneralTransform");
		names->Append("Windows.UI.Xaml.Media.Geometry");
		names->Append("Windows.UI.Xaml.Media.Projection");
		names->Append("Windows.UI.Xaml.Media.RectangleGeometry");
		names->Append("Windows.UI.Xaml.Media.SolidColorBrush");
		names->Append("Windows.UI.Xaml.Media.Transform");
		names->Append("Windows.UI.Xaml.Navigation.PageStackEntry");
		names->Append("Windows.UI.Xaml.PropertyChangedCallback");
		names->Append("Windows.UI.Xaml.PropertyMetadata");
		names->Append("Windows.UI.Xaml.PropertyPath");
		names->Append("Windows.UI.Xaml.ResourceDictionary");
		names->Append("Windows.UI.Xaml.RoutedEvent");
		names->Append("Windows.UI.Xaml.SetterBase");
		names->Append("Windows.UI.Xaml.SetterBaseCollection");
		names->Append("Windows.UI.Xaml.Style");
		names->Append("Windows.UI.Xaml.TriggerBase");
		names->Append("Windows.UI.Xaml.TriggerCollection");
		names->Append("Windows.UI.Xaml.UIElement");
		names->Append("Windows.UI.Xaml.Window");
		//// INSERT SUPPORTED NATIVE MODULE NAMES END

		return names;
	}

} // namespace TitaniumWindows