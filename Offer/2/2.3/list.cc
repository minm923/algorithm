#include <iostream>

struct ListNode
{
    int m_nValue;
    struct ListNode * m_pNext;
};

void AddToTail(struct ListNode** pHead, int value)
{
    struct ListNode * pNewNode = new struct ListNode(); 

    if (pHead != NULL && pNewNode !=NULL)
    {
        pNewNode->m_nValue = value;
        pNewNode->m_pNext  = NULL;

        if (*pHead == NULL)
        {
            *pHead = pNewNode;
        }
        else
        {
            struct ListNode * tmp = *pHead;
            while (tmp->m_pNext)
            {
                tmp = tmp->m_pNext;
            }

            tmp->m_pNext = pNewNode;
        }
    }
}

int RemoveNode(struct ListNode** pHead, int value)
{
    int iDelNum = 0;
    struct ListNode * pFirst  = *pHead;
    struct ListNode * pSecond = NULL;
    struct ListNode * pDel    = NULL;

    if (pHead != NULL && pFirst != NULL)
    {
        if (pFirst->m_nValue == value)
        {
            (*pHead) = pFirst->m_pNext;
            pDel = pFirst;
            iDelNum = 1;
        }
        else
        {
            pSecond = pFirst->m_pNext;                                                                                    

            while (pSecond)
            {
                if (pSecond->m_nValue == value)
                {
                    pDel = pSecond;
                    pFirst->m_pNext = pSecond->m_pNext;
                    iDelNum = 1;
                }
                else
                {
                    pFirst  = pSecond;
                    pSecond = pSecond->m_pNext;
                }
            }
        }
    }

    if (pDel != NULL)
    {
        delete pDel;
    }

    return iDelNum;
}

int main(int argc, char * argv[])
{


    
    return 0;
}

