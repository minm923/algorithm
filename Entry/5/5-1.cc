#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char * argv[])
{
    string line;
    while (getline(cin, line))// 读取一行数据到字符串
    {
        int sum = 0;
        int x = 0;

        stringstream ss(line);// 把字符串变成流
        while (ss >> x)// 读流
        {
            sum += x;
        }

        cout << sum << endl;
    }

    return 0;    
}
