// MusicXML Class Library
// Copyright (c) by Matthew James Briggs
// Distributed under the MIT License

#include "mxtest/control/CompileControl.h"
#ifdef MX_COMPILE_CORE_TESTS

#include "cpul/cpulTestHarness.h"
#include "mxtest/core/HelperFunctions.h"
#include "mx/core/Elements.h"
#include "mxtest/core/ToeTest.h"
#include "mxtest/core/MidiInstrumentTest.h"

using namespace mx::core;
using namespace std;
using namespace mxtest;

TEST( Test01, Toe )
{
    TestMode v = TestMode::one;
	ToePtr object = tgenToe( v );
	stringstream expected;
	tgenToeExpected( expected, 1, v );
	stringstream actual;
	// object->toStream( std::cout, 1 );
	object->toStream( actual, 1 );
	CHECK_EQUAL( expected.str(), actual.str() )
	CHECK( ! object->hasAttributes() )
	CHECK( ! object->hasContents() )
}
TEST( Test02, Toe )
{
    TestMode v = TestMode::two;
	ToePtr object = tgenToe( v );
	stringstream expected;
	tgenToeExpected( expected, 1, v );
	stringstream actual;
	// object->toStream( std::cout, 1 );
	object->toStream( actual, 1 );
	CHECK_EQUAL( expected.str(), actual.str() )
	CHECK( object->hasAttributes() )
	CHECK( ! object->hasContents() )
}
TEST( Test03, Toe )
{
    TestMode v = TestMode::three;
	ToePtr object = tgenToe( v );
	stringstream expected;
	tgenToeExpected( expected, 1, v );
	stringstream actual;
	// object->toStream( std::cout, 1 );
	object->toStream( actual, 1 );
	CHECK_EQUAL( expected.str(), actual.str() )
	CHECK( object->hasAttributes() )
	CHECK( ! object->hasContents() )
}

namespace mxtest
{
    ToePtr tgenToe( TestMode v )
    {
        ToePtr o = makeToe();
        switch ( v )
        {
            case TestMode::one:
            {
                
            }
                break;
            case TestMode::two:
            {
                o->getAttributes()->hasSubstitution = true;
                o->getAttributes()->substitution = YesNo::yes;
                o->getAttributes()->hasFontStyle = true;
                o->getAttributes()->fontStyle = FontStyle::italic;
                o->getAttributes()->hasColor = true;
                o->getAttributes()->color = Color( 83, 102, 30, 22 );
            }
                break;
            case TestMode::three:
            {
                o->getAttributes()->hasFontFamily = true;
                o->getAttributes()->fontFamily = CommaSeparatedText( "Bish,and,Bones" );
            }
                break;
            default:
                break;
        }
        return o;
    }
    void tgenToeExpected(std::ostream& os, int i, TestMode v )
    {
        
        switch ( v )
        {
            case TestMode::one:
            {
                streamLine( os, i, R"(<toe/>)", false );
            }
                break;
            case TestMode::two:
            {
                streamLine( os, i, R"(<toe font-style="italic" color="#53661E16" substitution="yes"/>)", false );
            }
                break;
            case TestMode::three:
            {
                streamLine( os, i, R"(<toe font-family="Bish,and,Bones"/>)", false );
            }
                break;
            default:
                break;
        }
    }
}

#endif
