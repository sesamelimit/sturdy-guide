#include <iostream>
using namespace std;

void one(){
    int x;
    cin >> x;
    if(x<27)
        for(int i=1; i<x;++i) {
            for (int j = 0; j < i; ++j)
                cout << '*';
            cout << endl;
        }
}

void two(){
    int x;
    cin >> x;
    for(int i=0;i<x;++i) {
        for (int j = x - i; j > 0; --j)
            cout << " ";
        for (int j = 0; j < i; ++j)
            cout << "*";
        cout << "*";
        for (int j = 0; j < i; ++j)
            cout << "*";
        for (int j = x - i; j > 0; --j)
            cout << " ";
        cout << endl;
    }
}

void three(){
    int x;
    cin >> x;
    if(x==1) {
        cout << "*" << endl;
        return;
    }
    int i=0;
    int sgn=1;
    do{
        for (int j = x - i; j > 0; --j)
            cout << " ";
        for (int j = 0; j < i; ++j)
            cout << "*";
        cout << "*";
        for (int j = 0; j < i; ++j)
            cout << "*";
        for (int j = x - i; j > 0; --j)
            cout << " ";
        cout << endl;
        if (i/(x-1)==1 && sgn==1)
            sgn=-1;
        i=i+sgn;
    } while(i>=0);
}

void four(){
    int x;
    int y;
    cin >> x;
    cin >> y;
    if(x==1) {
        cout << "*" << endl;
        return;
    }
    int i=0;
    int sgn=1;
    do{
        for(int k=0;k<y;++k){
        for (int j = x - i; j > 0; --j)
            cout << " ";
        for (int j = 0; j < i; ++j)
            cout << "*";
        cout << "*";
        for (int j = 0; j < i; ++j)
            cout << "*";
        for (int j = x - i; j > 0; --j)
            cout << " ";}
        cout << endl;
        if (i/(x-1)==1 && sgn==1)
            sgn=-1;
        i=i+sgn;
    } while(i>=0);
}

void five() {
    int x;
    cin >> x;
    if(x==1) {
        cout << "*" << endl;
        return;
    }
    int i=0;
    int sgn=1;
    do{
        for (int j = x - i; j > 0; --j)
            cout << " ";
        for (int j = 0; j < i/2; ++j)
            cout << "* ";
        cout << "* ";
        for (int j = 0; j < i/2; ++j)
            cout << "* ";
        if (i%2==1)
            cout << "*";
        for (int j = x - i; j > 0; --j)
            cout << " ";
        cout << endl;
        if (i/(x-1)==1 && sgn==1)
            sgn=-1;
        i=i+sgn;
    } while(i>=0);
}

void six(){
    int x;
    cin >> x;
    if(x==1) {
        cout << "*" << endl;
        return;
    }
    int i=0;
    int sgn=1;
    do{
        for (int j = x - i; j > 0; --j)
            cout << " ";
        cout << "*";

        for (int j = 1; j < i; ++j)
            cout << " ";
        cout << " ";
        for (int j = 1; j < i; ++j)
            cout << " ";

        if (i!=0) cout << "*";
        for (int j = x - i; j > 0; --j)
            cout << " ";
        cout << endl;

        if (i/(x-1)==1 && sgn==1)
            sgn=-1;
        i=i+sgn;
    } while(i>=0);
}

