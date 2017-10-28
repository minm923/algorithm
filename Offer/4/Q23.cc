#include <iostream>
#include <queue>

using namespace std;

struct BinaryTreeNode
{
    int m_nValue;    
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};


void solution(BinaryTreeNode* tree)
{
    if (!tree)
        return ;

    queue<BinaryTreeNode*> mq;
    mq.push(tree);
    BinaryTreeNode* pNode = NULL;

    while (mq.size())
    {
        pNode = mq.front();
        mq.pop();
        cout << pNode->m_nValue << " " << endl;
        if (pNode->m_pLeft)
        {
            mq.push(pNode->m_pLeft);
        }

        if (pNode->m_pRight)
        {
            mq.push(pNode->m_Right);
        }
    }
}

int main(int argc, char* argv[])
{

    return 0;        
}
