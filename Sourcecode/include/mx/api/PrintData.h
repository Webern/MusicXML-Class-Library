// MusicXML Class Library
// Copyright (c) by Matthew James Briggs
// Distributed under the MIT License

#pragma once

#include "mx/api/ApiCommon.h"
#include "mx/api/PositionData.h"
#include "mx/api/FontData.h"
#include "mx/api/ColorData.h"

namespace mx
{
    namespace api
    {
        struct PrintData
        {
            Bool printObject;
            FontData fontData;
            bool isColorSpecified;
            ColorData color;

            PrintData()
            : printObject{ Bool::unspecified }
            , fontData{}
            , isColorSpecified{ false }
            , color{}
            {
                
            }
        };
        
        MXAPI_EQUALS_BEGIN( PrintData )
        MXAPI_EQUALS_MEMBER( printObject )
        MXAPI_EQUALS_MEMBER( fontData )
        MXAPI_EQUALS_MEMBER( isColorSpecified )
        MXAPI_EQUALS_MEMBER( color )
        MXAPI_EQUALS_END;
        MXAPI_NOT_EQUALS_AND_VECTORS( PrintData );
    }
}
