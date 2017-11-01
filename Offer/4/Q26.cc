#include <iostream>

struct ComplexListNode
{
    int m_nValue;    
    ComplexListNode* m_pNext;
    ComplexListNode* m_pSibling;
};

void CloneNodes(ComplexListNode* pHead)
{
    ComplexListNode* pNode = pHead;

    while (pNode != NULL)
    {
        ComplexListNode* pCloned = new ComplexListNode();
        pCloned->m_nValue        = pNode->m_nValue;
        pCloned->m_pNext         = pNode->m_pNext;
        pCloned->m_pSibling      = NULL;
        
        pNode->m_pNext = pCloned;
        pNode          = pCloned->m_pNext;
    }
}

void ConnectSilingNode(ComplexListNode* pHead)
{
    ComplexListNode* pNode = pHead;

    while (pNode != NULL)
    {
        ComplexListNode* pCloned = pNode->m_pNext;

        if (pNode->m_pSibling != NULL)
        {
            pClone = pNode->m_pSibling->m_pNext;
        }

        pNode = pCloned->m_pNext;
    }
}

ComplexListNode* ReconnectNode(ComplexListNode* pHead)
{
    if (!pHead)
        return NULL;

    ComplexListNode* pNode   = pHead;
    ComplexListNode* pClonedHead = pHead->m_pNext;
    ComplexListNode* pCloned = pCloneHead;

    while (pNode != NULL)
    {
        pNode->m_pNext   = pCloned->m_pNext;
        if (pCloned->m_pNext != NULL)
        {
            pCloned->m_pNext = pCloned->m_pNext->m_pNext;
        }

        pNode   = pNode->m_pNext;
        pCloned = pCloned->m_pNext;
    }

    return pClonedHead;
}

ComplexListNode* Clone(ComplexListNode* pHead)
{
    CloneNodes(pHead);
    ConnectSilingNode(pHead);
    return ReconnectNode(pHead);
}

int main(int argc, char * argv[])
{



    return 0;
}
