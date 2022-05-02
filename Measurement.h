#if ! defined ( MEASUREMENT_H )
#define MEASUREMENT_H


class Measurement{

public:

Measurements();
Measurements(DateTime timeStamp, long Value);
~Measurements();


DateTime Measurement::getTimeStamp();
void Measurement::setTimeStamp(dateTime newTimeStamp);
long Measurement::getValue();
void Measurement::setValue(long newValue)


private:
DateTime timeStamp;
long value;
};
#endif //Measurement_H
