//-------------------------------------------------------- Include système
#include <list>
#include <string>
#include <iostream>
#include <sstream>

using std::list;
using std::string;

using std::cout;
using std::endl;

#include <cxxtest/TestSuite.h>

//------------------------------------------------------ Include personnel
#include "Measurement.h"

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

        TS_ASSERT_EQUALS((int) measurement.getValue(), 50);
    }

    void testModel(void)
    {
        Model<Measurement>::populate("datasets/measurements-50.csv");
        TS_ASSERT_EQUALS(Model<Measurement>::getAll().size(), 50);
    }

    void testReference(void)
    {
        Model<Attribute>::populate("datasets/attributes.csv");
        Model<Sensor>::populate("datasets/sensors.csv");
        Model<Measurement>::populate("datasets/measurements-50.csv");

        Measurement& measurement = Model<Measurement>::get(0);

        if (measurement.getAttribute() != nullptr)
        {
            Attribute& attribute = *measurement.getAttribute();
            TS_ASSERT_EQUALS(attribute.getId(), "O3");
            TS_ASSERT_EQUALS(attribute.getUnit(), "µg/m3");
            TS_ASSERT_EQUALS(attribute.getDescription(), "concentration d'ozone");
            TS_ASSERT_LESS_THAN(0, attribute.getMeasurements().size());
        }

        if (measurement.getSensor() != nullptr)
        {
            Sensor& sensor = *measurement.getSensor();
            TS_ASSERT_EQUALS(sensor.getId(), "Sensor0");
            TS_ASSERT_EQUALS((int) sensor.getLatitude(), 44);
            TS_ASSERT_EQUALS((int) sensor.getLongitude(), -1);
            TS_ASSERT_LESS_THAN(0,sensor.getMeasurements().size());
        }
        
    }
};
