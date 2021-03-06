// MusicXML Class Library
// Copyright (c) by Matthew James Briggs
// Distributed under the MIT License

#include "mxtest/control/CompileControl.h"
#ifdef MX_COMPILE_CORE_TESTS

#include "cpul/cpulTestHarness.h"
#include "mxtest/core/HelperFunctions.h"
#include "mxtest/core/GroupNameDisplayTest.h"

using namespace mx::core;
using namespace std;
using namespace mxtest;

TEST( Test01, GroupNameDisplay )
{
    TestMode v = TestMode::one;
	GroupNameDisplayPtr object = tgenGroupNameDisplay( v );
	stringstream expected;
	tgenGroupNameDisplayExpected( expected, 1, v );
	stringstream actual;
	// object->toStream( std::cout, 1 );
	object->toStream( actual, 1 );
	CHECK_EQUAL( expected.str(), actual.str() )
	CHECK( ! object->hasAttributes() )
	CHECK( ! object->hasContents() )
}
TEST( Test02, GroupNameDisplay )
{
    TestMode v = TestMode::two;
	GroupNameDisplayPtr object = tgenGroupNameDisplay( v );
	stringstream expected;
	tgenGroupNameDisplayExpected( expected, 1, v );
	stringstream actual;
	// object->toStream( std::cout, 1 );
	object->toStream( actual, 1 );
	CHECK_EQUAL( expected.str(), actual.str() )
	CHECK( object->hasAttributes() )
	CHECK( object->hasContents() )
}
TEST( Test03, GroupNameDisplay )
{
    TestMode v = TestMode::three;
	GroupNameDisplayPtr object = tgenGroupNameDisplay( v );
	stringstream expected;
	tgenGroupNameDisplayExpected( expected, 1, v );
	stringstream actual;
	// object->toStream( std::cout, 1 );
	object->toStream( actual, 1 );
	CHECK_EQUAL( expected.str(), actual.str() )
	CHECK( ! object->hasAttributes() )
	CHECK( object->hasContents() )
}

namespace mxtest
{
    GroupNameDisplayPtr tgenGroupNameDisplay( TestMode v )
    {
        GroupNameDisplayPtr o = makeGroupNameDisplay();
        switch ( v )
        {
            case TestMode::one:
            {
                
            }
                break;
            case TestMode::two:
            {
                auto ch = makeDisplayTextOrAccidentalText();
                ch->setChoice( DisplayTextOrAccidentalText::Choice::accidentalText );
                ch->getAccidentalText()->setValue( AccidentalValue::doubleSharp );
                o->addDisplayTextOrAccidentalText( ch );
                o->getAttributes()->hasPrintObject = true;
                o->getAttributes()->printObject = YesNo::no;
            }
                break;
            case TestMode::three:
            {
                auto ch = makeDisplayTextOrAccidentalText();
                ch->setChoice( DisplayTextOrAccidentalText::Choice::displayText );
                ch->getDisplayText()->setValue( XsString( "My Display String!" ) );
                ch->getDisplayText()->getAttributes()->hasSpace = true;
                ch->getDisplayText()->getAttributes()->space = XmlSpace::preserve;
                o->addDisplayTextOrAccidentalText( ch );
            }
                break;
            default:
                break;
        }
        return o;
    }
    void tgenGroupNameDisplayExpected(std::ostream& os, int i, TestMode v )
    {
        
        switch ( v )
        {
            case TestMode::one:
            {
                streamLine( os, i, R"(<group-name-display/>)", false );
            }
                break;
            case TestMode::two:
            {
                streamLine( os, i, R"(<group-name-display print-object="no">)" );
                streamLine( os, i+1, R"(<accidental-text>double-sharp</accidental-text>)" );
                streamLine( os, i, R"(</group-name-display>)", false );
            }
                break;
            case TestMode::three:
            {
                streamLine( os, i, R"(<group-name-display>)" );
                streamLine( os, i+1, R"(<display-text xml:space="preserve">My Display String!</display-text>)" );
                streamLine( os, i, R"(</group-name-display>)", false );
            }
                break;
            default:
                break;
        }
    }
}

#endif

