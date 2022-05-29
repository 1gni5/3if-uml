#if ! defined UTILITIES_H
#define UTILITIES_H

#include <string>
using std::string;

time_t parseDateTime(string fdate, string fmt);
string toString(size_t value);

#endif