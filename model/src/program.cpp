//-------------------------------------------------------- Include système
#include <iostream>
#include "System.h"
using namespace std;
//------------------------------------------------------ Include personnel

int main(int argc, char *argv[])
{
    cout << "hello wrld " << endl;
    System sys = System();
    time_t date;
    sys.ComputeAirQuality(44.0, -1.0, date);
    cout << "hello wrld " << endl;
    return 0;
}