#include <iostream>

struct BSTNode
{
    int m_Value;
    BSTNode * p_left;
    BSTNode * p_right;    
}

int SearchBST1(BSTNode* pNode, int value)
{
    if (pNode)
    {
        if (pNode->m_Value == value)
        {
            return value;
        }
        else if (pNode->m_Value > value)
        {
            return SearchBST(pNode->p_left, value);        
        }
        else
        {
            return SearchBST(pNode->p_right, value);        
        }
    }

    return (-value + 1);
}

int SearchBST2(BSTNode* pNode, int value)
{
    if (pNode)
    {
        while (pNode)        
        {
            if (pNode->m_Value > value)
            {
                pNode = pNode->left;
            }
            else if (pNode->mValue < value)
            {
                pNode = pNode->right;
            }
            else
            {
                break;
            }
        }

        if (pNode)
        {
            return value;
        }
    }

    return (-value + 1);
}

int InsertBST1(BSTNode** pRoot, int value)
{
    if (pRoot)
    {
        if (!(*pRoot))
        {
            (*pRoot) = new BSTNode();
            (*pRoot)->m_Value = value;
            (*pRoot)->p_left  = NULL;
            (*pRoot)->p_right = NULL;

            return 1;
        }
        else
        {
            return InsertCore((*pRoot), value);
        }
    }
}

int InsertCore(BSTNode* pNode, int value)
{
    if (pNode->m_Value == value)
    {
        return 0;
    }
    else if (pNode->m_Value > value)
    {
        if (pNode->m_right)
        {
            return InsertCore(pNode->m_right, value);
        }
        else
        {
            pNode->m_right = new BSTNode();                        
            pNode->m_right->m_Value = value;
            pNode->m_right->p_left  = NULL;
            pNode->m_right->p_right = NULL;

            return 1;
        }
    }
    else
    {
        if (pNode->left)
        {
            return InsertCore(pNode->left, value);
        }
        else
        {
            pNode->m_left = new BSTNode();                        
            pNode->m_left->m_Value = value;
            pNode->m_left->p_left  = NULL;
            pNode->m_left->p_right = NULL;
 
            return 1;
        }
    }
}

int InsertBST2(BSTNode** pRoot, int value)
{
    if (pRoot)
    {
        if ((*pRoot) == NULL)
        {
            (*pRoot) = new BSTNode();
            (*pRoot)->m_Value = value;
            (*pRoot)->p_left  = NULL;
            (*pRoot)->p_right = NULL;

        }
        else
        {

        }
    }

    return 0;    
}

int main(int argc, char * argv[])
{

    return 0;
}

