// MusicXML Class Library
// Copyright (c) by Matthew James Briggs
// Distributed under the MIT License

#include "mxtest/control/CompileControl.h"
#ifdef MX_COMPILE_CORE_TESTS

#include "cpul/cpulTestHarness.h"
#include "mxtest/core/HelperFunctions.h"
#include "mxtest/core/ArrowTest.h"

using namespace mx::core;
using namespace std;
using namespace mxtest;
#include "mxtest/control/CompileControl.h"
#ifdef MX_COMPILE_CORE_TESTS

TEST( Test01, Arrow )
{
    TestMode v = TestMode::one;
	ArrowPtr object = tgenArrow( v );
	stringstream expected;
	tgenArrowExpected( expected, 1, v );
	stringstream actual;
	// object->toStream( std::cout, 1 );
	object->toStream( actual, 1 );
	CHECK_EQUAL( expected.str(), actual.str() )
	CHECK( ! object->hasAttributes() )
	CHECK( object->hasContents() )
}
TEST( Test02, Arrow )
{
    TestMode v = TestMode::two;
	ArrowPtr object = tgenArrow( v );
	stringstream expected;
	tgenArrowExpected( expected, 1, v );
	stringstream actual;
	// object->toStream( std::cout, 1 );
	object->toStream( actual, 1 );
	CHECK_EQUAL( expected.str(), actual.str() )
	CHECK( object->hasAttributes() )
	CHECK( object->hasContents() )
}
TEST( Test03, Arrow )
{
    TestMode v = TestMode::three;
	ArrowPtr object = tgenArrow( v );
	stringstream expected;
	tgenArrowExpected( expected, 1, v );
	stringstream actual;
	// object->toStream( std::cout, 1 );
	object->toStream( actual, 1 );
	CHECK_EQUAL( expected.str(), actual.str() )
	CHECK( object->hasAttributes() )
	CHECK( object->hasContents() )
}
#endif
namespace mxtest
{
    ArrowPtr tgenArrow( TestMode v )
    {
        ArrowPtr o = makeArrow();
        switch ( v )
        {
            case TestMode::one:
            {
                
            }
                break;
            case TestMode::two:
            {
                o->setChoice( Arrow::Choice::arrowGroup );
                auto ag = makeArrowGroup();
                ag->getArrowDirection()->setValue( ArrowDirectionEnum::leftRight );
                ag->setHasArrowStyle( true );
                ag->getArrowStyle()->setValue( ArrowStyleEnum::hollow );
                o->setArrowGroup( ag );
                o->getAttributes()->hasPlacement = true;
                o->getAttributes()->placement = AboveBelow::below;
            }
                break;
            case TestMode::three:
            {
                o->setChoice( Arrow::Choice::circularArrow );
                o->getCircularArrow()->setValue( CircularArrowEnum::anticlockwise );
                o->getAttributes()->hasRelativeY = true;
                o->getAttributes()->relativeY = TenthsValue( 0.1 );
            }
                break;
            default:
                break;
        }
        return o;
    }
    void tgenArrowExpected(std::ostream& os, int i, TestMode v )
    {
        
        switch ( v )
        {
            case TestMode::one:
            {
                streamLine( os, i, R"(<arrow>)" );
                streamLine( os, i+1, R"(<arrow-direction>up</arrow-direction>)" );
                streamLine( os, i, R"(</arrow>)", false );
            }
                break;
            case TestMode::two:
            {
                streamLine( os, i, R"(<arrow placement="below">)" );
                streamLine( os, i+1, R"(<arrow-direction>left right</arrow-direction>)" );
                streamLine( os, i+1, R"(<arrow-style>hollow</arrow-style>)" );
                streamLine( os, i, R"(</arrow>)", false );
            }
                break;
            case TestMode::three:
            {
                streamLine( os, i, R"(<arrow relative-y="0.1">)" );
                streamLine( os, i+1, R"(<circular-arrow>anticlockwise</circular-arrow>)" );
                streamLine( os, i, R"(</arrow>)", false );
            }
                break;
            default:
                break;
        }
    }
}

#endif
