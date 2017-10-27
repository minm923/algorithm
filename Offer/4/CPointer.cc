#include <iostream>

#define N  2
#define M  2 

void Solution(int** number, int n, int m)
{
    std::cout << number[0][0] << std::endl;
}

int main(int argc, char* argv[])
{
    int arr0[M] = {1,2};
    int arr1[M] = {3, 4};
    int arr2[N][M] ={{1,2},{3,4}};
    int* arr3[N] = {arr0, arr1};


    Solution(arr3, 0, 0);
    Solution(arr4, 0, 0);


    return 0;        
}



