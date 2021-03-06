// MusicXML Class Library
// Copyright (c) by Matthew James Briggs
// Distributed under the MIT License

#include "mxtest/control/CompileControl.h"
#ifdef MX_COMPILE_CORE_TESTS

#include "cpul/cpulTestHarness.h"
#include "mxtest/core/HelperFunctions.h"
#include "mxtest/core/CreditWordsGroupTest.h"

using namespace mx::core;
using namespace std;
using namespace mxtest;

TEST( Test01, CreditWordsGroup )
{
    TestMode v = TestMode::one;
	CreditWordsGroupPtr object = tgenCreditWordsGroup( v );
	stringstream expected;
	tgenCreditWordsGroupExpected( expected, 1, v );
	stringstream actual;
	// object->toStream( std::cout, 1 );
    bool isOneLineOnly = true;
	object->streamContents( actual, 1, isOneLineOnly );
	CHECK_EQUAL( expected.str(), actual.str() )
	CHECK( ! object->hasAttributes() )
	CHECK( object->hasContents() )
}
TEST( Test02, CreditWordsGroup )
{
    TestMode v = TestMode::two;
	CreditWordsGroupPtr object = tgenCreditWordsGroup( v );
	stringstream expected;
	tgenCreditWordsGroupExpected( expected, 1, v );
	stringstream actual;
	// object->toStream( std::cout, 1 );
    bool isOneLineOnly = true;
	object->streamContents( actual, 1, isOneLineOnly );
	CHECK_EQUAL( expected.str(), actual.str() )
	CHECK( ! object->hasAttributes() )
	CHECK( object->hasContents() )
}
TEST( Test03, CreditWordsGroup )
{
    TestMode v = TestMode::three;
	CreditWordsGroupPtr object = tgenCreditWordsGroup( v );
	stringstream expected;
	tgenCreditWordsGroupExpected( expected, 1, v );
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
    CreditWordsGroupPtr tgenCreditWordsGroup( TestMode v )
    {
        CreditWordsGroupPtr o = makeCreditWordsGroup();
        switch ( v )
        {
            case TestMode::one:
            {
                
            }
                break;
            case TestMode::two:
            {
                o->getCreditWords()->setValue( XsString( "Matthew James Briggs" ) );
                auto l1 = makeLink();
                l1->getAttributes()->href = XlinkHref("matthewjamesbriggs.com");
                o->addLink( l1 );
                auto b1 = makeBookmark();
                b1->getAttributes()->hasElement = true;
                b1->getAttributes()->element = XsNMToken( "NMToken1" );
                o->addBookmark( b1 );
            }
                break;
            case TestMode::three:
            {
                o->getCreditWords()->setValue( XsString( ".mjb" ) );
                auto l1 = makeLink();
                l1->getAttributes()->href = XlinkHref("matthewjamesbriggs.com");
                o->addLink( l1 );
                auto l2 = makeLink();
                l2->getAttributes()->href = XlinkHref("somethingelse.com");
                o->addLink( l2 );
                auto b1 = makeBookmark();
                b1->getAttributes()->hasElement = true;
                b1->getAttributes()->element = XsNMToken( "NMToken2" );
                o->addBookmark( b1 );
                auto b2 = makeBookmark();
                b2->getAttributes()->hasElement = true;
                b2->getAttributes()->element = XsNMToken( "NMToken3" );
                o->addBookmark( b2 );
            }
                break;
            default:
                break;
        }
        return o;
    }
    void tgenCreditWordsGroupExpected(std::ostream& os, int i, TestMode v )
    {
        
        switch ( v )
        {
            case TestMode::one:
            {
                streamLine( os, i, R"(<credit-words></credit-words>)", false );
            }
                break;
            case TestMode::two:
            {
                streamLine( os, i, R"(<link xlink:href="matthewjamesbriggs.com"/>)" );
                streamLine( os, i, R"(<bookmark id="ID" element="NMToken1"/>)" );
                streamLine( os, i, R"(<credit-words>Matthew James Briggs</credit-words>)", false );
            }
                break;
            case TestMode::three:
            {
                streamLine( os, i, R"(<link xlink:href="matthewjamesbriggs.com"/>)" );
                streamLine( os, i, R"(<link xlink:href="somethingelse.com"/>)" );
                streamLine( os, i, R"(<bookmark id="ID" element="NMToken2"/>)" );
                streamLine( os, i, R"(<bookmark id="ID" element="NMToken3"/>)" );
                streamLine( os, i, R"(<credit-words>.mjb</credit-words>)", false );
            }
                break;
            default:
                break;
        }
    }
}

#endif
