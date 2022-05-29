/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_TestsAttribute_init = false;
#include "tests/TestsAttribute.h"

static TestsAttribute suite_TestsAttribute;

static CxxTest::List Tests_TestsAttribute = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TestsAttribute( "tests/TestsAttribute.h", 15, "TestsAttribute", suite_TestsAttribute, Tests_TestsAttribute );

static class TestDescription_suite_TestsAttribute_testConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestsAttribute_testConstructor() : CxxTest::RealTestDescription( Tests_TestsAttribute, suiteDescription_TestsAttribute, 18, "testConstructor" ) {}
 void runTest() { suite_TestsAttribute.testConstructor(); }
} testDescription_suite_TestsAttribute_testConstructor;

static class TestDescription_suite_TestsAttribute_testModel : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestsAttribute_testModel() : CxxTest::RealTestDescription( Tests_TestsAttribute, suiteDescription_TestsAttribute, 28, "testModel" ) {}
 void runTest() { suite_TestsAttribute.testModel(); }
} testDescription_suite_TestsAttribute_testModel;

#include "tests/TestsSensor.h"

static TestsSensor suite_TestsSensor;

static CxxTest::List Tests_TestsSensor = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TestsSensor( "tests/TestsSensor.h", 16, "TestsSensor", suite_TestsSensor, Tests_TestsSensor );

static class TestDescription_suite_TestsSensor_testConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestsSensor_testConstructor() : CxxTest::RealTestDescription( Tests_TestsSensor, suiteDescription_TestsSensor, 19, "testConstructor" ) {}
 void runTest() { suite_TestsSensor.testConstructor(); }
} testDescription_suite_TestsSensor_testConstructor;

static class TestDescription_suite_TestsSensor_testModel : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestsSensor_testModel() : CxxTest::RealTestDescription( Tests_TestsSensor, suiteDescription_TestsSensor, 33, "testModel" ) {}
 void runTest() { suite_TestsSensor.testModel(); }
} testDescription_suite_TestsSensor_testModel;

#include "tests/TestsMeasurement.h"

static TestsMeasurement suite_TestsMeasurement;

static CxxTest::List Tests_TestsMeasurement = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TestsMeasurement( "tests/TestsMeasurement.h", 18, "TestsMeasurement", suite_TestsMeasurement, Tests_TestsMeasurement );

static class TestDescription_suite_TestsMeasurement_testConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestsMeasurement_testConstructor() : CxxTest::RealTestDescription( Tests_TestsMeasurement, suiteDescription_TestsMeasurement, 21, "testConstructor" ) {}
 void runTest() { suite_TestsMeasurement.testConstructor(); }
} testDescription_suite_TestsMeasurement_testConstructor;

static class TestDescription_suite_TestsMeasurement_testModel : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestsMeasurement_testModel() : CxxTest::RealTestDescription( Tests_TestsMeasurement, suiteDescription_TestsMeasurement, 34, "testModel" ) {}
 void runTest() { suite_TestsMeasurement.testModel(); }
} testDescription_suite_TestsMeasurement_testModel;

static class TestDescription_suite_TestsMeasurement_testReference : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestsMeasurement_testReference() : CxxTest::RealTestDescription( Tests_TestsMeasurement, suiteDescription_TestsMeasurement, 40, "testReference" ) {}
 void runTest() { suite_TestsMeasurement.testReference(); }
} testDescription_suite_TestsMeasurement_testReference;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
