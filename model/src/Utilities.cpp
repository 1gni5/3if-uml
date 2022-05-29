#include <sstream>
#include "Utilities.h"

using std::ostringstream;

time_t parseDateTime(string fdate, string fmt)
{
    tm time;
    strptime(fdate.c_str(), fmt.c_str(), &time);
    return mktime(&time);
}

string toString(size_t value)
{
    std::ostringstream oss;
    oss << value;
    return oss.str();
}