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
            "Sensor0",
            "O3", 
            "50.25" 
        };
        Measurement measurement(fields);

        TS_ASSERT_EQUALS(measurement.getSensor(), "Sensor0");
        TS_ASSERT_EQUALS(measurement.getUnit(), "O3");
        TS_ASSERT_EQUALS((int) measurement.getValue(), 50);
    }

    void testDeserialize(void)
    {
        multimap<string, Measurement> data;
        deserialize<Measurement, multimap<string, Measurement>>(
            "datasets/measurements-50.csv", 
            data, 0, true, false
        );

        // Should contains 50 different measurements
        // TS_ASSERT_EQUALS(data.size(), 50);

        // Check that the measurements are well deserialized
    }
};
