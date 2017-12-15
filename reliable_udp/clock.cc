#include <stdio.h>
#include <sys/time.h>
#include <iostream>

int main(int argc, char* argv[])
{
    struct timeval time;
    gettimeofday(&time, NULL);

    std::cout << time.tv_sec << std::endl;
    std::cout << time.tv_usec << std::endl;
    printf("%d, %d\n", time.tv_sec, time.tv_usec);

    return 0;
}
