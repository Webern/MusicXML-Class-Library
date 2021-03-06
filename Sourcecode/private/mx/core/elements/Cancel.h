// MusicXML Class Library
// Copyright (c) by Matthew James Briggs
// Distributed under the MIT License

#pragma once

#include "mx/core/ForwardDeclare.h"
#include "mx/core/ElementInterface.h"
#include "mx/core/Integers.h"
#include "mx/core/elements/CancelAttributes.h"

#include <iosfwd>
#include <memory>
#include <vector>

namespace mx
{
    namespace core
    {

        MX_FORWARD_DECLARE_ATTRIBUTES( CancelAttributes )
        MX_FORWARD_DECLARE_ELEMENT( Cancel )

        inline CancelPtr makeCancel() { return std::make_shared<Cancel>(); }
		inline CancelPtr makeCancel( const FifthsValue& value ) { return std::make_shared<Cancel>( value ); }
		inline CancelPtr makeCancel( FifthsValue&& value ) { return std::make_shared<Cancel>( std::move( value ) ); }

        class Cancel : public ElementInterface
        {
        public:
            Cancel();
            Cancel( const FifthsValue& value );

            virtual bool hasAttributes() const;
            virtual bool hasContents() const;
            virtual std::ostream& streamAttributes( std::ostream& os ) const;
            virtual std::ostream& streamName( std::ostream& os ) const;
            virtual std::ostream& streamContents( std::ostream& os, const int indentLevel, bool& isOneLineOnly ) const;
            CancelAttributesPtr getAttributes() const;
            void setAttributes( const CancelAttributesPtr& attributes );
            FifthsValue getValue() const;
            void setValue( const FifthsValue& value );

            private:
            virtual bool fromXElementImpl( std::ostream& message, ::ezxml::XElement& xelement );

        private:
            FifthsValue myValue;
            CancelAttributesPtr myAttributes;
        };
    }
}
