
#if ! defined UTILITIES_H
#define UTILITIES_H

#include <string>
#include <cmath>

using std::string;
using std::pair;

time_t parseDateTime(string fdate, string fmt);
inline double distance(pair<double, double> p1, pair<double, double> p2) {
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}
#endif