//-------------------------------------------------------- Include système
#include <list>
#include <string>
#include <iostream>

using std::list;
using std::string;

#include <cxxtest/TestSuite.h>

//------------------------------------------------------ Include personnel
#include "Attribute.h"
#include "Model.h"

class TestsAttribute : public CxxTest::TestSuite
{
public:
    void testConstructor(void)
    {
        list<string> fields = {"O3", "µg/m3", "concentration d'ozone"};
        Attribute attribute(fields);

        TS_ASSERT_EQUALS(attribute.getId(), "O3");
        TS_ASSERT_EQUALS(attribute.getUnit(), "µg/m3");
        TS_ASSERT_EQUALS(attribute.getDescription(), "concentration d'ozone");
    }

    void testModel(void)
    {
        Model<Attribute>::populate("datasets/attributes.csv");
        TS_ASSERT_EQUALS(Model<Attribute>::getAll().size(), 5);
        
        Attribute& attribute = Model<Attribute>::get("O3");

        TS_ASSERT_EQUALS(attribute.getId(), "O3");
        TS_ASSERT_EQUALS(attribute.getUnit(), "µg/m3");
        TS_ASSERT_EQUALS(attribute.getDescription(), "concentration d'ozone");
    }
};
