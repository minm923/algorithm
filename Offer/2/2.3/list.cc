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
    struct ListNode * pFirst = *pHead;

    if (pHead != NULL && pFirst != NULL)
    {

    }

    return 0;
}

int main(int argc, char * argv[])
{


    
    return 0;
}

