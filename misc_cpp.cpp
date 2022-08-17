#include <iostream>
#include <math.h>
using namespace std;

void char_out(){
    unsigned char c=0;
    do {
        cout << (int)c << "\t";
        ++c;
    }
    while (c!=0);

    return;
}

bool two_radiuses(double x, double y, double r, double R){
    return x*x + y*y < R*R && x*x + y*y > r*r; //допустим кольцо открытое
}

double bij(double a, double b, double c, double d, double x){
   double t = (x-b) / (a-b);
   return t * c + (1-t) * d;
}

void graph() {
    int height = 21;
    int width = 41;
    bool map[height][width];
    int c = 0;
    for(double x = -1.5; x <= 1.5; x += 3.0 / 40) {
        ++c;
        int c_2=0;
        for (double y = -1.5; y <= 1.5 && c_2<20; y += 3.0 / 20){
            map[c_2][c] = ((x*x + y*y - 1) * (x*x + y*y - 1) * (x*x + y*y - 1) - x * x * y * y * y <= 0);
            ++c_2;
        }
    }
    for(int i = 0; i < height; ++i){
        for (int j = 0; j < width; ++j)
            if (map[i][j]) cout << "*";
            else cout << " ";
        cout << endl;
    }
}

unsigned long dots(double R)
{
    unsigned int sum=2;
    for(double y=R; y>-R; --y)
        sum+=(unsigned int)(2*sqrt(R*R-y*y));
    return sum;
}

void foobar(){
    for(int i = 1; i <= 100; ++i) {
        if (i % 3 == 0)
            cout << "Foo";
        if (i % 5 == 0)
            cout << "Bar";
        if (i % 3 != 0 && i % 5 != 0)
            cout << i;
        cout << endl;
    }
}