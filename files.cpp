#include <iostream>
#include <fstream>
using namespace std;

int files_1(){
    char* filename = new char[255];
    cin >> filename;

    char* filename2 = new char[255];
    cin >> filename2;

    ifstream(fin);
    ofstream(fout);
    fout.open(filename2);
    fin.open(filename);

    char c;
    bool opened = false;
    while(fin.get(c))
    {
        if (c != '$')
            fout << c;
        else if(!opened){
            opened = true;
            fout << "<math>";
            fin.get(c);
            if (c!='$')
                fout << c;
        }

        else {
            opened = false;
            fout << "</math>";
            fin.get(c);
            if (c!='$')
                fout << c;
        }
    }

    fin.close();
    fout.close();

    delete[] filename;
    delete[] filename2;
    return 0;
}

int files_2(){
    char* filename = new char[255];
    cin >> filename;
    char* filename2 = new char[255];
    cin >> filename2;

    ifstream(fin);
    ofstream(fout);
    fout.open(filename2);
    fin.open(filename);

    char c;
    while(fin.get(c))
    {
        string sequence;
        fout << "00000000: ";
        for(int i = 0; i < 16; ++i)
        {
            fin.get(c);
            sequence += c;
        }

        for(int i = 0;i < 8; ++i)
        {
            if (sequence[i] < 32)
                sequence[i]=' ';
            fout << hex << (int) sequence[i] << " ";
        }

        fout << '|';

        for(int i = 8; i < 16; ++i)
        {
            if (sequence[i]<32)
                sequence[i]=' ';
            fout << hex << (int) sequence[i] << " ";
        }

        fout << '|';
        fout << sequence << endl;
    }

    fin.close();
    fout.close();
    return 0;
}