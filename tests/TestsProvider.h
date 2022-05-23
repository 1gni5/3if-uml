//-------------------------------------------------------- Include système
#include <list>
#include <string>
#include <iostream>
#include <sstream>

using std::list;
using std::string;

#include <cxxtest/TestSuite.h>

//------------------------------------------------------ Include personnel
#include "Provider.h"
#include "Deserialize.h"

class TestsProvider : public CxxTest::TestSuite
{
public:
    void testConstructor(void)
    {
        list<string> fields = {
			"Cleaner0"
        };
        Provider provider(fields);

        TS_ASSERT_EQUALS(provider.getCleaner(), "Cleaner0");
    }

	void testDeserialize(void)
	{
		map<string, Provider> mp = singleKeyDeserialize<Provider>("datasets/providers.csv", 0);

		// Should contains 2 different providers
		TS_ASSERT_EQUALS(mp.size(), 2);

		// Check that the providers are well deserialized
		Provider provider = mp["Provider0"];
        TS_ASSERT_EQUALS(provider.getCleaner(), "Cleaner0");
	}
};
