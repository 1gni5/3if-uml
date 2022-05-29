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
#include "Model.h"

class TestsSensor : public CxxTest::TestSuite
{
public:
    void testConstructor(void)
    {
        list<string> fields = {
            "Sensor0",
            "44", 
            "-1"
        };
        Sensor sensor(fields);

        TS_ASSERT_EQUALS(sensor.getId(), "Sensor0");
        TS_ASSERT_EQUALS((int) sensor.getLatitude(), 44);
        TS_ASSERT_EQUALS((int) sensor.getLongitude(), -1);
    }

    void testModel(void)
    {
        Model<Sensor>::populate("datasets/sensors.csv");
        TS_ASSERT_EQUALS(Model<Sensor>::getAll().size(), 100);

        Sensor sensor = Model<Sensor>::get("Sensor0");
        TS_ASSERT_EQUALS(sensor.getId(), "Sensor0");
        TS_ASSERT_EQUALS((int) sensor.getLatitude(), 44);
        TS_ASSERT_EQUALS((int) sensor.getLongitude(), -1);
    }
};
