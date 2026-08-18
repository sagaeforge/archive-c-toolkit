
#include "Command.h"

double Sqrt(int a, int b) {
	double precision = 0.00000001;
	double x = a / 2.0;
	double x2 = x * x;
	double comp_x2 = (double)a;

	while (!(comp_x2 - precision < x2 && x2 < comp_x2 + precision))
	{
		x = (x + (a / x)) / 2;
		x2 = x * x;
	}

	return x;
}