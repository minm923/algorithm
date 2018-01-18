#include <iostream>
#include <map>

int main(int argc, char* argv[])
{
    std::map<int, int> im;
    im[0] = 1;
    im[1] = 1;
    im[2] = 1;
    im[3] = 1;
    im[4] = 1;


    for (std::map<int, int>::iterator it=im.begin();
        it!=im.end();)
    {
        if (0 == (it->first)%2)
        {
            im.erase(it++);
        }
        else
        {
            ++it;
        }
    }

    for (std::map<int, int>::iterator it=im.begin();
        it!=im.end(); ++it)
    {
        std::cout << it->first << " " << it->second <<std::endl;
    }

    return 0;
}

