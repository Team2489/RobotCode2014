#include "AngleReader.h"
#include <math.h>
#include "Round.h"
const double PI  =3.141592653589793238462;
	
AngleReader::AngleReader(ADXL345_2489 *accelramotor, int wind){
	m_accelramotor = accelramotor;
	baseAngle = getAngleAbsoulute();
	currind = 0;
	// array = new double[wind];
	window = wind;
}

double AngleReader::getAngleAbsoulute(){
	ADXL345_2489::AllAxes accels = m_accelramotor->GetAccelerations();
	double h = sqrt(accels.XAxis*accels.XAxis + accels.YAxis*accels.YAxis + accels.ZAxis*accels.ZAxis);
	double r; 
	if(h == 0){
		 r = 0;
	}
	else{
		 r = (acos(- accels.ZAxis/h)*180)/PI;
	}
	// array[currind%window] = r;
	currind += 1;
//	cout << "r = " << r << endl;
	return r;
}
double AngleReader::getAngleAbsouluteRound(){
	return round(getAngleAbsoulute(), 1);
}

double AngleReader::getAngleAbsouluteAverage(){
#if 0
	int i;
	double sum = 0;
	getAngleAbsoulute();
	for(i = 0; i < window; i++) {
		sum += array[i]; 
	}
	double average = sum/window;
	return average;
#else
	return getAngleAbsoulute();
#endif
}
int AngleReader::getAngle(){
	return (int) (getAngleAbsoulute()-baseAngle);
}
