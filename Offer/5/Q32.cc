#include <iostream>
#include <limits.h>
#include <string.h>

using namespace std;

int solution(int n)
{
    if (n < 1)
        return 0;

    int round = n;
    int weight = 0;
    int count  = 0;
    int base   = 1;

    while (round > 0)
    {
        weight = round % 10;
        round  = round / 10;

        count += base * round;

        if (weight > 1)
            count += base;                        
        else if (1 == weight)
            count += n % base + 1;
        else
            count += 0;

        base *= 10;
    }

    return count;
}

int main(int argc, char* argv[])
{
    cout << solution(534) << endl;

    return 0;    
}

