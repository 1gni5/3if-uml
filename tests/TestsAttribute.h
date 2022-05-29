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
		map<string, Attribute> data;
		deserialize<Attribute>(
			"datasets/attributes.csv", 
			data, 0, true
		);

        // Should contains 4 different attributes
        TS_ASSERT_EQUALS(data.size(), 4);

        // Check that the attributes are well deserialized
        Attribute& attr = data["PM10"];
        TS_ASSERT_EQUALS(attr.getUnit(), "µg/m3");
        TS_ASSERT_EQUALS(attr.getDescription(), "concentration de particules fines");
    }
};
