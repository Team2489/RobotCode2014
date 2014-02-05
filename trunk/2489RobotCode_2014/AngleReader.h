#ifndef __AngleReader_h__
#define __AngleReader_h__
#include "WPILib.h"
#include "ADXL345_2489.h"


class AngleReader{
private:

	ADXL345_2489 *m_accelramotor;
	double baseAngle;
	double *array;
	int currind;
	int window;
	
	
public:
	AngleReader(ADXL345_2489 *, int);
	double getAngleAbsoulute();
	double getAngleAbsouluteRound();
	double getAngleAbsouluteAverage();
	int getAngle();
};
#endif
