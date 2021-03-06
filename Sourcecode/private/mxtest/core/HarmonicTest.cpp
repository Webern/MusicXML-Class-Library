// MusicXML Class Library
// Copyright (c) by Matthew James Briggs
// Distributed under the MIT License

#include "mxtest/control/CompileControl.h"
#ifdef MX_COMPILE_CORE_TESTS

#include "cpul/cpulTestHarness.h"
#include "mxtest/core/HelperFunctions.h"
#include "mxtest/core/HarmonicTest.h"
#include "mxtest/core/HarmonicTypeChoiceTest.h"
#include "mxtest/core/HarmonicInfoChoiceTest.h"

using namespace mx::core;
using namespace std;
using namespace mxtest;

TEST( Test01, Harmonic )
{
    TestMode v = TestMode::one;
	HarmonicPtr object = tgenHarmonic( v );
	stringstream expected;
	tgenHarmonicExpected( expected, 1, v );
	stringstream actual;
	// object->toStream( std::cout, 1 );
	object->toStream( actual, 1 );
	CHECK_EQUAL( expected.str(), actual.str() )
	CHECK( ! object->hasAttributes() )
	CHECK( ! object->hasContents() )
}
TEST( Test02, Harmonic )
{
    TestMode v = TestMode::two;
	HarmonicPtr object = tgenHarmonic( v );
	stringstream expected;
	tgenHarmonicExpected( expected, 1, v );
	stringstream actual;
	// object->toStream( std::cout, 1 );
	object->toStream( actual, 1 );
	CHECK_EQUAL( expected.str(), actual.str() )
	CHECK( object->hasAttributes() )
	CHECK( object->hasContents() )
}
TEST( Test03, Harmonic )
{
    TestMode v = TestMode::three;
	HarmonicPtr object = tgenHarmonic( v );
	stringstream expected;
	tgenHarmonicExpected( expected, 1, v );
	stringstream actual;
	// object->toStream( std::cout, 1 );
	object->toStream( actual, 1 );
	CHECK_EQUAL( expected.str(), actual.str() )
	CHECK( ! object->hasAttributes() )
	CHECK( object->hasContents() )
}

namespace mxtest
{
    HarmonicPtr tgenHarmonic( TestMode v )
    {
        HarmonicPtr o = makeHarmonic();
        switch ( v )
        {
            case TestMode::one:
            {

            }
                break;
            case TestMode::two:
            {
                o->setHasHarmonicTypeChoice( true );
                o->setHarmonicTypeChoice( tgenHarmonicTypeChoice( v ) );
                o->setHasHarmonicInfoChoice( true );
                o->setHarmonicInfoChoice( tgenHarmonicInfoChoice( v ) );
                o->getAttributes()->hasPrintObject = true;
                o->getAttributes()->printObject = YesNo::no;
                o->getAttributes()->hasFontWeight = true;
                o->getAttributes()->fontWeight = FontWeight::bold;
            }
                break;
            case TestMode::three:
            {
                o->setHasHarmonicTypeChoice( true );
                o->setHarmonicTypeChoice( tgenHarmonicTypeChoice( v ) );
                o->setHasHarmonicInfoChoice( true );
                o->setHarmonicInfoChoice( tgenHarmonicInfoChoice( v ) );
            }
                break;
            default:
                break;
        }
        return o;
    }
    void tgenHarmonicExpected(std::ostream& os, int i, TestMode v )
    {
        
        switch ( v )
        {
            case TestMode::one:
            {

                streamLine( os, i, R"(<harmonic/>)", false );
            }
                break;
            case TestMode::two:
            {
                streamLine( os, i, R"(<harmonic print-object="no" font-weight="bold">)" );
                tgenHarmonicTypeChoiceExpected( os, i+1, v );
                os << std::endl;
                tgenHarmonicInfoChoiceExpected( os, i+1, v );
                os << std::endl;
                streamLine( os, i, R"(</harmonic>)", false );
            }
                break;
            case TestMode::three:
            {
                streamLine( os, i, R"(<harmonic>)" );
                tgenHarmonicTypeChoiceExpected( os, i+1, v );
                os << std::endl;
                tgenHarmonicInfoChoiceExpected( os, i+1, v );
                os << std::endl;
                streamLine( os, i, R"(</harmonic>)", false );
            }
                break;
            default:
                break;
        }
    }
}

#endif
