#import <math.h>
#import <iostream>
using namespace std;

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



int main(){
    double x=10;
    double y=10;
    cout << sail(x,y);
    return 0;
}