#include <iostream>
#include <stdio.h>
#include <stdlib.h>

struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

int solution(BinaryTreeNode* root)
{
    if (!root)
        return 0;

    int nLeft  = solution(root->m_pLeft);
    int nRight = solution(root->m_pRight);

    return (nLeft > nRight)?nLeft+1:nRight+1;
}

void CreateBiTree(BinaryTreeNode **T)
{
    int ch;
    scanf("%d",&ch);
    if (ch == -1)
    {
        *T = NULL;
        return;
    }
    else
    {
        *T = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
        (*T)->m_nValue = ch;
        printf("输入%d的左子节点：",ch);
        CreateBiTree(&((*T)->m_pLeft));
        printf("输入%d的右子节点：",ch);
        CreateBiTree((&(*T)->m_pRight));
    }

    return;
}

int main(int argc, char * argv[])
{
    std::cout << "Start to create BiTree, -1 == NULL NODE" << std::endl;
    BinaryTreeNode* pRoot;
    CreateBiTree(&pRoot);

    std::cout << solution(pRoot) << std::endl;

    return 0;
}

