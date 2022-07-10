#include <iostream>
#import <math.h>
using namespace std;
double** dyn_array(size_t rows, size_t columns){
    double** C=new double*[rows];
    for(int i = 0; i < rows; i++){
        C[i] = new double[columns];
    }
    return C;
}

void dyn_array_destroy(double** M,size_t rows){
    for (int i = 0; i < rows; ++i)
        delete[] M[i];
    delete[] M;
}

void print_matrix(double **M, size_t rows, size_t columns){
    for(int i=0;i<rows;++i)
    {for(int j=0;j<columns;++j)
            cout << M[i][j] << "\t";
        cout << endl;}
}

double** multMatrix(double lambda, double** M, size_t rows, size_t columns)
{

for(int i=0;i<rows;++i)
    for(int j=0;j<columns;++j)
        M[i][j]=lambda*M[i][j];
return M;
}

double** plusMatrix(double** A, double** B, size_t rows, size_t columns){
    double** C=new double*[rows];
    for(int i = 0; i < rows; i++){
        C[i] = new double[columns];
    }

    for(int i=0;i<rows;++i)
        for(int j=0;j<columns;++j)
            C[i][j]=A[i][j]+B[i][j];
    return C;
}

double** minusMatrix(double** A, double** B, size_t rows, size_t columns){
    double** C=new double*[rows];
    for(int i = 0; i < rows; i++){
        C[i] = new double[columns];
    }

    for(int i=0;i<rows;++i)
        for(int j=0;j<columns;++j)
            C[i][j]=A[i][j]-B[i][j];
    return C;

}

double** multMatrix(double** A, double** B, size_t rowsA, size_t columnsA, size_t columnsB){
    double** C=new double*[rowsA];
    for(int i = 0; i < rowsA; i++){
        C[i] = new double[columnsB];
    }
    for(int i=0;i<rowsA;++i)
        for(int j=0;j<columnsB;++j)
            C[i][j]=0;

    for(int i=0;i<rowsA;++i)
        for(int j=0;j<columnsB;++j)
            for(int k=0; k<columnsA; ++k)
            C[i][j]+=A[i][k]*B[k][j];
    return C;
}

double& maximumMatrix(double** M, size_t rows, size_t columns){
    int max_i=0,max_j=0;
    double max=M[0][0];
    for(int i=0;i<rows;++i)
        for(int j=0;j<columns;++j)
            if (M[i][j]>max)
            {max=M[i][j];max_i=i;max_j=j;}
    return M[max_i][max_j];
}

double& minmaxMatrix(double** M, size_t rows, size_t columns){
    double min[rows];
    int min_j[rows];
    for (int i=0;i<rows;++i)
    {min[i]=M[i][0]; min_j[i]=0;
    for(int j=1;j<columns;++j)
        if (M[i][j]<min[i]) {min[i]=M[i][j]; min_j[rows]=j;}
    }
    double max=min[0]; int max_j;int max_i;
    for (int i=1;i<rows;++i)
        if (max<min[i]) {max=min[i]; max_i=i;max_j=min_j[i];}
    return M[max_i][max_j];
}

void mixMatrix(double** M, size_t rows, size_t columns, size_t K_1, size_t K_2)
{
    double temp;
    for(int i=0;i<columns;++i)
    {
        temp=M[K_1][i];
        M[K_1][i]=M[K_2][i];
        M[K_2][i]=temp;
    }
}

void localMinimum(double** M, size_t rows, size_t columns);

double det(double** M, size_t size){
    if (size==2)
        return M[0][0]*M[1][1] - M[0][1]*M[1][0];
    double d=0;

    for(size_t n=0;n<size;++n){
        if (M[0][n]!=0) {
            auto minor = dyn_array(size - 1, size - 1);
            for (int i = 0; i < size - 1; ++i)
                for (int j = 0; j < size; ++j)
                    if (j < n)
                        minor[i][j] = M[i + 1][j];
                    else if (j > n)
                        minor[i][j] = M[i + 1][j - 1];

            d += pow(-1, 1 + n) * M[0][n] * det(minor, size - 1);
            dyn_array_destroy(minor,size-1);
        }
    }

    return d;
}


int main(){
    size_t columnsA=4; size_t rowsA=3;
    double** A=new double*[rowsA];
    for(int i = 0; i < rowsA; i++){
        A[i] = new double[columnsA];
    }

    for(int i=0;i<rowsA;++i)
        for(int j=0;j<columnsA;++j)
        A[i][j]=i+j+5;

    A[1][2]=-7;

    for(int i=0;i<rowsA;++i)
    {for(int j=0;j<columnsA;++j)
            cout << A[i][j] << "\t";
        cout << endl;}

   localMinimum(A,rowsA,columnsA);

    for(int i=0;i<rowsA;++i)
    {for(int j=0;j<columnsA;++j)
            cout << A[i][j] << "\t";
        cout << endl;}

    cout << endl;

    for (int i = 0; i < rowsA; ++i)
        delete[] A[i];
    delete[] A;

    return 0;
}