#include <iostream>

char GetOneChar()
{
    char a = 'a';
    return a;
}

int main(int argc, char* argv[])
{
    GetOneChar() = 'c';

    return 0;    
}
