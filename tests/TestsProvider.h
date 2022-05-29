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
#include "Cleaner.h"
#include "Model.h"

class TestsProvider : public CxxTest::TestSuite
{
public:

	void setUp()
    {
        Model<Cleaner>::populate("datasets/cleaners.csv");
    }

    void testConstructor(void)
    {
        list<string> fields = {
			"Provider0",
			"Cleaner0"
		};
		Provider provider(fields);

		TS_ASSERT_EQUALS(provider.getUnique(), "Provider0");
		TS_ASSERT_EQUALS(provider.getCleaner().getUnique(), "Cleaner0");
		TS_ASSERT_EQUALS((int) provider.getCleaner().getLatitude(), 45);
		TS_ASSERT_EQUALS((int) provider.getCleaner().getLongitude(), 1);
	}

	void testModel(void)
	{
		Model<Provider>::populate("datasets/providers.csv");
		TS_ASSERT_EQUALS(Model<Provider>::getAll().size(), 2);
	}
};
