<%
// This expects:
// to_assign: the name of the native variable to assign the resulting object to
// type: the name of the type we're converting
// metadata: pointer to the full metadata
// argument_name: the name of the JS variable we're converting from

//	It's a class. Let's wrap the native item in our native wrapper for the defined type
type = type.trim();
if (type.indexOf('class ') == 0) {
	type = type.substring(6);
}

// TODO How do we handle other possible templated types like the Async stuff?

if (type.indexOf('[]') == type.length - 2) { // 'primitive' array
	// Strip off the [], then proceed knowing it's an array...
	type = type.substring(0, type.length - 2);
-%>
			TITANIUM_ASSERT_AND_THROW(<%= argument_name %>.IsObject(), "Expected Object");
			auto object_<%= argument_name %> = static_cast<JSObject>(<%= argument_name %>);
			TITANIUM_ASSERT(object_<%= argument_name %>.IsArray());
			const auto array_<%= argument_name %> = static_cast<JSArray>(object_<%= argument_name %>);
			auto items_<%= argument_name %> = array_<%= argument_name %>.GetPrivateItems<<%= type.replace(/\./g, '::') %>>(); // std::vector<std::shared_ptr<<%= type.replace(/\./g, '::') %>>
			auto <%= to_assign %> = ref new ::Platform::Array<::<%= type.replace(/\./g, '::') %>^>(items_<%= argument_name %>.size());
			for (size_t i = 0; i < items_<%= argument_name %>.size(); ++i) {
				items[i] = items_<%= argument_name %>.at(i)->unwrap<%= type.replace(/\./g, '_') %>();
			}
<%
} else  if (type.indexOf('.IIterator') != -1) { // IIterator
	// Pull out the internal type!
	type = type.substring(type.indexOf('`1<') + 3, type.length - 1);
	// Make a vector and then return an iterator over it!
	type = 'Windows.Foundation.Collections.IVector`1<' + type + '>';
-%>
			<%- include('js_to_native_class.cpp', {type: type, metadata: metadata, to_assign: to_assign + "_vector", argument_name: argument_name }) -%>
			auto <%= to_assign %> = <%= to_assign %>_vector->First();
<%
} else if (type.indexOf('.IVectorView') != -1) { // IVectorView
	type = type.substring(type.indexOf('`1<') + 3, type.length - 1);
	// Treat as a Vector, then just return view of it!
	type = 'Windows.Foundation.Collections.IVector`1<' + type + '>';
-%>
			<%- include('js_to_native_class.cpp', {type: type, metadata: metadata, to_assign: to_assign + "_vector", argument_name: argument_name }) -%>
			auto <%= to_assign %> = <%= to_assign %>_vector->GetView();
<%
} else if (type.indexOf('.IVector') != -1 || type.indexOf('.IIterable') != -1) { // IVector/IIterable
	// Pull out the internal type!
	type = type.substring(type.indexOf('`1<') + 3, type.length - 1);
	if (type == 'object') {
		type = 'Platform.Object';
	}
	if (type.indexOf('class ') == 0) {
		type = type.substring(6);
	}
-%>
			TITANIUM_ASSERT_AND_THROW(<%= argument_name %>.IsObject(), "Expected Object");
			auto object_<%= argument_name %> = static_cast<JSObject>(<%= argument_name %>);
			TITANIUM_ASSERT(object_<%= argument_name %>.IsArray());
			const auto array_<%= argument_name %> = static_cast<JSArray>(object_<%= argument_name %>);
<%

	if (type == 'string') {
		type = 'Platform.String'; // FIXME When it's strings, we need to handle them totally differently! We can't do GetPrivateItems
		// we cast to a vectore of std::string, then convert thos to platform strings
-%>
			auto items_<%= argument_name %> = static_cast<std::vector<std::string>>(array_<%= argument_name %>);
			auto <%= to_assign %> = ref new ::Platform::Collections::Vector<::<%- type.replace(/\./g, '::') %>^>();
			for (size_t i = 0; i < items_<%= argument_name %>.size(); ++i) {
				TitaniumWindows::Utility::ConvertUTF8String(static_cast<std::string>(<%= argument_name %>));
				 <%= to_assign %>->Append(TitaniumWindows::Utility::ConvertUTF8String(items_<%= argument_name %>[i]));
			}
<%
	} else { // Assume typical classes
-%>
			auto items_<%= argument_name %> = array_<%= argument_name %>.GetPrivateItems<<%= type.replace(/\./g, '::') %>>(); // std::vector<std::shared_ptr<<%= type.replace(/\./g, '::') %>>
			auto <%= to_assign %> = ref new ::Platform::Collections::Vector<::<%- type.replace(/\./g, '::') %>^>();
			for (size_t i = 0; i < items_<%= argument_name %>.size(); ++i) {
				 <%= to_assign %>->Append(items_<%= argument_name %>[i]->unwrap<%= type.replace(/\./g, '_') %>());
			}
<%
	}
} else if (type.indexOf('.IMapView') != -1) { // IMapView
	// Pull out the internal types for key and value!
	type = type.substring(type.indexOf('`2<') + 3, type.length - 1);
	// Treat as a map, then just return view of it!
	type = 'Windows.Foundation.Collections.IMap`2<' + type + '>';
-%>
			<%- include('js_to_native_class.cpp', {type: type, metadata: metadata, to_assign: to_assign + "_map", argument_name: argument_name }) -%>
			auto <%= to_assign %> = <%= to_assign %>_map->GetView();
<%
} else if (type.indexOf('.IMap') != -1) { // IMap
	// Pull out the internal types for key and value!
	type = type.substring(type.indexOf('`2<') + 3, type.length - 1);
	// Split the type in two using the comma
	var commaIndex = type.indexOf(',');
	var key_type_name = type.substring(0, commaIndex);
	var value_type_name = type.substring(commaIndex + 1);
	if (key_type_name == 'string') {
		key_type_name = 'Platform.String';
	}
	if (key_type_name == 'object') {
		key_type_name = 'Platform.Object';
	}
	if (value_type_name == 'string') {
		value_type_name = 'Platform.String';
	}
	if (value_type_name == 'object') {
		value_type_name = 'Platform.Object';
	}
	// TODO normalize the key/value type names!
	// could be 'string' or 'object'!
-%>
			ENSURE_ARRAY(<%= argument_name %>, array_<%= argument_name %>)
			auto vector_<%= argument_name %> = static_cast<std::vector<JSValue>>(array_<%= argument_name %>);
			auto <%= to_assign %> = ref new ::Platform::Collections::Map<::<%- key_type_name.replace(/\./g, '::') %>^, ::<%- value_type_name.replace(/\./g, '::') %>^>();
			for (auto v : vector_<%= argument_name %>) {
				TITANIUM_ASSERT_AND_THROW(v.IsObject(), "Expected Object");
				auto tmp = static_cast<JSObject>(v);
				auto tmp_key = tmp.GetProperty("key");
				auto tmp_value = tmp.GetProperty("value");
				<%- include('js_to_native.cpp', {type: key_type_name, metadata: metadata, to_assign: 'key', argument_name: 'tmp_key' }) -%>
				<%- include('js_to_native.cpp', {type: value_type_name, metadata: metadata, to_assign: 'value', argument_name: 'tmp_value' }) -%>
				<%= to_assign %>->Insert(key, value);
			}
<%
} else { // normal class
-%>
			TITANIUM_ASSERT_AND_THROW(<%= argument_name %>.IsObject(), "Expected Object");
			auto object_<%= argument_name %> = static_cast<JSObject>(<%= argument_name %>);
			auto wrapper_<%= to_assign %> = object_<%= argument_name %>.GetPrivate<<%= type.replace(/\./g, '::') %>>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto <%= to_assign %> = wrapper_<%= to_assign %>->unwrap<%= type.replace(/\./g, '_') %>();
<%
}
-%>
