#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <iostream>
#include <math.h>

const int E = 31;
const int M = 9;

int main(int argc, char* argv[]) 
{
    int    tableA[E][M];            
    double tableB[E][M];            

    // 生成表来查询
    memset(tableA, 0, sizeof tableA);
    memset(tableB, 0, sizeof tableB);

    for (int i=1; i<E; ++i)
    {
        for (int j=0; j<=M; ++j)
        {
            double mantissa = 1 - pow(2.0, -1*i-1);// 注意是-i-1            
            double exponent = pow(2.0, j) - 1;
            double tmp = log10(mantissa) + exponent * log10(2);// log10

            tableA[i][j] = (int) tmp;
            tableB[i][j] = pow(10, tmp - tableA[i][j]);
        }
    }

    std::string s;
    std::cin >> s;
    s.replace(s.find('e'), 1, " ");
    std::stringstream ss(s);

    double a = 0;
    int    b = 0;
    ss >> a >> b;// stringstream

    //std::cout << a << ' ' << b;

    for (int i=1; i<E; ++i)
    {
        for (int j=0; j<=M; ++j)
        {
            if (b == tableA[i][j] && fabs(a-tableB[i][j]) < 1e-5)
            {
                printf("E : %d, M %d\n", i, j);
            }
        }
    }


    return 0;
}
