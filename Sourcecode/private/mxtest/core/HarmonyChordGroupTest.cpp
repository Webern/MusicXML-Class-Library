// MusicXML Class Library
// Copyright (c) by Matthew James Briggs
// Distributed under the MIT License

#include "mxtest/control/CompileControl.h"
#ifdef MX_COMPILE_CORE_TESTS

#include "cpul/cpulTestHarness.h"
#include "mxtest/core/HelperFunctions.h"
#include "mxtest/core/HarmonyChordGroupTest.h"
#include "mxtest/core/VirtualInstrumentTest.h"
#include "mxtest/core/EncodingTest.h"
#include "mxtest/core/RootTest.h"
#include "mxtest/core/BassTest.h"
#include "mxtest/core/DegreeTest.h"

using namespace mx::core;
using namespace std;
using namespace mxtest;

TEST( Test01, HarmonyChordGroup )
{
    TestMode v = TestMode::one;
	HarmonyChordGroupPtr object = tgenHarmonyChordGroup( v );
	stringstream expected;
	tgenHarmonyChordGroupExpected( expected, 1, v );
	stringstream actual;
	// object->toStream( std::cout, 1 );
    bool isOneLineOnly = true;
	object->streamContents( actual, 1, isOneLineOnly );
	CHECK_EQUAL( expected.str(), actual.str() )
	CHECK( ! object->hasAttributes() )
	CHECK( object->hasContents() )
}
TEST( Test02, HarmonyChordGroup )
{
    TestMode v = TestMode::two;
	HarmonyChordGroupPtr object = tgenHarmonyChordGroup( v );
	stringstream expected;
	tgenHarmonyChordGroupExpected( expected, 1, v );
	stringstream actual;
	// object->toStream( std::cout, 1 );
    bool isOneLineOnly = true;
	object->streamContents( actual, 1, isOneLineOnly );
	CHECK_EQUAL( expected.str(), actual.str() )
	CHECK( ! object->hasAttributes() )
	CHECK( object->hasContents() )
}
TEST( Test03, HarmonyChordGroup )
{
    TestMode v = TestMode::three;
	HarmonyChordGroupPtr object = tgenHarmonyChordGroup( v );
	stringstream expected;
	tgenHarmonyChordGroupExpected( expected, 1, v );
	stringstream actual;
	// object->toStream( std::cout, 1 );
    bool isOneLineOnly = true;
	object->streamContents( actual, 1, isOneLineOnly );
	CHECK_EQUAL( expected.str(), actual.str() )
	CHECK( ! object->hasAttributes() )
	CHECK( object->hasContents() )
}

namespace mxtest
{
    HarmonyChordGroupPtr tgenHarmonyChordGroup( TestMode v )
    {
        HarmonyChordGroupPtr o = makeHarmonyChordGroup();
        switch ( v )
        {
            case TestMode::one:
            {
                
            }
                break;
            case TestMode::two:
            {
                o->setRoot( tgenRoot( v ) );
                o->setChoice( HarmonyChordGroup::Choice::function );
                o->getFunction()->setValue( XsString("II" ) );
                o->getKind()->setValue( KindValue::diminished );
                o->setHasBass( true );
                o->setBass( tgenBass( v ) );
                o->addDegree( tgenDegree( v ) );
            }
                break;
            case TestMode::three:
            {
                o->setRoot( tgenRoot( v ) );
                o->setChoice( HarmonyChordGroup::Choice::root );
                o->getKind()->setValue( KindValue::dominant13th );
                o->setHasBass( true );
                o->setBass( tgenBass( v ) );
                o->addDegree( tgenDegree( TestMode::one ) );
                o->addDegree( tgenDegree( TestMode::three ) );
            }
                break;
            default:
                break;
        }
        return o;
    }
    void tgenHarmonyChordGroupExpected(std::ostream& os, int i, TestMode v )
    {
        
        switch ( v )
        {
            case TestMode::one:
            {
                tgenRootExpected( os, i, v );
                os << std::endl;
                streamLine( os, i, R"(<kind>none</kind>)", false );
            }
                break;
            case TestMode::two:
            {
                streamLine( os, i, R"(<function>II</function>)" );
                streamLine( os, i, R"(<kind>diminished</kind>)" );
                tgenBassExpected( os, i, v );
                os << std::endl;
                tgenDegreeExpected( os, i, v );
            }
                break;
            case TestMode::three:
            {
                tgenRootExpected( os, i, v );
                os << std::endl;
                streamLine( os, i, R"(<kind>dominant-13th</kind>)" );
                tgenBassExpected( os, i, v );
                os << std::endl;
                tgenDegreeExpected(os, i, TestMode::one );
                os << std::endl;
                tgenDegreeExpected(os, i, TestMode::three );
            }
                break;
            default:
                break;
        }
    }
}

#endif
