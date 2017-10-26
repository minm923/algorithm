#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};

ListNode* reverseList(ListNode* pHead)
{
    if (!pHead)
        return NULL;

    ListNode* pNode       = pHead;
    ListNode* reverseList = NULL;
    ListNode* pNext       = NULL;

    while (!pNode)
    {
        pNext          = pNode->m_pNext;
        pNode->m_pNext = NULL;

        if (!reverseList)
        {
            reverseList = pNode;
        }
        else
        {
            pNode->m_pNext = reverseList;
            reverseList   = pNode;
        }
        pNode = pNext;
    }

    return reverseList;
}

int main(int argc, char* argv[])
{

    return 0;
}
