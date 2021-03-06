// MusicXML Class Library
// Copyright (c) by Matthew James Briggs
// Distributed under the MIT License

#include "mxtest/control/CompileControl.h"
#ifdef MX_COMPILE_CORE_TESTS

#include "cpul/cpulTestHarness.h"
#include "mxtest/core/HelperFunctions.h"
#include "mxtest/core/PageLayoutTest.h"
#include "mxtest/core/PageMarginsTest.h"
#include "mxtest/core/MidiInstrumentTest.h"

using namespace mx::core;
using namespace std;
using namespace mxtest;

TEST( Test01, PageLayout )
{
    TestMode v = TestMode::one;
	PageLayoutPtr object = tgenPageLayout( v );
	stringstream expected;
	tgenPageLayoutExpected( expected, 1, v );
	stringstream actual;
	// object->toStream( std::cout, 1 );
	object->toStream( actual, 1 );
	CHECK_EQUAL( expected.str(), actual.str() )
	CHECK( ! object->hasAttributes() )
	CHECK( object->hasContents() )
}
TEST( Test02, PageLayout )
{
    TestMode v = TestMode::two;
	PageLayoutPtr object = tgenPageLayout( v );
	stringstream expected;
	tgenPageLayoutExpected( expected, 1, v );
	stringstream actual;
	// object->toStream( std::cout, 1 );
	object->toStream( actual, 1 );
	CHECK_EQUAL( expected.str(), actual.str() )
	CHECK( ! object->hasAttributes() )
	CHECK( object->hasContents() )
}
TEST( Test03, PageLayout )
{
    TestMode v = TestMode::three;
	PageLayoutPtr object = tgenPageLayout( v );
	stringstream expected;
	tgenPageLayoutExpected( expected, 1, v );
	stringstream actual;
	// object->toStream( std::cout, 1 );
	object->toStream( actual, 1 );
	CHECK_EQUAL( expected.str(), actual.str() )
	CHECK( ! object->hasAttributes() )
	CHECK( object->hasContents() )
}

namespace mxtest
{
    PageLayoutPtr tgenPageLayout( TestMode v )
    {
        PageLayoutPtr o = makePageLayout();
        switch ( v )
        {
            case TestMode::one:
            {
                
            }
                break;
            case TestMode::two:
            {
                o->getPageHeight()->setValue( TenthsValue( 2534 ) );
                o->getPageWidth()->setValue( TenthsValue( 4352 ) );
                o->addPageMargins( tgenPageMargins( TestMode::one ) );
                o->addPageMargins( tgenPageMargins( TestMode::two ) );
            }
                break;
            case TestMode::three:
            {
                o->getPageHeight()->setValue( TenthsValue( 3524 ) );
                o->getPageWidth()->setValue( TenthsValue( 3241 ) );
                o->addPageMargins( tgenPageMargins( TestMode::three ) );
            }
                break;
            default:
                break;
        }
        return o;
    }
    void tgenPageLayoutExpected(std::ostream& os, int i, TestMode v )
    {
        
        switch ( v )
        {
            case TestMode::one:
            {
                streamLine( os, i, R"(<page-layout>)" );
                streamLine( os, i+1, R"(<page-height>0</page-height>)" );
                streamLine( os, i+1, R"(<page-width>0</page-width>)" );
                streamLine( os, i, R"(</page-layout>)", false );
            }
                break;
            case TestMode::two:
            {
                streamLine( os, i, R"(<page-layout>)" );
                streamLine( os, i+1, R"(<page-height>2534</page-height>)" );
                streamLine( os, i+1, R"(<page-width>4352</page-width>)" );
                tgenPageMarginsExpected(os, i+1, TestMode::one );
                os << std::endl;
                tgenPageMarginsExpected(os, i+1, TestMode::two );
                os << std::endl;
                streamLine( os, i, R"(</page-layout>)", false );
            }
                break;
            case TestMode::three:
            {
                streamLine( os, i, R"(<page-layout>)" );
                streamLine( os, i+1, R"(<page-height>3524</page-height>)" );
                streamLine( os, i+1, R"(<page-width>3241</page-width>)" );
                tgenPageMarginsExpected(os, i+1, TestMode::three );
                os << std::endl;
                streamLine( os, i, R"(</page-layout>)", false );
            }
                break;
            default:
                break;
        }
    }
}

#endif
