#include <iostream>
#include <map>
#include <set>


using namespace std;

void solution(const char* arr, int iLen)
{
    map<char, int> mc;

    for (int i=0; i<iLen; ++i)
    {
        char tmp = *(arr+i);
        if (!mc.count(tmp))
        {
            mc[tmp] = 1;
        }
        else
        {
            mc[tmp] += 1;
        }
    }

    for (int i=0; i<iLen; ++i)
    {
        char tmp = *(arr+i);
        if (mc[tmp] == 1)
        {
            cout <<  tmp << endl;
            break;
        }
    }


}

int main(int argc, char* argv[])
{
    const char * arr = "abaddc";

    solution(arr, 6);    

    return 0;
}
