//-------------------------------------------------------- Include système
#include <list>
#include <string>
#include <iostream>

using std::list;
using std::string;

#include <cxxtest/TestSuite.h>

//------------------------------------------------------ Include personnel
#include "Attribute.h"
#include "Deserialize.h"

class TestsAttribute : public CxxTest::TestSuite
{
public:
    void testConstructor(void)
    {
        list<string> fields = {"unit", "description"};
        Attribute attribute(fields);

        TS_ASSERT_EQUALS(attribute.getUnit(), "unit");
        TS_ASSERT_EQUALS(attribute.getDescription(), "description");
    }

    void testDeserialize(void)
    {
        multimap<string, Attribute> mp = deserialize<Attribute>("datasets/attributes.csv", 0, true);

        TS_ASSERT_EQUALS(mp.size(), 4);

        for (auto itr = mp.find("PM10"); itr != mp.end(); itr++)
        {
            TS_ASSERT_EQUALS(itr->second.getUnit(), "µg/m3");
            TS_ASSERT_EQUALS(itr->second.getDescription(), "concentration de particules fines");
            break;
        }
    }
};