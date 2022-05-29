//-------------------------------------------------------- Include système
#include <list>
#include <string>
#include <iostream>
#include <sstream>

using std::list;
using std::string;

#include <cxxtest/TestSuite.h>

//------------------------------------------------------ Include personnel
#include "Cleaner.h"
#include "Model.h"

class TestsCleaner : public CxxTest::TestSuite
{
public:
    void testConstructor(void)
    {
        list<string> fields = {
            "Cleaner0",
            "45.333333", 
            "1.333333", 
            "2019-02-01 12:00:00", 
            "2019-03-01 00:00:00"
        };
        Cleaner cleaner(fields);

        TS_ASSERT_EQUALS(cleaner.getUnique(), "Cleaner0");
        TS_ASSERT_EQUALS((int) cleaner.getLatitude(), 45);
        TS_ASSERT_EQUALS((int) cleaner.getLongitude(), 1);
    }

	void testModel(void)
    {
        Model<Cleaner>::populate("datasets/cleaners.csv");
        TS_ASSERT_EQUALS(Model<Cleaner>::getAll().size(), 2);
        
        Cleaner cleaner = Model<Cleaner>::get("Cleaner0");

        TS_ASSERT_EQUALS(cleaner.getUnique(), "Cleaner0");
        TS_ASSERT_EQUALS((int) cleaner.getLatitude(), 45);
        TS_ASSERT_EQUALS((int) cleaner.getLongitude(), 1);
    }
};
