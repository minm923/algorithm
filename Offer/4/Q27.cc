#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

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
        printf("输入%d的左子节点：\n",ch);
        CreateBiTree(&((*T)->m_pLeft));
        printf("输入%d的右子节点：\n",ch);
        CreateBiTree((&(*T)->m_pRight));
    }

    return;
}

void InorderTraverse(BinaryTreeNode* pRoot)
{
    if (!pRoot)
        return ;
    vector<BinaryTreeNode*> ms;       
    ms.push_back(pRoot);
    BinaryTreeNode* pTop = NULL;

    while (ms.size() > 0)
    {
        pTop = ms.back();
        ms.pop_back();
        cout << pTop->m_nValue << " ";


        if (pTop->m_pRight)
        {
            ms.push_back(pTop->m_pRight);
        }

        if (pTop->m_pLeft)
        {
           ms.push_back(pTop->m_pLeft); 
        }

    }
    cout << endl;
}

int main(int argc, char* argv[])
{
    BinaryTreeNode* tree = NULL;
    CreateBiTree(&tree);
    InorderTraverse(tree);

    return 0;
}

