#include <iostream>
#include <stack>

struct ListNode
{
    int m_nKey;
    ListNode * m_pNext;
};

void PrintListReversingly(const ListNode* const pHead)
{
    if (pHead != NULL)
    {
        std::stack<int> nodes;           

        ListNode * pTmp = pHead;
        
        while (pTmp)
        {
            int value = pTmp->m_nKey;
            nodes.push(value);
        }
    }

    while (nodes.size() > 0)
    {
        int n = nodes.top();
        std::cout << n << std::endl;
        nodes.pop();
    }
}

void PrintListRecursive(const listNode* const pNode)
{
    if (!pNode)
    {
        PrintListRecursive(pNode->m_pNext);        
        std::cout << pNode->m_nKey << std::endl;
    }
}

int main(int argc, char * argv[])
{


    return 0;    
}
