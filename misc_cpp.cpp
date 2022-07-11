#include <iostream>
#include <math.h>
using namespace std;

void char_out(){
    for(unsigned char c=0; c<255; ++c)
        cout << c << "\t";
    return;
}

bool two_radiuses(double x, double y, double r, double R){
    return x*x + y*y < R*R && x*x + y*y > r*r; //допустим кольцо открытое
}

double bij(double a, double b, double c, double d, double x){
   double t = (x-b)/(a-b);
   return t*c + (1-t)*d;
}

void graph() {
    int height=21;
    int width=41;
    bool map[height][width];
    int c=0;
    for(double x=-1.5; x<=1.5; x += 3.0/40) {
        cout << x << " " << endl;
        ++c;
        int c_2=0;
        for (double y = 1.5; y >= -1.5; y -= 3.0 / 20){
            map[c_2][c]=((x*x + y*y - 1)*(x*x + y*y - 1)*(x*x + y*y - 1) - x*x*y*y*y <= 0);
            ++c_2;}
    }
    for(int i=0;i<height;++i)
    {for (int j=0; j<width;++j)
            if (map[i][j]) cout << "*";
            else cout << " ";
        cout << endl;
    }
}

unsigned long dots(double R)
{
    unsigned long c=0;
    for(long x=-(int)R; x<=(int)R;++x)
    {
        for(long y=-(int)sqrt(R*R-x*x); y<=(int)sqrt(R*R-x*x);++y)
            if ((x*x +y*y) <= R*R)
                ++c;}
    return c;
}

void foobar(){
    for(int i=1;i<=100;++i) {
        if (i % 3 == 0)
            cout << "Foo";
        if (i % 5 == 0)
            cout << "Bar";
        if (i%3 !=0 && i%5 !=0)
            cout << i;
        cout << endl;
    }
}


int main() {
    foobar();
    return 0;
}