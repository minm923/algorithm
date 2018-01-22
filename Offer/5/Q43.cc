#include <iostream>
#include <math.h>

void solution(int n)
{
    int L1    = 1 * n;
    int R1    = L1 + 5;
    int R2    = 6 * n;
    int L2    = R2 - 5;
    const double Sum   = 6 * (R2 - R1 + 1);
    std::cout << "Sum " << Sum << std::endl;
    double Count = 0;
    double rate  = 0;

    for (int i=L1; i<=R2; ++i)
    {
        if (1 == n)
        {
           Count = 1; 
        }
        else
        {
            if (i<R1)
            {
                Count = i - L1 + 1;
            }
            else if (i>=R1 && i<=L2)
            {
                Count = 6;
            }
            else
            {
                Count = R2 - i + 1;
            }
        }

        rate = Count / Sum;
        std::cout << "num : " << i << ", rate: "<< rate << std::endl;
    }
}

int main(int argc, char* argv[])
{
    solution(6);

    return 0;
}

