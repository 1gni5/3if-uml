#if ! defined ( MEASUREMENT_H )
#define MEASUREMENT_H


class Measurement{

public:

Measurement();
Measurement(DateTime timeStamp, long Value);
~Measurement();


DateTime Measurement::getTimeStamp();
void Measurement::setTimeStamp(dateTime newTimeStamp);
long Measurement::getValue();
void Measurement::setValue(long newValue)


private:
DateTime timeStamp;
long value;
};
#endif //Measurement_H
