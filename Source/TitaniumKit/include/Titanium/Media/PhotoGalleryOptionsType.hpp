/**
 * TitaniumKit PhotoGalleryOptionsType
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_MEDIA_PHOTOGALLERYOPTIONSTYPE_HPP_
#define _TITANIUM_MEDIA_PHOTOGALLERYOPTIONSTYPE_HPP_

#include "Titanium/detail/TiBase.hpp"
#include "Titanium/Media/Constants.hpp"

namespace Titanium
{

	namespace UI
	{
		class View;
	} // namespace UI

	namespace Media
	{
		using namespace HAL;

		/*!
		  @struct
		  @discussion Simple object for specifying options to openPhotoGallery.
		  This is an abstract type. Any object meeting this description can be used where this type is used.
		  See http://docs.appcelerator.com/titanium/latest/#!/api/PhotoGalleryOptionsType
		*/
		struct PhotoGalleryOptionsType
		{
			bool allowEditing;
			bool animated;
			std::int32_t arrowDirection;
			bool autohide;
			JSValue cancel;
			JSValue error;
			std::vector<MediaType> mediaTypes;
			std::shared_ptr<Titanium::UI::View> popoverView;
			JSValue success;
		};
		
		PhotoGalleryOptionsType js_to_PhotoGalleryOptionsType(const JSObject& object);
		JSObject PhotoGalleryOptionsType_to_js(const JSContext& js_context, const PhotoGalleryOptionsType& config);
		
	} // namespace Media
} // namespace Titanium
#endif // _TITANIUM_MEDIA_PHOTOGALLERYOPTIONSTYPE_HPP_
