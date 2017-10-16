#include <iostream>
#include <stdlib.h>
#include <stdexcept>
#include <new>

using namespace std;

struct BinaryTreeNode
{
    int m_nValue;    
    BinaryTreeNode * m_pLeft;
    BinaryTreeNode * m_pRight;
};

BinaryTreeNode* MakeNode(int value)
{
    BinaryTreeNode* pNode = (BinaryTreeNode*) malloc (sizeof(BinaryTreeNode));
    if (pNode)        
    {
        pNode->m_nValue = value;        
        pNode->m_pLeft  = NULL;
        pNode->m_pRight = NULL;
    }

    return pNode;
}

BinaryTreeNode* constructcore(int* preOderStart, int* preOderEnd, 
                   int* midOderStart, int* midOderEnd)
{
    int iRootValue = *preOderStart;

    int *pMidOrderRoot = NULL;
    for (int *p = midOderStart; p<=midOderEnd; ++p)
    {
        if (*p == iRootValue)
        {
            pMidOrderRoot = p;            
        }
    }

    int iLeftTreeLen = pMidOrderRoot - midOderStart;

    if (!pMidOrderRoot)
    {
        throw runtime_error("input error");
    }

    BinaryTreeNode* pRoot = MakeNode(iRootValue);
    if (!pRoot)
    {
        throw bad_alloc();
    }

    if (pMidOrderRoot > midOderStart)
    {
        pRoot->m_pLeft = constructcore(preOderStart+1, preOderStart+iLeftTreeLen, midOderStart, pMidOrderRoot-1);
    }

    if (midOderEnd > pMidOrderRoot)
    {
        pRoot->m_pRight = constructcore(preOderStart+iLeftTreeLen+1, preOderEnd, pMidOrderRoot+1, midOderEnd);
    }

    return pRoot;    
}

void midOderPrint(BinaryTreeNode* pRoot)
{
    if (pRoot)
    {
        midOderPrint(pRoot->m_pLeft);
        cout << pRoot->m_nValue << endl;
        midOderPrint(pRoot->m_pRight);
    }
}

void postOderPrint(BinaryTreeNode* pRoot)
{
    if (pRoot)
    {
        postOderPrint(pRoot->m_pLeft);
        postOderPrint(pRoot->m_pRight);
        cout << pRoot->m_nValue << endl;
    }
}

BinaryTreeNode* construct(int* preOder, int* midOder, int iLen)
{
    if (!preOder || !midOder || iLen <=0)
    {
        return NULL;
    }

    return constructcore(preOder, preOder+iLen-1, midOder, midOder+iLen-1);
}

int main(int argc, char * argv[])
{
    int preOrder[] = {1, 2, 4, 7, 3, 5, 6, 8};
    int midOrder[] = {4, 7, 2, 1, 5, 3, 8, 6};

    BinaryTreeNode* pRoot = construct(preOrder, midOrder, sizeof(preOrder)/sizeof(preOrder[0]));

    midOderPrint(pRoot);
    cout << endl;
    postOderPrint(pRoot);

    return 0;        
}
