#include <iostream>
#include <math.h>
using namespace std;

// f (x) = 10x3 − 8.3x2 + 2.295x − 0.21141 = 0 has a root at x = 0.29. Use Newton’s method with an int:0.28 and 0.315
//initial approximation x0 = 0.28 to attempt to find this root. Explain what happens.
int main(void){
	double a = 10, b = -8.3, c = 2.295,d = -0.21141;
	double a_diff = 30, b_diff = -16.6, c_diff = 2.295;
	//double x0 = 0.343036;
	double x0 = 0.29059;
	double delta,f0,f0_diff;

	delta = 1;
	

	while(delta >= 0.00001){
		cout << x0 <<","; 
		f0 = a * pow(x0,3) + b * pow(x0,2) + c * x0 + d;
		f0_diff = a_diff * pow(x0,2) + b_diff * pow(x0,1) + c_diff;

		//delta = 0;
		delta = f0/f0_diff;
		x0 = x0 - delta;
	}
	cout << x0 <<endl; 
}