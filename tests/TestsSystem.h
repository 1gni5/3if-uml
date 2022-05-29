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

class TestsSystem : public CxxTest::TestSuite
{
public:
    void testConstructor(void)
    {
        System system = System(); 
    }
};
