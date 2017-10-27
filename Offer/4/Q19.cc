#include <stdio.h>

struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;    
};

void Solution(BinaryTreeNode* Tree)
{
    if (Tree)
    {
        BinaryTreeNode* pTmp = Tree->m_pLeft;
        Tree->m_pLeft  = Tree->m_pRight;
        Tree->m_pRight = pTmp;

        Solution(Tree->m_pLeft);
        Solution(Tree->m_pRight);
    }
}

int main(int argc, char* argv[])
{

    return 0;        
}
