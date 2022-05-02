#if ! defined CLEANER_H
#define CLEANER_H

#include <ctime>

typedef struct {
    long longitude;
    long latitude;
} coord_t;

class Cleaner
{
public:
    Cleaner();
    ~Cleaner();
private:
    long cleanerID;
    coord_t location;
    t_time start;
    t_time stop;
};

#endif