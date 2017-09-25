#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <set>
#include <queue>
#include <map>

// 队列练习

const int TEAM_NUM = 1000;

using namespace std;

map<int, int> PlayerIDMapTeamID;

int main(int argc, char * argv[])
{
    int n = 0;
    cin >> n;   
    for (int i=0; i<n; ++i)
    {
        int iPlayerNum = 0;        
        cin >> iPlayerNum;
        for (int j=0; j<iPlayerNum; ++j)
        {
            int iPlayerID = 0;
            cin >> iPlayerID;
            PlayerIDMapTeamID[iPlayerID] = i;
        }
    }

    queue<int> TeamQueue;
    queue<int> Team[TEAM_NUM];

    string op;    
    while(cin >> op)        
    {
        if ('E' == op[0])
        {
            int iPlayerID = 0;
            cin >> iPlayerID;
            int iTeamID = PlayerIDMapTeamID[iPlayerID];

            if (Team[iTeamID].empty())
            {
                TeamQueue.push(iTeamID);
            }

            Team[iTeamID].push(iPlayerID);
        }
        else if ('D' == op[0])
        {
            const int iTeamID   = TeamQueue.front();
            const int iPlayerID = Team[iTeamID].front();
            cout << iPlayerID << endl;

            Team[iTeamID].pop();
            if (Team[iTeamID].empty())
            {
                TeamQueue.pop();
            }
        }
        else
        {
            break;
        }
    }

    // printf
    

    return 0;    
}

