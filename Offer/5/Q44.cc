#include <iostream>
#include <vector>

int solution(int * arr, int iLen)
{
    if (!arr || iLen <=0)
    {
        return 0;
    }

    std::vector<int> iv;

    for (int i=0; i<iLen; ++i)
    {
        if (arr[i]>=2 && arr[i]<=13)
        {
            iv.push_back(arr[i]);
        }
    }

    // sort

    const int iEnd = iv.size()-1;

    if (iv.size() == iv[iEnd]-iv[0])
    {
        return 1;
    }
    
    return 0;
}


int main(int argc, char* argv[])
{
    return 0;
}

