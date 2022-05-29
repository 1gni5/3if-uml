//-------------------------------------------------------- Include système
#include <list>
#include <string>
#include <iostream>

#include <map>
using std::multimap;

using std::list;
using std::string;

#include <cxxtest/TestSuite.h>

//------------------------------------------------------ Include personnel
#include "System.h"
#include "Utilities.h"

class TestsSystem : public CxxTest::TestSuite
{
public:
    void testConstructor(void)
    {
        System system = System(); 
    }
    
    void testComputeAirQuality(void)
    {
        time_t t = parseDateTime("2019-01-01 12:00:00", "%Y-%m-%d %H:%M:%S");
        std::cout << "Timestamp: " << t << std::endl;
        System system = System();
        unordered_map<string, double> results = system.computeAirQuality(47, 8, t, 10);

        std::cout << std::endl;
        for (auto& result : results)
        {
            std::cout << result.first << ": " << result.second << std::endl;
        }
        time_t start = parseDateTime("2019-01-01 12:00:00", "%Y-%m-%d %H:%M:%S");
        time_t end = parseDateTime("2019-12-31 12:00:00", "%Y-%m-%d %H:%M:%S");

        Sensor sensor = system.getNearestSensors(47, 8, 1).front();
        list<Sensor> sensors = system.orderSensorsByATMO(sensor, start, end);
        for (auto& sensor : sensors)
        {
            std::cout << sensor.getId() << std::endl;
        }
    }
};
