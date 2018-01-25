#include <iostream>
#include <limits.h>
#include <string.h>

struct Node
{
    struct Node * pNext;
    int value;
};

struct Node* CreateList()
{
    std::cout << "please input list node value" << std::endl;

    struct Node * pHead  = NULL;
    struct Node * pIndex = NULL;

    int ch = 0;
    while (ch != -1)
    {
        std::cin >> ch;
        if (-1 != ch)
        {
            struct Node * pNode = new struct Node;        
            pNode->value = ch;
            pNode->pNext = NULL;

            if (NULL == pHead)
            {
                pHead  = pNode;
                pIndex = pNode;
            }
            else
            {
                pIndex->pNext = pNode;
                pIndex = pNode;
            }
        }
    }

    return pHead;
}

void traverse_list(struct Node * pHead)
{
    while (pHead != NULL)
    {
        std::cout << pHead->value << " ";
        pHead = pHead->pNext;
    }
    std::cout << std::endl;
}

void del_repeated_node(struct Node* pHead)
{
    if (!pHead) return ;

    //char H[INT_MAX] = {0};// 栈空间不够
    int H[1000] = {0};
    memset(H, 0, sizeof(H));

    struct Node * pIndex     = pHead;
    struct Node * pPreNode   = NULL;
    struct Node * pNextNode  = NULL;
    int            value     = 0;

    while (pIndex)
    {
        value = pIndex->value;
        if (0 == H[value])
        {
            H[value] = 1;
            pPreNode = pIndex;
            pIndex   = pIndex->pNext;
        }
        else
        {
            if (pIndex->pNext)
            {
                pNextNode        = pIndex->pNext;

                int tmp          = pNextNode->value;
                pNextNode->value = pIndex->value;
                pIndex->value    = tmp;

                pIndex->pNext = pNextNode->pNext;

                delete pNextNode;
                pNextNode = NULL;
            }
            else
            {
                pPreNode->pNext = NULL;
                delete  pIndex;
                pIndex = NULL;
            }
        }
    }
}

void del_repeated_node2(struct Node* pHead)
{
    if (!pHead) return ;

    //char H[INT_MAX] = {0};// 栈空间不够
    int H[1000] = {0};
    memset(H, 0, sizeof(H));

    struct Node * pIndex     = pHead;
    struct Node * pPreNode   = NULL;
    struct Node * pNextNode  = NULL;
    int            value     = 0;

    while (pIndex)
    {
        value = pIndex->value;
        if (0 == H[value])
        {
            H[value] = 1;
            pPreNode = pIndex;
            pIndex   = pIndex->pNext;
        }
        else
        {
            struct Node* pD = pIndex;
            pPreNode->pNext = pIndex->pNext;
            pIndex = pPreNode->pNext;
            delete pD;
        }
    }
}

int main(int argc, char * argv[])
{
    struct Node * pHead = CreateList();
    traverse_list(pHead);
    std::cout << "start..." << std::endl;
    del_repeated_node2(pHead);
    std::cout << "end..." << std::endl;
    traverse_list(pHead);

    return 0;
}

