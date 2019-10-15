#include <iostream>
#include <math.h>
using namespace std;

// f (x) = 10x3 − 8.3x2 + 2.295x − 0.21141 = 0 has a root at x = 0.29. Use Newton’s method with an int:0.28 and 0.315
//initial approximation x0 = 0.28 to attempt to find this root. Explain what happens.
int main(void){
	double a = 10, b = -8.3, c = 2.295,d = -0.21141;
	//double x1 = 0.400912, x0 = 0.28516;
	double x1 = 0.2924,x0 = 0.28878;
	double delta,f0,f1,f2,x2;
	int i = 0;
	delta = x1 - x0;//0.315-0.28 = 0.035;

	while(delta >= 0.00001){
		f0 = a * pow(x0,3) + b * pow(x0,2) + c * x0 + d;
		f1 = a * pow(x1,3) + b * pow(x1,2) + c * x1 + d;
		x2 = (x0 + x1)/2;
		f2 = a * pow(x2,3) + b * pow(x2,2) + c * x2 + d;

		if(f0*f2<0){
			x1 = x2;
		}
		else if(f1*f2<0){
			x0 = x2;
		}
		else{
			delta = 0;
		}
		delta /=2;

		cout << "x" <<i<<": "<< x2 << endl;
		i  = i + 1; 
	}

}