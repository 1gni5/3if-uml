//-------------------------------------------------------- Include système
#include <list>
#include <string>
#include <iostream>
#include <sstream>

using std::list;
using std::string;

#include <cxxtest/TestSuite.h>

//------------------------------------------------------ Include personnel
#include "Sensor.h"
#include "Deserialize.h"

class TestsSensor : public CxxTest::TestSuite
{
public:
    void testConstructor(void)
    {
        list<string> fields = {
            "44", 
            "-1", 
        };
        Sensor sensor(fields);

        TS_ASSERT_EQUALS((int) sensor.getLatitude(), 44);
        TS_ASSERT_EQUALS((int) sensor.getLongitude(), -1);
    }

	void testDeserialize(void)
	{
		map<string, Sensor> mp = singleKeyDeserialize<Sensor>("datasets/sensors.csv", 0);

		// Should contains 100 different sensors
		TS_ASSERT_EQUALS(mp.size(), 100);

		// Check that the sensors are well deserialized
		Sensor sensor = mp["Sensor0"];
		TS_ASSERT_EQUALS((int) sensor.getLatitude(), 44);
		TS_ASSERT_EQUALS((int) sensor.getLongitude(), -1);
	}
};
