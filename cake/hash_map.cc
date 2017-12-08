//g++ -o 1 hm.cc -Wno-deprecated
#include <string>
#include <iostream>
//#include <ext/hash_map>
#include <hash_map>

//typedef __gnu_cxx::hash_map<int, std::string> playerpool;

typedef __gnu_cxx::hash_map<int, std::string> playerpool;

//typedef std::hash_map<int, std::string> playerpool;

int main(int argc, char* argv[])
{
    playerpool pool;
    pool[1] = "xxxx";
    pool[2] = "yyyy";

    std::cout <<  pool[1] << std::endl;
    std::cout <<  pool[2] << std::endl;

    return 0;
}
