#include <iostream>

int solution(int* arr, int len, int sum, int* pres1, int* pres2)
{
    if (!arr || len <=0 || !pres1 || !pres2)
        return -1;

    int first  = 0;
    int second = len-1;
    int n = 0;

    while (first < second)
    {
        n = arr[first] + arr[second];
        if (sum == n)
        {
            *pres1 = arr[first];
            *pres2 = arr[second];

            return 0;
        }
        else if (sum < n)
        {
            --second;
        }
        else
        {
            ++first;
        }
    }

    return -1;
}


int main(int argc, char* argv[])
{
    int arr[] = {1, 2, 4, 7, 11, 15};
    int sum = 15;
    int res1 = 0;
    int res2 = 0;

    int r = solution(arr, sizeof(arr)/sizeof(arr[0]), sum, &res1, &res2);
    std::cout << "res " << r << std::endl;

    std::cout << "res1 " << res1 << std::endl;
    std::cout << "res2 " << res2 << std::endl;

    return 0;
}
