#include <iostream>
#include "solve.h"
#include "error.h"
using namespace std;

int main() {
    double a, b, c;
    vector<double> res;
    cin >> a >> b >> c;
	if(cin.fail() || a == 0) {
		cout << "Illegal inputs!" << endl;
		return(0);
	}
    try {
        res = solve(a, b, c);
        cout << res[0] << " " << res[1] << endl;
    }
    catch(exception& e) {
        cout << e.what() << endl;
        //cerr << "(b*b - 4*a*c) is less than zero" << endl;
    }
    return(0);
}

