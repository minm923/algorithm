#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstdio>

using namespace std;

const int N = 30;
vector<int> pile[N];
int iPileNum = 0;

int find_box_in_which_pile(int box)
{
    for (int i=0; i<iPileNum; ++i)
    {
        vector<int>::iterator it = find(pile[i].begin(), pile[i].end(), box);
        if (it != pile[i].end())
        {
            return i;
        }
    }

    printf("ERROR NOT FIND BOX %d\n", box);
}

void revert_position(const int box, const int pilenum)
{
    vector<int>::iterator it = find(pile[pilenum].begin(), pile[pilenum].end(), box);
    if (it != pile[pilenum].end())
    {
        for (vector<int>::iterator itt = it+1; itt != pile[pilenum].end(); ++itt)        
        {
            const int boxnum = *itt;
            pile[boxnum].push_back(boxnum);
        }

        pile[pilenum].erase(it+1, pile[pilenum].end());
    }
}

void printPile()
{
    for (int i=0; i<iPileNum; ++i)
    {
        cout << i << ":"; 
        for (vector<int>::iterator it = pile[i].begin(); it != pile[i].end(); ++it)
        {
            cout << " " << *it;
        }
        cout << endl;
    }
}

void move_a_onto_b(const int abox, const int apilenum, const int bbox, const int bpilenum)
{
    revert_position(abox, apilenum);
    revert_position(bbox, bpilenum);

    pile[apilenum].pop_back();
    pile[bpilenum].push_back(abox);
}

void move_a_over_b(const int abox, const int apilenum, const int bbox, const int bpilenum)
{
    revert_position(abox, apilenum);

    pile[apilenum].pop_back();
    pile[bpilenum].push_back(abox);
}

void pile_a_onto_b(const int abox, const int apilenum, const int bbox, const int bpilenum)
{
    revert_position(bbox, bpilenum);

    vector<int>::iterator it = find(pile[apilenum].begin(), pile[apilenum].end(), abox);

    if (it != pile[apilenum].end())
    {
        for(vector<int>::iterator itt=it; itt != pile[apilenum].end(); ++itt)
        {
            pile[bpilenum].push_back(*itt);
        }
        
        pile[apilenum].erase(it, pile[apilenum].end());
    }

}

void pile_a_over_b(const int abox, const int apilenum, const int bbox, const int bpilenum)
{
    vector<int>::iterator it = find(pile[apilenum].begin(), pile[apilenum].end(), abox);

    if (it != pile[apilenum].end())
    {
        for(vector<int>::iterator itt=it; itt != pile[apilenum].end(); ++itt)
        {
            pile[bpilenum].push_back(*itt);
        }
        
        pile[apilenum].erase(it, pile[apilenum].end());
    }
}

int main(int argc, char * argv[])
{
    cin >> iPileNum;

    if (iPileNum > 30)
    {
        cout << "iPileNum too large " << iPileNum << endl;
    }

    for (int i=0; i<iPileNum; ++i)
    {
        pile[i].push_back(i);
    }

    getchar();

    string ins;
    while (getline(cin, ins))
    {
        if (ins != "quit")
        {
            string action;
            int abox;
            string where;
            int bbox;
            stringstream  ss(ins);
            ss >> action >> abox >> where >> bbox;
            const int apilenum = find_box_in_which_pile(abox);
            const int bpilenum = find_box_in_which_pile(bbox);
            if (abox == bbox || apilenum == bpilenum)            
            {
                continue;                
            }
            else
            {
                if (action == "move" && where == "onto")
                {
                    move_a_onto_b(abox, apilenum, bbox, bpilenum);                    
                }
                else if (action == "move" && where == "over")
                {
                    move_a_over_b(abox, apilenum, bbox, bpilenum);
                }
                else if (action == "pile" && where == "onto")
                {
                    pile_a_onto_b(abox, apilenum, bbox, bpilenum);
                }
                else// action == "pile" && where == "over"
                {
                    pile_a_over_b(abox, apilenum, bbox, bpilenum);                    
                }
            }
        }
        else
        {
            // quite
            break;            
        }
    }

    // 打印输出
    printPile();

    return 0;
}
