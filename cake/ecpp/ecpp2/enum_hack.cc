#include <iostream>

enum PERSONALITY {age, level, skill};
const PERSONALITY PERSONALITY_MIN  = age;
const PERSONALITY PERSONALITY_MAX  = skill;
const int PERSONALITY_SIZE         = PERSONALITY_MAX +1;

int Arr[PERSONALITY_SIZE];

int main(int argc, char* argv[])
{
    Arr[age]   = 18;
    Arr[level] = 18;
    Arr[skill] = 20;

    for (int i=0; i<PERSONALITY_SIZE; ++i)
    {
        std::cout << Arr[i] << std::endl;
    }

    return 0;    
}

