#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sum = 0;
int sum2 = 0;

struct Queen
{
    int x;
    int y;
    Queen(int xx, int yy) : x(xx), y(yy) {};
    bool operator==(Queen const& q) const
    {
        return (x == q.x) || (y == q.y) || (y-x == q.y-q.x) || (x+y == q.x+q.y);
    }

    bool operator!=(Queen const& q) const
    {
        return !(*this == q);
    }
};

bool IsConflictQueen(vector<Queen>& qv, Queen& q)
{    
    return (find(qv.begin(), qv.end(), q) != qv.end());
}

void PrintQueen(vector<Queen>& qv)
{
    cout << "start print queen" << endl;
    for (vector<Queen>::iterator it=qv.begin(); it!=qv.end(); ++it)
    {
        cout << "x : " << it->x << " y : " << it->y << endl;
    }
    cout << "end print queen" << endl;
    cout << endl;
}

void placeQueen(int N)
{
    vector<Queen> qv;
    Queen q(0, 0);

    while (q.x !=0 || q.y < N)
    {
        if (qv.size() < N && !IsConflictQueen(qv, q))
        {
            if (q.y < N)
            {
                qv.push_back(q);
                ++q.x;
                q.y = 0;
            }
            else
            {
                q = qv.back();
                qv.pop_back();
                ++q.y;
            }
        }
        else
        {
            if (qv.size() == N)
            {
                ++sum;
                PrintQueen(qv);
                q = qv.back();
                qv.pop_back();
                if (q.y == N-1)
                {
                    // 回溯
                    q = qv.back();
                    qv.pop_back();
                    ++q.y;
                }
                else
                {
                    // 试探
                    ++q.y;
                }
            }
            else // 冲突
            {
                if (q.y == N-1)
                {
                    // 回溯
                    q = qv.back();
                    qv.pop_back();
                    ++q.y;
                }
                else
                {
                    // 试探
                    ++q.y;
                }
            }
        }
    }
}

void placeNQueen(int N)
{
    vector<Queen> qv;
    Queen q(0, 0);

    while (q.x !=0 || q.y <N)
    {
        if (q.y >= N || qv.size() >= N)// 如果出界就需要回溯
        {
            if (qv.size() == N)
            {
                PrintQueen(qv);
                ++sum2;
            }
            // 回溯上一行
            q = qv.back();            
            qv.pop_back();
            ++q.y;
        }
        else
        {
            if (!IsConflictQueen(qv, q))
            {
                qv.push_back(q);
                // 试探下一行
                ++q.x;
                q.y = 0;
            }
            else
            {
                // 试探下一列
                ++q.y;
            }
        }
    }
}

int main(int argc, char * argv[])
{
    //placeQueen(8);    
    placeNQueen(8);    
    //cout << "sum " << sum << endl;
    cout << "sum2 " << sum2 << endl;
    return 0;
}
