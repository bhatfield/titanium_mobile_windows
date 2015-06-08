/**
 * Windows Native Wrapper for Windows.UI.Xaml.Media.Animation.TransitionCollection
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Xaml.Media.Animation.Transition.hpp"
#include "Windows.UI.Xaml.Media.Animation.TransitionCollection.hpp"

namespace Titanium
{
	namespace Windows
	{
		namespace UI
		{
			namespace Xaml
			{
				namespace Media
				{
					namespace Animation
					{

		TransitionCollection::TransitionCollection(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::Platform::Object(js_context)
		{
			TITANIUM_LOG_DEBUG("TransitionCollection::ctor");
		}

		void TransitionCollection::postCallAsConstructor(const JSContext& context, const std::vector<JSValue>& arguments)
		{
			TITANIUM_LOG_DEBUG("TransitionCollection::postCallAsConstructor ", this);
			if (arguments.size() == 0) {

				wrapped__ = ref new ::Windows::UI::Xaml::Media::Animation::TransitionCollection();
			}

		}

		::Windows::UI::Xaml::Media::Animation::TransitionCollection^ TransitionCollection::unwrapWindows_UI_Xaml_Media_Animation_TransitionCollection() const
		{
			return dynamic_cast<::Windows::UI::Xaml::Media::Animation::TransitionCollection^>(wrapped__);
		}

		::Windows::UI::Xaml::Media::Animation::TransitionCollection^ TransitionCollection::unwrap() const
		{
			return unwrapWindows_UI_Xaml_Media_Animation_TransitionCollection();
		}

		void TransitionCollection::wrap(::Windows::UI::Xaml::Media::Animation::TransitionCollection^ object)
		{
			wrapped__ = object;
		}

		void TransitionCollection::JSExportInitialize()
		{
			JSExport<TransitionCollection>::SetClassVersion(1);
			JSExport<TransitionCollection>::SetParent(JSExport<Titanium::Platform::Object>::Class());

			TITANIUM_ADD_PROPERTY_READONLY(TransitionCollection, Size);
			TITANIUM_ADD_FUNCTION(TransitionCollection, GetAt);
			TITANIUM_ADD_FUNCTION(TransitionCollection, GetView);
			TITANIUM_ADD_FUNCTION(TransitionCollection, IndexOf);
			TITANIUM_ADD_FUNCTION(TransitionCollection, SetAt);
			TITANIUM_ADD_FUNCTION(TransitionCollection, InsertAt);
			TITANIUM_ADD_FUNCTION(TransitionCollection, RemoveAt);
			TITANIUM_ADD_FUNCTION(TransitionCollection, Append);
			TITANIUM_ADD_FUNCTION(TransitionCollection, RemoveAtEnd);
			TITANIUM_ADD_FUNCTION(TransitionCollection, Clear);
			TITANIUM_ADD_FUNCTION(TransitionCollection, GetMany);
			TITANIUM_ADD_FUNCTION(TransitionCollection, ReplaceAll);
			TITANIUM_ADD_FUNCTION(TransitionCollection, First);
		}

		TITANIUM_PROPERTY_GETTER(TransitionCollection, Size)
		{
			auto value = unwrap()->Size;
			auto context = get_context();


		}

		TITANIUM_FUNCTION(TransitionCollection, GetAt)
		{
			auto context = get_context();
			if (arguments.size() == 1) {
				auto _0 = arguments.at(0); 
			auto index = static_cast<uint32_t>(_0);

				auto method_result = unwrap()->GetAt(index);
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::Media::Animation::Transition>();
			result_wrapper->wrap(method_result);

			}

			// Catch-all if no arg count matches!
			TITANIUM_LOG_DEBUG("No method signature matched TransitionCollection::GetAt with # of args: ", arguments.size());
			return context.CreateUndefined(); 
		}

		TITANIUM_FUNCTION(TransitionCollection, GetView)
		{
			auto context = get_context();
			if (arguments.size() == 0) {
				auto method_result = unwrap()->GetView();
			for (uint32_t i = 0; i < method_result->Size; ++i) {
				
			auto method_result_tmp_wrapper = method_result_tmp.GetPrivate<Windows::UI::Xaml::Media::Animation::Transition>();
			method_result_tmp_wrapper->wrap(method_result->GetAt(i));

			}

			auto result = get_context().CreateArray(result_vector);

			}

			// Catch-all if no arg count matches!
			TITANIUM_LOG_DEBUG("No method signature matched TransitionCollection::GetView with # of args: ", arguments.size());
			return context.CreateUndefined(); 
		}

		TITANIUM_FUNCTION(TransitionCollection, IndexOf)
		{
			auto context = get_context();
			if (arguments.size() == 2) {
				auto _0 = arguments.at(0);
			auto object_value = static_cast<JSObject>(_0);
 
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper_value->unwrapWindows_UI_Xaml_Media_Animation_Transition();

				auto _1 = arguments.at(1); 
			auto index = static_cast<uint32_t>(_1);

				auto method_result = unwrap()->IndexOf(value, &index);


				_1 = out_1;
				return result;
			}

			// Catch-all if no arg count matches!
			TITANIUM_LOG_DEBUG("No method signature matched TransitionCollection::IndexOf with # of args: ", arguments.size());
			return context.CreateUndefined(); 
		}

		TITANIUM_FUNCTION(TransitionCollection, SetAt)
		{
			auto context = get_context();
			if (arguments.size() == 2) {
				auto _0 = arguments.at(0); 
			auto index = static_cast<uint32_t>(_0);

				auto _1 = arguments.at(1);
			auto object_value = static_cast<JSObject>(_1);
 
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper_value->unwrapWindows_UI_Xaml_Media_Animation_Transition();

				unwrap()->SetAt(index, value);
				return context.CreateUndefined(); 
			}

			// Catch-all if no arg count matches!
			TITANIUM_LOG_DEBUG("No method signature matched TransitionCollection::SetAt with # of args: ", arguments.size());
			return context.CreateUndefined(); 
		}

		TITANIUM_FUNCTION(TransitionCollection, InsertAt)
		{
			auto context = get_context();
			if (arguments.size() == 2) {
				auto _0 = arguments.at(0); 
			auto index = static_cast<uint32_t>(_0);

				auto _1 = arguments.at(1);
			auto object_value = static_cast<JSObject>(_1);
 
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper_value->unwrapWindows_UI_Xaml_Media_Animation_Transition();

				unwrap()->InsertAt(index, value);
				return context.CreateUndefined(); 
			}

			// Catch-all if no arg count matches!
			TITANIUM_LOG_DEBUG("No method signature matched TransitionCollection::InsertAt with # of args: ", arguments.size());
			return context.CreateUndefined(); 
		}

		TITANIUM_FUNCTION(TransitionCollection, RemoveAt)
		{
			auto context = get_context();
			if (arguments.size() == 1) {
				auto _0 = arguments.at(0); 
			auto index = static_cast<uint32_t>(_0);

				unwrap()->RemoveAt(index);
				return context.CreateUndefined(); 
			}

			// Catch-all if no arg count matches!
			TITANIUM_LOG_DEBUG("No method signature matched TransitionCollection::RemoveAt with # of args: ", arguments.size());
			return context.CreateUndefined(); 
		}

		TITANIUM_FUNCTION(TransitionCollection, Append)
		{
			auto context = get_context();
			if (arguments.size() == 1) {
				auto _0 = arguments.at(0);
			auto object_value = static_cast<JSObject>(_0);
 
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper_value->unwrapWindows_UI_Xaml_Media_Animation_Transition();

				unwrap()->Append(value);
				return context.CreateUndefined(); 
			}

			// Catch-all if no arg count matches!
			TITANIUM_LOG_DEBUG("No method signature matched TransitionCollection::Append with # of args: ", arguments.size());
			return context.CreateUndefined(); 
		}

		TITANIUM_FUNCTION(TransitionCollection, RemoveAtEnd)
		{
			auto context = get_context();
			if (arguments.size() == 0) {
				unwrap()->RemoveAtEnd();
				return context.CreateUndefined(); 
			}

			// Catch-all if no arg count matches!
			TITANIUM_LOG_DEBUG("No method signature matched TransitionCollection::RemoveAtEnd with # of args: ", arguments.size());
			return context.CreateUndefined(); 
		}

		TITANIUM_FUNCTION(TransitionCollection, Clear)
		{
			auto context = get_context();
			if (arguments.size() == 0) {
				unwrap()->Clear();
				return context.CreateUndefined(); 
			}

			// Catch-all if no arg count matches!
			TITANIUM_LOG_DEBUG("No method signature matched TransitionCollection::Clear with # of args: ", arguments.size());
			return context.CreateUndefined(); 
		}

		TITANIUM_FUNCTION(TransitionCollection, GetMany)
		{
			auto context = get_context();
			if (arguments.size() == 2) {
				auto _0 = arguments.at(0); 
			auto startIndex = static_cast<uint32_t>(_0);

				auto _1 = arguments.at(1);
			auto object_items = static_cast<JSObject>(_1);

			const auto array_items = static_cast<JSArray>(object_items);
			auto items_items = array_items.GetPrivateItems<Windows::UI::Xaml::Media::Animation::Transition>(); // std::vector<std::shared_ptr<Windows::UI::Xaml::Media::Animation::Transition>
			auto items = ref new ::Platform::Array<::Windows::UI::Xaml::Media::Animation::Transition^>(items_items.size());
			for (size_t i = 0; i < items_items.size(); ++i) {
				items[i] = items_items.at(i)->unwrapWindows_UI_Xaml_Media_Animation_Transition();
			}

				auto method_result = unwrap()->GetMany(startIndex, items);

			for (size_t i = 0; i < items->Length; ++i) {
				
			auto items_tmp_wrapper = items_tmp.GetPrivate<Windows::UI::Xaml::Media::Animation::Transition>();
			items_tmp_wrapper->wrap(items[i]);
		
			}

			auto out_1 = get_context().CreateArray(out_1_vector);

				_1 = out_1;
				return result;
			}

			// Catch-all if no arg count matches!
			TITANIUM_LOG_DEBUG("No method signature matched TransitionCollection::GetMany with # of args: ", arguments.size());
			return context.CreateUndefined(); 
		}

		TITANIUM_FUNCTION(TransitionCollection, ReplaceAll)
		{
			auto context = get_context();
			if (arguments.size() == 1) {
				auto _0 = arguments.at(0);
			auto object_items = static_cast<JSObject>(_0);

			const auto array_items = static_cast<JSArray>(object_items);
			auto items_items = array_items.GetPrivateItems<Windows::UI::Xaml::Media::Animation::Transition>(); // std::vector<std::shared_ptr<Windows::UI::Xaml::Media::Animation::Transition>
			auto items = ref new ::Platform::Array<::Windows::UI::Xaml::Media::Animation::Transition^>(items_items.size());
			for (size_t i = 0; i < items_items.size(); ++i) {
				items[i] = items_items.at(i)->unwrapWindows_UI_Xaml_Media_Animation_Transition();
			}

				unwrap()->ReplaceAll(items);
				return context.CreateUndefined(); 
			}

			// Catch-all if no arg count matches!
			TITANIUM_LOG_DEBUG("No method signature matched TransitionCollection::ReplaceAll with # of args: ", arguments.size());
			return context.CreateUndefined(); 
		}

		TITANIUM_FUNCTION(TransitionCollection, First)
		{
			auto context = get_context();
			if (arguments.size() == 0) {
				auto method_result = unwrap()->First();
			while (method_result->HasCurrent) {
				
			auto method_result_tmp_wrapper = method_result_tmp.GetPrivate<Windows::UI::Xaml::Media::Animation::Transition>();
			method_result_tmp_wrapper->wrap(method_result->Current);

        		method_result->MoveNext();
			}

			auto result = get_context().CreateArray(result_vector);

			}

			// Catch-all if no arg count matches!
			TITANIUM_LOG_DEBUG("No method signature matched TransitionCollection::First with # of args: ", arguments.size());
			return context.CreateUndefined(); 
		}

					} // namespace Animation
				} // namespace Media
			} // namespace Xaml
		} // namespace UI
	} // namespace Windows
} // namespace Titanium