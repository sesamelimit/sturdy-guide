#import <math.h>
#import <iostream>
using namespace std;
#define _USE_MATH_DEFINES

bool sail(double x, double y){
    if (x*x + y*y <=4 && y>=-1){
        if (y<=0){
            if ((x-1)*(x-1) + y*y <= 1 || (x+1)*(x+1)+y*y <=1)
                return true;
            else
                return false;
        }
        else
            if (-2*abs(x) + 2 >= y)
                return true;
            else
                return false;
    }
    else
        return false;

}

bool star(double x, double y){
    if (((int)(tan(72*M_PI/180)*abs(y) <= 5-x) +
    (int)(tan(72*M_PI/180)*abs(-sin(144*M_PI/180)*x+cos(144*M_PI/180)*y)<=5-cos(144*M_PI/180)*x-sin(144*M_PI/180)*y)+
    + (int)(tan(72*M_PI/180)*abs(-sin(72*M_PI/180)*x+cos(72*M_PI/180)*y)<=5-cos(72*M_PI/180)*x-sin(72*M_PI/180)*y)
    +(int)(tan(72*M_PI/180)*abs(sin(72*M_PI/180)*x+cos(72*M_PI/180)*y)<=5-cos(72*M_PI/180)*x+sin(72*M_PI/180)*y))>1)
        return true;
    else
        return false;
}
