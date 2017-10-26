#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int m_nValue;   
    ListNode* m_pNext;
};

int ListLength(ListNode* pNode)
{
    int iLen = 0;
    while(pNode)
    {
        ++iLen;
        pNode = pNode->m_pNext;
    }

    return iLen;
}

ListNode* NextNNode(ListNode* pNode, int n)
{
    while(n)
    {
        --n;
        if (pNode)
        {
            pNode = pNode->m_pNext;        
        }
    }

    return pNode;
}

ListNode* suck_solution(ListNode* pHead, int n)
{
    if (!pHead || n<=0)
        return NULL;

    int iListLen = ListLength(pHead);

    if (n > iListLen)
    {
        return NULL;
    }
    else
    {
        ListNode* pNode = pHead;
        ListNode* pNextNNode = NextNNode(pNode, n);
        while(pNextNNode)
        {
            pNode = pNode->m_pNext;
            pNextNNode = NextNNode(pNode, n);
        }

        return pNode;
    }
}

ListNode* solution(ListNode* pHead, int n)
{
    if (!pHead || n<=0)
        return NULL;

    ListNode* pNode   = pHead;
    ListNode* pTarget = NextNNode(pNode, n-1);
    if (pTarget)
    {
        while(pTarget->m_pNext)
        {
            pNode = pNode->m_pNext;
            pTarget = pTarget->m_pNext;
        }
        return pNode;
    }

    return NULL;
}

int main(int argc, char* argv[])
{

    return 0;
}
