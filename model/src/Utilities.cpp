#include "Utilities.h"

time_t parseDateTime(string fdate, string fmt)
{
    tm time;
    strptime(fdate.c_str(), fmt.c_str(), &time);
    return mktime(&time);
}