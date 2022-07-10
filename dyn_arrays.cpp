#include <iostream>
using namespace std;
#include <random>

void one() {
    int n; //высота столбца
    int m; //длина строки
    int direction;
    cout << "input n and m" << endl;
    cin >> n;
    cin >> m;
    cout << "0 for right ; 1 for left" << endl;
    cin >> direction;
    int A[n][m];
    int k=1;
    for(int i=0; i<n; ++i)
        if (!((i+direction)%2))
            for(int j=0;j<m;++j) {
                A[i][j]=k;
                ++k;}
        else
            for(int j=m-1;j>=0;--j) {
                A[i][j]=k;
                ++k;
            }

}

void two(){
    random_device dev;
    mt19937 gen(dev());
    uniform_int_distribution<> distr(0, 100000);

    int n;
    int m;
    cout << "input n and m" << endl;
    cin >> n;
    cin >> m;
    unsigned int A[n][m];
    for(int i=0; i<n;++i)
        for(int j=0;j<m;++j)
            A[i][j]=distr(gen);
    for(int i=0; i<n;++i) {
        for (int j = 0; j < m; ++j)
            cout << "\t" << A[i][j];
        cout << endl;
    }
}

void snakeArray(int** A, int n, int right) { //или вправо или вниз
    int k = 1;
    if (right){
        for (int i = 0; i < n; ++i)
            if (!(i % 2))
                for (int j = 0; j < n; ++j) {
                    A[i][j] = k;
                    ++k;
                }
            else
                for (int j = n - 1; j >= 0; --j) {
                    A[i][j] = k;
                    ++k;
                }
    }
    else
        for(int j=0; j<n; ++j)
            if (!(j%2))
                for(int i=0;i<n;++i) {
                    A[i][j] = k;
                    ++k;
                }
            else
                for(int i=n-1;i>=0;--i) {
                    A[i][j]=k;
                    ++k;
                }
}

double mysqrt(double x, double eps=1e-6){
    double z_1=1;
    double z_2=z_1-(z_1*z_1-x)/(2*z_1);
    while(abs(z_2-z_1)>eps){
        z_1=z_2;
        z_2=z_1-(z_1*z_1-x)/(2*z_1);
    }
    return z_2;
}

void snail(int **A, int n, int m, int dir){ // 1 - down 0 - right
    int counter=0;
    int k=1;
    if (dir)
        while(k<=n*m) {
            //сверху слева направо
            for (int i = counter; i < n - counter; ++i) {
                A[i][counter] = k;
                ++k;
            }
            //справа сверху вниз
            for (int j = counter + 1; j < m - counter - 1; ++j) {
                if (k<=n*m){
                    A[n - counter - 1][j] = k;
                    ++k;}
            }
            //снизу справа налево
            for (int i = n - counter - 1; i > counter; --i) {
                if (k<=n*m){
                    A[i][m - counter - 1] = k;
                    ++k;}
            }
            //слева снизу вверх
            for (int j = m - counter - 1; j > counter; --j){
                if (k<=n*m){
                    A[counter][j] = k;
                    ++k;
                }
            }
            ++counter;
        }
    else
        while(k<=n*m) {
            //сверху слева направо
            for (int j = counter; j < m - counter; ++j) {
                A[counter][j] = k;
                ++k;
            }
            //справа сверху вниз
            for (int i = counter + 1; i < n - counter - 1; ++i) {
                if (k<=n*m){
                    A[i][m - counter - 1] = k;
                    ++k;}
            }
            //снизу справа налево
            for (int j = m - counter - 1; j > counter; --j) {
                if (k<=n*m){
                    A[n - counter - 1][j] = k;
                    ++k;}
            }
            //слева снизу вверх
            for (int i = n - counter - 1; i > counter; --i){
                if (k<=n*m){
                    A[i][counter] = k;
                    ++k;
                }
            }
            ++counter;
        }
}

void six(){
    random_device dev;
    mt19937 gen(dev());
    uniform_int_distribution<> distr(0, 100000);
    int n;
    int m;
    cout << "input n and m" << endl;
    cin >> n;
    cin >> m;
    unsigned int A[n][m];
    for(int i=0; i<n;++i)
        for(int j=0;j<m;++j)
            A[i][j]=distr(gen);
    for(int i=0; i<n;++i) {
        for (int j = 0; j < m; ++j) {
            std::cout.width(6);
            std::cout << std::right << A[i][j];
        }
        cout << endl;
    }
}

void shiftArray(int A[], int n, int k)
{
    int temp[k];
    for(int i=0;i<k;++i)
        temp[i]=A[i];

    for(int i=0;i<n-k;++i)
        A[i]=A[i+k];
    for(int i=0;i<k;++i)
        A[n-k+i]=temp[i];
    for(int i=0;i<n;++i)
        cout << A[i] << " ";
}

void eight(int **A, int n, int m, int dir){ //1 - down -1 - right
    int k=1;
    int c=dir;
    int i=0;int j=0;
    A[i][j]=k;++k;
    A[n-1][m-1]=n*m; //маленький костыль чтобы не писать большой
    while (k < n * m) {
        if(dir==1){
            if ((i + 1 < n && j - 1 < 0) || (i + 1 < n && j + 1 >= m)) {
                ++i;
                A[i][j] = k;
                ++k;
            } else if ((j + 1 < m && i - 1 < 0) || (j + 1 < m && i + 1 >= n)) {
                ++j;
                A[i][j] = k;
                ++k;
            }}
        else {
            if ((j + 1 < m && i - 1 < 0) || (j + 1 < m && i + 1 >= n)) {
                ++j;
                A[i][j] = k;
                ++k;
            }
            else if ((i + 1 < n && j - 1 < 0) || (i + 1 < n && j + 1 >= m)) {
                ++i;
                A[i][j] = k;
                ++k;
            }
        }
        if (c==1){c=c*(-1);
            while (0 <= i - 1 && j < m - 1) {
                --i;
                ++j;
                A[i][j] = k;
                ++k;
            }
        }
        else if (c==-1){  c=c*(-1);
            while (i + 1 < n && j > 0) {
                ++i;
                --j;
                A[i][j] = k;
                ++k;

            }}

    }
}
