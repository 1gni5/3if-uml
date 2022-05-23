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
#include "Deserialize.h"

class TestsCleaner : public CxxTest::TestSuite
{
public:
    void testConstructor(void)
    {
        list<string> fields = {
            "45.333333", 
            "1.333333", 
            "2019-02-01 12:00:00", 
            "2019-03-01 00:00:00"
        };
        Cleaner cleaner(fields);

        TS_ASSERT_EQUALS((int) cleaner.getLatitude(), 45);
        TS_ASSERT_EQUALS((int) cleaner.getLongitude(), 1);
    }

	void testDeserialize(void)
	{
		map<string, Cleaner> mp = singleKeyDeserialize<Cleaner>("datasets/cleaners.csv", 0);

		// Should contains 2 different cleaners
		TS_ASSERT_EQUALS(mp.size(), 2);

		// Check that the cleaners are well deserialized
		Cleaner cleaner = mp["Cleaner0"];
		TS_ASSERT_EQUALS((int) cleaner.getLatitude(), 45);
		TS_ASSERT_EQUALS((int) cleaner.getLongitude(), 1);
	}
};
