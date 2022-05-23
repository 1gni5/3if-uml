//-------------------------------------------------------- Include système
#include <list>
#include <string>
#include <iostream>

using std::list;
using std::string;

#include <cxxtest/TestSuite.h>

//------------------------------------------------------ Include personnel
#include "User.h"
#include "Deserialize.h"

class TestsUser : public CxxTest::TestSuite
{
public:
    void testConstructor(void)
    {
        list<string> fields = {
			"Sensor70"
        };
        User user(fields);

        TS_ASSERT_EQUALS(user.getSensor(), "Sensor70");
    }

	void testDeserialize(void)
	{
		map<string, User> mp = singleKeyDeserialize<User>("datasets/users.csv", 0);

		// Should contains 2 different users
		TS_ASSERT_EQUALS(mp.size(), 2);

		// Check that the users are well deserialized
		User user = mp["User0"];
        TS_ASSERT_EQUALS(user.getSensor(), "Sensor70");
	}
};
