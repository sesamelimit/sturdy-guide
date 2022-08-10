#include <iostream>
#include <random>
#define rows 5
#define columns 6

unsigned int** one() {
    size_t n=rows; //высота столбца
    size_t m=columns; //длина строки
    int direction;
   /* std::cout << "input n" << std::endl;
    std::cin >> n;
    std::cout << "input m" << std::endl;
    std::cin >> m;
    std::cout << "0 for right ; 1 for left" << std::endl;
    */std::cin >> direction;

    unsigned int** A = new unsigned int* [n];
    for (size_t i = 0; i < n; i++) {
        A[i] = new unsigned int[m];
    }

    int k=1;
    for(size_t i = 0; i < n; ++i)
        if (!((i + direction) % 2))
            for(size_t j = 0;j < m;++j)
            {
                A[i][j]=k;
                ++k;
            }
        else
            for(size_t j = m - 1;j != -1;--j)
            {
                A[i][j]=k;
                ++k;
            }
    return A;

}

unsigned int** two(){
    std::random_device dev;
    std::mt19937 gen(dev());
    std::uniform_int_distribution<> distr(0, 100000);

    size_t n=rows;
    size_t m=columns;
    /*std::cout << "input n" << std::endl;
    std::cin >> n;
    std::cout << "input m" << std::endl;
    std::cin >> m;*/

    unsigned int** A = new unsigned int* [n];
    for (size_t i = 0; i < n; i++) {
        A[i] = new unsigned int[m];
    }

    for(size_t i = 0; i < n;++i)
        for(size_t j = 0;j < m;++j)
            A[i][j]=distr(gen);
    return A;
}

void snakeArray(int** A, size_t n, size_t right) { //или вправо или вниз
    int k = 1;
        for (size_t i = 0; i < n; ++i)
                for (size_t j = (n-1)*(i%2); 0 <=j && j < n; j += (-1)*(i%2) + (i+1)%2 )
                {
                    if (right) 
                        A[i][j] = k;
                    else
                        A[j][i] = k;
                    ++k;
                }
                

}

double mysqrt(double x, double eps=1e-6){
    double z_1 = 1;
    double z_2 = z_1 - (z_1 * z_1 - x) / (2 * z_1);
    while( std::abs(z_2 - z_1) > eps)
    {
        z_1 = z_2;
        z_2 = z_1 - (z_1 * z_1 - x) / (2 * z_1);
    }
    return z_2;
}

void snail(int **A, size_t n, size_t m, int dir){ // 1 - down 0 - right
    int counter = 0;
    int k = 1;
        while(k <= n*m) {
            //сверху слева направо
            for (size_t i = counter; i < dir*n + ((dir+1)%2)*m - counter; ++i)
            {
                if (dir) A[i][counter] = k;
                else A[counter][i] = k;
                ++k;
            }
            //справа сверху вниз
            for (size_t j = counter + 1; j < dir*m + ((dir + 1) % 2) *n - counter - 1; ++j) {
                if (k <= n * m){
                    if (dir) A[n - counter - 1][j] = k;
                    else A[j][m - counter - 1] = k;
                    ++k;
                }
            }
            //снизу справа налево
            for (size_t i = dir * n + ((dir + 1) % 2) * m - counter - 1; i > counter; --i) {
                if (k <= n * m){
                    if(dir) A[i][m - counter - 1] = k;
                    else A[n - counter - 1][i] = k;
                    ++k;
                }
            }
            //слева снизу вверх
            for (size_t j = dir * m + ((dir + 1) % 2) * n - counter - 1; j > counter; --j){
                if (k <= n*m){
                    if(dir) A[counter][j] = k;
                    else A[j][counter] = k;
                    ++k;
                }
            }

            ++counter;
        }
    
}

unsigned int** six(){
    std::random_device dev;
    std::mt19937 gen(dev());
    std::uniform_int_distribution<> distr(0, 100000);
    size_t n=rows;
    size_t m=columns;
   /* std::cout << "input n" << std::endl;
    std::cin >> n;
    std::cout << "input m" << std::endl;
    std::cin >> m;*/

    unsigned int** A = new unsigned int* [n];
    for (size_t i = 0; i < n; i++) {
        A[i] = new unsigned int[m];
    }
    for(size_t i = 0; i < n; ++i)
        for(size_t j = 0; j < m; ++j)
            A[i][j]=distr(gen);
    for(size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            std::cout.width(6);
            std::cout << std::right << A[i][j];
        }
        std::cout << std::endl;
    }
    return A;
}

void shiftArray(int A[], int n, int k)
{
    for (size_t t = 1; t <= k; ++t)
    {
        int temp = A[0];
        for (size_t i = 0; i < n-1; ++i)
            A[i] = A[i+1];
        A[n - 1] = temp;
    }
}

void eight(int **A, size_t n, size_t m, int dir){ //1 - down -1 - right
    int k=1;
    int c=dir;
    size_t i=0;
    size_t j=0;
    A[i][j]=k;
    ++k;
    A[n-1][m-1]=n*m; //маленький костыль чтобы не писать большой

    while (k < n * m) {
        if(dir == 1){
            if ((i + 1 < n && j - 1 < 0) || (i + 1 < n && j + 1 >= m)) {
                ++i;
                A[i][j] = k;
                ++k;
            }
            else if ((j + 1 < m && i - 1 < 0) || (j + 1 < m && i + 1 >= n)) {
                ++j;
                A[i][j] = k;
                ++k;
            }
        }

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

        if (c == 1){
            c *= -1;
            while (0 <= i - 1 && j < m - 1) {
                --i;
                ++j;
                A[i][j] = k;
                ++k;
            }
        }

        else if (c == -1){
            c *= -1;
            while (i + 1 < n && j > 0) {
                ++i;
                --j;
                A[i][j] = k;
                ++k;
            }
        }
    }
}

int main() {
    size_t n = rows;
    size_t m = columns;
    int C[rows];
    for (size_t i = 0; i < rows; ++i)
        C[i] = i;
    for (size_t i = 0; i < rows; ++i)
        std::cout << C[i]<<" ";
    std::cout << std::endl;
    shiftArray(C, n, 3);
    for (size_t i = 0; i < rows; ++i)
        std::cout << C[i];
    return 0;
}