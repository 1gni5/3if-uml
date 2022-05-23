//-------------------------------------------------------- Include système
#include <list>
#include <string>
#include <iostream>
#include <sstream>

using std::list;
using std::string;

#include <cxxtest/TestSuite.h>

//------------------------------------------------------ Include personnel
#include "Measurement.h"
#include "Deserialize.h"

class TestsMeasurement : public CxxTest::TestSuite
{
public:
    void testConstructor(void)
    {
        list<string> fields = {
            "2019-03-01 00:00:00",
            "O3", 
            "50.25" 
        };
        Measurement measurement(fields);

        TS_ASSERT_EQUALS(measurement.getUnit(), "O3");
        TS_ASSERT_EQUALS((int) measurement.getValue(), 50);
    }
};
