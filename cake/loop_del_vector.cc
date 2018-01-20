#include <iostream>
#include <vector>


int main(int argc, char* argv[])
{
    std::vector<int> iv;
    iv.push_back(0);
    iv.push_back(1);
    iv.push_back(2);
    iv.push_back(4);
    iv.push_back(4);
    iv.push_back(5);
    iv.push_back(6);
    iv.push_back(7);
    iv.push_back(8);


    for (std::vector<int>::iterator it=iv.begin();
        it != iv.end(); )
    {
        if (0 == (*it)%2)
        {
            it = iv.erase(it);
        }
        else
        {
            ++it;
        }
    }

    for (std::vector<int>::iterator it=iv.begin();
        it != iv.end(); ++it)
    {
        std::cout << *it << std::endl;
    }


    return 0;
}
