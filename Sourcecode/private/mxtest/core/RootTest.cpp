// MusicXML Class Library
// Copyright (c) by Matthew James Briggs
// Distributed under the MIT License

#include "mxtest/control/CompileControl.h"
#ifdef MX_COMPILE_CORE_TESTS

#include "cpul/cpulTestHarness.h"
#include "mxtest/core/HelperFunctions.h"
#include "mxtest/core/RootTest.h"
#include "mxtest/core/MidiInstrumentTest.h"

using namespace mx::core;
using namespace std;
using namespace mxtest;

TEST( Test01, Root )
{
    TestMode v = TestMode::one;
	RootPtr object = tgenRoot( v );
	stringstream expected;
	tgenRootExpected( expected, 1, v );
	stringstream actual;
	// object->toStream( std::cout, 1 );
	object->toStream( actual, 1 );
	CHECK_EQUAL( expected.str(), actual.str() )
	CHECK( ! object->hasAttributes() )
	CHECK( object->hasContents() )
}
TEST( Test02, Root )
{
    TestMode v = TestMode::two;
	RootPtr object = tgenRoot( v );
	stringstream expected;
	tgenRootExpected( expected, 1, v );
	stringstream actual;
	// object->toStream( std::cout, 1 );
	object->toStream( actual, 1 );
	CHECK_EQUAL( expected.str(), actual.str() )
	CHECK( ! object->hasAttributes() )
	CHECK( object->hasContents() )
}
TEST( Test03, Root )
{
    TestMode v = TestMode::three;
	RootPtr object = tgenRoot( v );
	stringstream expected;
	tgenRootExpected( expected, 1, v );
	stringstream actual;
	// object->toStream( std::cout, 1 );
	object->toStream( actual, 1 );
	CHECK_EQUAL( expected.str(), actual.str() )
	CHECK( ! object->hasAttributes() )
	CHECK( object->hasContents() )
}

namespace mxtest
{
    RootPtr tgenRoot( TestMode v )
    {
        RootPtr o = makeRoot();
        switch ( v )
        {
            case TestMode::one:
            {
                
            }
                break;
            case TestMode::two:
            {
                o->setHasRootAlter( true );
                o->getRootAlter()->setValue( Semitones( -2 ) );
                o->getRootStep()->setValue( StepEnum::f );
            }
                break;
            case TestMode::three:
            {
                o->setHasRootAlter( true );
                o->getRootAlter()->setValue( Semitones( 1.1 ) );
                o->getRootStep()->setValue( StepEnum::c );
            }
                break;
            default:
                break;
        }
        return o;
    }
    void tgenRootExpected(std::ostream& os, int i, TestMode v )
    {
        
        switch ( v )
        {
            case TestMode::one:
            {
                streamLine( os, i, R"(<root>)" );
                streamLine( os, i+1, R"(<root-step>A</root-step>)" );
                streamLine( os, i, R"(</root>)", false );
            }
                break;
            case TestMode::two:
            {
                streamLine( os, i, R"(<root>)" );
                streamLine( os, i+1, R"(<root-step>F</root-step>)" );
                streamLine( os, i+1, R"(<root-alter>-2</root-alter>)" );
                streamLine( os, i, R"(</root>)", false );
            }
                break;
            case TestMode::three:
            {
                streamLine( os, i, R"(<root>)" );
                streamLine( os, i+1, R"(<root-step>C</root-step>)" );
                streamLine( os, i+1, R"(<root-alter>1.1</root-alter>)" );
                streamLine( os, i, R"(</root>)", false );
            }
                break;
            default:
                break;
        }
    }
}

#endif
