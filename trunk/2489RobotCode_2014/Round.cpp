#include <math.h>
#include "round.h"
double round(double d, double c){
	double x = d/c;
	x = (int)x;
	return x*c;
}
