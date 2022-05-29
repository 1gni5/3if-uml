//-------------------------------------------------------- Include système
#include <list>
#include <string>
#include <iostream>
#include <cstdlib>

#include <map>
using std::multimap;

using std::list;
using std::string;
using std::make_pair;

#include <cxxtest/TestSuite.h>

//------------------------------------------------------ Include personnel
#include "System.h"
#include "Utilities.h"

class TestsSystem : public CxxTest::TestSuite
{
public:
    // void testConstructor(void)
    // {
    //     System system = System(); 
    // }
    
    // void testComputeAirQuality(void)
    // {
    //     time_t t = parseDateTime("2019-01-01 12:00:00", "%Y-%m-%d %H:%M:%S");
    //     std::cout << "Timestamp: " << t << std::endl;
    //     System system = System();
    //     unordered_map<string, double> results = system.computeAirQuality(47, 8, t, 10);

    //     std::cout << std::endl;
    //     for (auto& result : results)
    //     {
    //         std::cout << result.first << ": " << result.second << std::endl;
    //     }
    //     time_t start = parseDateTime("2019-01-01 12:00:00", "%Y-%m-%d %H:%M:%S");
    //     time_t end = parseDateTime("2019-12-31 12:00:00", "%Y-%m-%d %H:%M:%S");

    //     Sensor sensor = system.getNearestSensors(47, 8, 1).front();
    //     list<Sensor> sensors = system.orderSensorsByATMO(sensor, start, end);
    //     for (auto& sensor : sensors)
    //     {
    //         std::cout << sensor.getId() << std::endl;
    //     }
    // }

    void testGetNearestSensors(void)
    {
        System system = System(
            "datasets/attributes.csv",
            "datasets/cleaners.csv",
            "datasets/measurements-10.csv",
            "datasets/providers.csv",
            "datasets/sensors-05.csv",
            "datasets/users.csv"
        );

        list<Sensor> nearestSensors = system.getNearestSensors(44, 2, 5);
        
        list<Sensor> allSensors = system.getAllSensors();
        Sensor farSensor = system.getSensor("Sensor0");

        double farestDistance = distance(
            make_pair(
                farSensor.getLatitude(),
                farSensor.getLongitude()
            ),
            make_pair(44,2)
        );

        for (auto& sensor : nearestSensors)
        {
            TS_ASSERT(
                (distance (
                    make_pair(
                        sensor.getLatitude(), 
                        sensor.getLongitude()
                    ), 
                    make_pair(44, 2)
                ) <= farestDistance)
            )
        }

        list<Sensor> shouldBeEmpty = system.getNearestSensors(44, 2, -1);

        TS_ASSERT_EQUALS(shouldBeEmpty.size(), 5);
        TS_ASSERT_EQUALS(system.getNearestSensors(44, 2, 49).size(), 5);
    }

    void testDistance(void)
    {
        TS_ASSERT_DELTA(distance(make_pair(0,0), make_pair(0,0)), 0, 0.0001);
        TS_ASSERT_DELTA(distance(make_pair(0,1), make_pair(1,0)), 1.4142135, 0.0001);
    }

    void testComputeAirQuality(void)
    {
        System system = System(
            "datasets/attributes.csv",
            "datasets/cleaners.csv",
            "datasets/measurements-10.csv",
            "datasets/providers.csv",
            "datasets/sensors-05.csv",
            "datasets/users.csv"
        );

        Sensor sensorA = system.getSensor("Sensor0");
        Sensor sensorB = system.getSensor("Sensor0");
        Sensor sensorC = system.getSensor("Sensor1");
        Sensor sensorD = Sensor();

        time_t start = parseDateTime("2019-01-01 12:00:00", "%Y-%m-%d %H:%M:%S");
        time_t end = parseDateTime("2019-12-31 12:00:00", "%Y-%m-%d %H:%M:%S");

        unsigned int ATMO_A = system.computeATMOIndex(system.computeAirQuality(sensorA, start, end));
        unsigned int ATMO_B = system.computeATMOIndex(system.computeAirQuality(sensorB, start, end));
        unsigned int ATMO_C = system.computeATMOIndex(system.computeAirQuality(sensorC, start, end));
        unsigned int ATMO_D = system.computeATMOIndex(system.computeAirQuality(sensorD, start, end));

        TS_ASSERT_EQUALS(ATMO_A, ATMO_B);
        TS_ASSERT_DIFFERS(ATMO_A, ATMO_C);
        TS_ASSERT_EQUALS(ATMO_D, 1);
    }

    void testOrderSensors(void)
    {
        System system = System(
            "datasets/attributes.csv",
            "datasets/cleaners.csv",
            "datasets/measurements.csv",
            "datasets/providers.csv",
            "datasets/sensors.csv",
            "datasets/users.csv"
        );

        Sensor sensorA = system.getSensor("Sensor0");

        time_t start = parseDateTime("2019-01-01 12:00:00", "%Y-%m-%d %H:%M:%S");
        time_t end = parseDateTime("2019-12-31 12:00:00", "%Y-%m-%d %H:%M:%S");

        list<Sensor> sensors = system.orderSensorsByATMO(sensorA, start, end);
        unsigned int referenceValue = system.computeATMOIndex(system.computeAirQuality(sensorA, start, end));

        for (auto& sensor : sensors)
        {
            unsigned int value = system.computeATMOIndex(system.computeAirQuality(sensor, start, end));
            
            int delta = referenceValue - value;
            delta = abs(delta);

            TS_ASSERT_LESS_THAN_EQUALS(delta, 2);
        }
    }
};
