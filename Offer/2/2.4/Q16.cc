#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int m_nValue;   
    ListNode* m_pNext;
};

ListNode* reverseList(ListNode* pHead)
{
    ListNode* pNode = new ListNode;
    pNode->m_nValue = pHead->m_nValue;
    pNode->m_pNext  = NULL;
    
    ListNode* pNext = pHead->m_pNext;
    ListNode* pTmp  = NULL;
    
    while (pNext)
    {
        pTmp = new ListNode;        
        pTmp->m_nValue = pHead;
    }
}

int main(int argc, char* argv[])
{

    return 0;
}
