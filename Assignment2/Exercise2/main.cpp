//
//  main.cpp
//  interplolation
//
//  Created by Jiahui Sun on 2019/9/17.
//  Copyright © 2019 Jiahui Sun. All rights reserved.
//

#include <iostream>
using namespace std;

class NewtonInterpolation {
private:
    double x[7] = {0.1, 0.4, 1.0, 1.8, 2.9, 3.2, 3.8};
    double fx[7] = {4.2, 3.8, 2.5, 2.0, -2.0, 0.0, -0.3};
    double D[7][7] = {{0}};
    double coff[7] = {0};
    double res = 0;

public:
    void DividedDifferenceTable() {
        for(int i=0; i<7; i++) {
            D[i][0] = fx[i];
        }
        for(int i=1; i<7; i++) {
            for(int j=1; j<=i; j++) {
                D[i][j] = (D[i][j-1] - D[i-1][j-1]) / (x[i] - x[i-j]);
            }
        }
        for(int i=0; i<7; i++) {
            for(int j=0; j<=i; j++) {
                cout << D[i][j] << " ";
            }
            coff[i] = D[i][i];
            cout << endl;
        }
    }
    
    double ApproximateValue(double& newx) {
        res = 0;
        for(int i=1; i<7; i++) {
            double tmp = 1;
            for(int j=1; j<=i; j++) {
                tmp *= (newx - x[j-1]);
            }
            res += coff[i] * tmp;
        }
        return res + coff[0];
    }
};

int main() {
    NewtonInterpolation* myObj = new NewtonInterpolation();
    myObj->DividedDifferenceTable();
    double newx;
    while(cin >> newx){
        if(cin.fail())
            break;
        cout << myObj->ApproximateValue(newx) << endl;
    }
    return 0;
}
