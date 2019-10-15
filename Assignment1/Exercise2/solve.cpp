#include <cmath>
#include "solve.h"
#include "error.h"

vector<double> solve(double a, double b, double c) {
	double delta = b*b - 4*a*c;
	vector<double> x;
	if(delta < 0) {
		throw BadValue();
	} else {
		x.push_back((-b + sqrt(delta)) / 2*a);
		x.push_back((-b - sqrt(delta)) / 2*a);
	}
	return(x); 
}
