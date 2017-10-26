#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int m_nValue;
    ListNode* p_pNext;
}

/*
 *  O(1) 时间删除该节点
 *  需要保证 pToBeDeleted 在改链表中
 */

void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted)
{
    if (!pListHead || !(*pListHead) || !pToBeDeleted)
    {
        return ;
    }

    ListNode * pToBeDeletedNext = NULL;                
    if (NULL == pToBeDeleted->p_pNext)
    {
        if (*pListHead == pToBeDeleted)
        {
            delete pToBeDeleted;
            (*pListHead) = NULL;
        }
        else
        {
            ListNode * pNode = *pListHead;

            while (pNode->p_pNext != pToBeDeleted)
            {
                pNode = pNode->p_pNext;
            }
            pNode->p_pNext = NULL;
            delete pToBeDeleted;
            pToBeDeleted = NULL;
        }
    }
    else
    {
        pToBeDeleted->m_nValue = pToBeDeleted->p_pNext->m_nValue;
        ListNode * pTmp = pToBeDeleted->p_pNext;
        pToBeDeleted->p_pNext  = pToBeDeleted->p_pNext->p_pNext;
        delete pTmp;
        pTmp = NULL;// attention 指针delete之后要置NULL
    }
}

int main(int argc, char* argv[])
{

    return 0;
}
