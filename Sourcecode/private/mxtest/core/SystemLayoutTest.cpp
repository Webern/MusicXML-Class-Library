// MusicXML Class Library
// Copyright (c) by Matthew James Briggs
// Distributed under the MIT License

#include "mxtest/control/CompileControl.h"
#ifdef MX_COMPILE_CORE_TESTS

#include "cpul/cpulTestHarness.h"
#include "mxtest/core/HelperFunctions.h"
#include "mxtest/core/SystemLayoutTest.h"
#include "mxtest/core/SystemMarginsTest.h"
#include "mxtest/core/SystemDividersTest.h"


using namespace mx::core;
using namespace std;
using namespace mxtest;

TEST( Test01, SystemLayout )
{
    TestMode v = TestMode::one;
	SystemLayoutPtr object = tgenSystemLayout( v );
	stringstream expected;
	tgenSystemLayoutExpected( expected, 1, v );
	stringstream actual;
	// object->toStream( std::cout, 1 );
	object->toStream( actual, 1 );
	CHECK_EQUAL( expected.str(), actual.str() )
	CHECK( ! object->hasAttributes() )
	CHECK( ! object->hasContents() )
}
TEST( Test02, SystemLayout )
{
    TestMode v = TestMode::two;
	SystemLayoutPtr object = tgenSystemLayout( v );
	stringstream expected;
	tgenSystemLayoutExpected( expected, 1, v );
	stringstream actual;
	// object->toStream( std::cout, 1 );
	object->toStream( actual, 1 );
	CHECK_EQUAL( expected.str(), actual.str() )
	CHECK( ! object->hasAttributes() )
	CHECK( object->hasContents() )
}
TEST( Test03, SystemLayout )
{
    TestMode v = TestMode::three;
	SystemLayoutPtr object = tgenSystemLayout( v );
	stringstream expected;
	tgenSystemLayoutExpected( expected, 1, v );
	stringstream actual;
	// object->toStream( std::cout, 1 );
	object->toStream( actual, 1 );
	CHECK_EQUAL( expected.str(), actual.str() )
	CHECK( ! object->hasAttributes() )
	CHECK( object->hasContents() )
}

namespace mxtest
{
    SystemLayoutPtr tgenSystemLayout( TestMode v )
    {
        SystemLayoutPtr o = makeSystemLayout();
        switch ( v )
        {
            case TestMode::one:
            {
                
            }
                break;
            case TestMode::two:
            {
                o->setHasSystemMargins( true );
                o->setSystemMargins( tgenSystemMargins( v ) );
                o->setHasTopSystemDistance( true );
                o->getTopSystemDistance()->setValue( TenthsValue( 1.1 ) );
                o->setHasSystemDistance( true );
                o->getSystemDistance()->setValue( TenthsValue( 2.2 ) );
                o->setHasSystemDividers( true );
                o->setSystemDividers( tgenSystemDividers( v ) );
            }
                break;
            case TestMode::three:
            {
                o->setHasSystemMargins( true );
                o->setSystemMargins( tgenSystemMargins( v ) );
                o->setHasTopSystemDistance( true );
                o->getTopSystemDistance()->setValue( TenthsValue( 3.3 ) );
                o->setHasSystemDistance( true );
                o->getSystemDistance()->setValue( TenthsValue( 4.4 ) );
            }
                break;
            default:
                break;
        }
        return o;
    }
    void tgenSystemLayoutExpected(std::ostream& os, int i, TestMode v )
    {
        
        switch ( v )
        {
            case TestMode::one:
            {
                streamLine( os, i, R"(<system-layout/>)", false );
            }
                break;
            case TestMode::two:
            {
                streamLine( os, i, R"(<system-layout>)" );
                tgenSystemMarginsExpected( os, i+1, v );
                os << std::endl;
                streamLine( os, i+1, R"(<system-distance>2.2</system-distance>)" );
                streamLine( os, i+1, R"(<top-system-distance>1.1</top-system-distance>)" );
                tgenSystemDividersExpected( os, i+1, v );
                os << std::endl;
                streamLine( os, i, R"(</system-layout>)", false );
            }
                break;
            case TestMode::three:
            {
                streamLine( os, i, R"(<system-layout>)" );
                tgenSystemMarginsExpected( os, i+1, v );
                os << std::endl;
                streamLine( os, i+1, R"(<system-distance>4.4</system-distance>)" );
                streamLine( os, i+1, R"(<top-system-distance>3.3</top-system-distance>)" );
                streamLine( os, i, R"(</system-layout>)", false );
            }
                break;
            default:
                break;
        }
    }
}

#endif
