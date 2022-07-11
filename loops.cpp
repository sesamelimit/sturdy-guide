#include <iostream>
#include <math.h>
using namespace std;



void taylor(double x_1,double x_2, double dx, double eps){
    cout << "x" << "\t" << "f(x)" <<  "\t" << "sin(x)" << endl;
    for(double x = x_1; x <= x_2; x += dx){
        double f = x;
        double f_i = x;
        int c=1;
        while(abs(f - sin(x)) >= eps)
        {
            f_i = f_i * x * x * (-1) / ((c+1) * (c+2));
            f += f_i;
            c+=2;
        }
        cout << x << "\t" << f << "\t" << sin(x) << endl;
    }
}
