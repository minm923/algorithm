#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Point
{
public:
    Point(int a, int b) : x(a), y(b) {}

    int getX () { return x;}
    int getY () { return y;}

private:
    int x;
    int y;
};

// 运算符也算函数的一种 这种做运算符重载
Point operator + (Point& A, Point& B)
{
    return Point(A.getX()+B.getX(), A.getY()+B.getY());    
}

// 返回的是引用 输出运算符重载
ostream& operator<<(ostream& out, Point& A)
{
    cout << A.getX() << A.getY() << endl;
    return cout;
}

int main(int argc, char * argv[])
{
    string s;

    while(getline(cin, s))
    {
        stringstream ss(s);
        int x1 = 0;
        int y1 = 0;
        int x2 = 0;
        int y2 = 0;

        ss >> x1;
        ss >> y1;
        ss >> x2;
        ss >> y2;

        Point p1(x1, y1);
        Point p2(x2, y2);
        Point p3 = p1 + p2;
        cout << p3;
    }



    return 0;    
}
