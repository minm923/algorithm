#include <iostream>
#include <cstring>


int main(int argc, char * argv[])
{
    char str[11];// 注意是11
    strcpy(str, "0123456789");

    char str1[] = "Hello World";
    char str2[] = "Hello World";

    char* str3 = "Hello World";    
    char* str4 = "Hello World";    

    if (str1 != str2)
    {
        std::cout << "str1 != str2 " << std::endl;
    }

    if (str3 == str4)
    {
        std::cout << "str3 == str4 " << std::endl;
    }

    return 0;
}
