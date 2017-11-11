#include <stdio.h>

int Arr1[N];
int Arr2[N];

struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

// attention 复杂问题自下而上 简单问题自上而下
bool DoesTree1HasTree2(BinaryTreeNode* pTree1, BinaryTreeNode* pTree2)
{
    if (NULL == pTree2)
        return true;        

    if (NULL == pTree1)
        return false;

    if (pTree1->m_nValue != pTree2->m_nValue)
        return false;
    
    return DoesTree1HasTree2(pTree1->m_pLeft,  pTree2->m_pLeft) && 
           DoesTree1HasTree2(pTree2->m_pRight, pTree2->m_pRight)             
}

bool HasSubTree (BinaryTreeNode* pTree1, BinaryTreeNode* pTree2)
{
    bool result = false;

    if (pTree1 && pTree2)
    {
        if (pTree1->m_nValue == pTree2->m_nValue)
        {
            result = DoesTree1HasTree2(pTree1, pTree2);
        }

        if (!result)
        {
            result = HasSubTree(pTree1->m_pLeft, pTree2);
        }

        if (!result)            
        {
            result = HasSubTree(pTree1->m_pRight, pTree2);
        }
    }

    return result;
}

int main(int argc, char * argv[])
{

    return 0;
}
