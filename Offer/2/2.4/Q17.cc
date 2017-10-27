#include <stdio.h>

struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
}


ListNode* MergeList(ListNode* pHead1, ListNode* pHead2)
{
    if (!pHead1 || !pHead2)
    {
        return NULL;
    }

    ListNode* pMergeList = NULL;
    ListNode* pTmp = NULL;
    ListNode* pNode1 = pHead1;
    ListNode* pNode2 = pHead2;
    ListNode* pMergeNode = NULL;

    while (pNode1 && pNode2)
    {
        if  (pNode1->m_nValue > pNode2->m_nValue)
        {
            pTmp          = pNode2;
            pNode2        = pNode2->m_pNext;
            pTmp->m_pNext = NULL;
        }
        else
        {
            pTmp          = pNode1;
            pNode1        = pNode1->m_pNext;
            pTmp->m_pNext = NULL;
        }

        if (!pMergeList)
        {
            pMergeList = pTmp;
            pMergeNode = pMergeList;
        }
        else
        {
            pMergeNode->m_pNext = pTmp;
            pMergeNode = pTmp;
        }
    }

    if (pNode1)
    {
        pMergeNode->m_pNext = pNode1;
    }

    if (pNode2)
    {
        pMergeNode->m_pNext = pNode2;
    }

    return pMergeList;
}

int main(int argc, char* argv[])
{
    return 0;
}
