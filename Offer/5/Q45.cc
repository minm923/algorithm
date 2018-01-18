#include <iostream>
#include <vector>

void solution(std::vector<int>& iv, const int num)
{
    while (iv.size()>1)
    {
        if (iv.size() >= num)
        {
            std::vector<int>::iterator iter = iv.begin() + num -1;
            std::cout << "Del " << *iter << std::endl;
            iv.erase(iter);
        }
        else
        {
            const int iDel = num % iv.size();
            std::vector<int>::iterator iter2 = iv.begin() + iDel -1;
            std::cout << "Del " << *iter2 << std::endl;
            iv.erase(iter2);
        }
    }

    std::cout << iv[0] << std::endl;
}

int main(int argc, char* argv[])
{
    std::vector<int> iv;

    iv.push_back(0);
    iv.push_back(1);
    iv.push_back(2);
    iv.push_back(3);
    iv.push_back(4);

    solution(iv, 3);

    return 0;
}

