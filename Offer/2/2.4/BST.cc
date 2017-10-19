#include <iostream>

struct BSTNode
{
    int m_Value;
    BSTNode * p_left;
    BSTNode * p_right;    
};

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
            return SearchBST1(pNode->p_left, value);        
        }
        else
        {
            return SearchBST1(pNode->p_right, value);        
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
                pNode = pNode->p_left;
            }
            else if (pNode->m_Value < value)
            {
                pNode = pNode->p_right;
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


int InsertBST2(BSTNode** pRoot, int value)
{
    BSTNode * pNode = (*pRoot);
    int flg = 0;

    if (pRoot)
    {
        if (pNode == NULL)
        {
            pNode = new BSTNode();
            pNode->m_Value = value;
            pNode->p_left  = NULL;
            pNode->p_right = NULL;
            flg = 1;
        }
        else
        {
            while(!flg)
            {
                if (pNode->m_Value > value)
                {
                    if (pNode->p_left == NULL)                    
                    {
                        pNode->p_left = new BSTNode();                                                                    
                        pNode->p_left->m_Value = value;
                        pNode->p_left->p_left  = NULL;
                        pNode->p_left->p_right = NULL;
                        flg = 1;
                    }
                    else
                    {
                        pNode = pNode->p_left;
                    }
                }
                else if (pNode->m_Value < value)
                {
                    if (pNode->p_right == NULL)                    
                    {
                        pNode->p_right = new BSTNode();                                                                    
                        pNode->p_right->m_Value = value;
                        pNode->p_right->p_left  = NULL;
                        pNode->p_right->p_right = NULL;
                        flg = 1;
                    }
                    else
                    {
                        pNode = pNode->p_right;
                    }
                }
                else
                {
                    flg = 0;
                }
            }
        }
    }

    return flg;
}

int Delete(BSTNode** pRoot, int value)
{

}

int main(int argc, char * argv[])
{

    return 0;
}

