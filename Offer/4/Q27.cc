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

void MidorderTraverse(BinaryTreeNode* pRoot)
{
    if (!pRoot)
        return ;    
    int flg = 1;// push flg
    vector<BinaryTreeNode*> ms;
    ms.push_back(pRoot);
    BinaryTreeNode* pTop = NULL;

    while (ms.size() > 0)
    {
        pTop = ms.back();
        if (flg)
        {
            if (pTop->m_pLeft)
            {
                ms.push_back(pTop->m_pLeft);
            }
            else
            {
                flg = 0;
            }
        }
        else
        {
            cout << pTop->m_nValue << " ";
            ms.pop_back();
            if (pTop->m_pRight)
            {
                ms.push_back(pTop->m_pRight);
                flg = 1;
            }
        }
    }

    cout << endl;
}

void PostorderTraverse(BinaryTreeNode* pRoot)
{
    if (!pRoot)
        return ;

    int flg = 1;// push flg
    vector<BinaryTreeNode*> ms;
    ms.push_back(pRoot);
    BinaryTreeNode* pTop      = NULL;
    BinaryTreeNode* pLastVist = NULL;

    while (ms.size() > 0)        
    {
        pTop = ms.back();
        if (flg)
        {
            if (pTop->m_pLeft)
            {
                ms.push_back(pTop->m_pLeft);
            }
            else// pTop->m_pLeft == NULL
            {
                flg = 0;
            }
        }
        else
        {
            if (pTop->m_pRight)
            {
                if (pTop->m_pRight != pLastVist)
                {
                    ms.push_back(pTop->m_pRight);
                    flg = 1;
                }
                else
                {
                    cout << pTop->m_nValue <<" ";
                    pLastVist = pTop;
                    ms.pop_back();
                }
            }
            else
            {
                    cout << pTop->m_nValue <<" ";
                    pLastVist = pTop;
                    ms.pop_back();
            }
        }
    }

    cout << endl;
}

BinaryTreeNode* ConvertTreeToList(BinaryTreeNode* pRoot)
{
    if (!pRoot)
        return NULL;

    int flg = 1;// push flg
    vector<BinaryTreeNode*> ms;
    ms.push_back(pRoot);
    BinaryTreeNode* pTop = NULL;

    BinaryTreeNode* pHead = NULL;
    BinaryTreeNode* pNode = NULL;

    while (ms.size() > 0)
    {
        pTop = ms.back();
        if (flg)
        {
            if (pTop->m_pLeft)
            {
                ms.push_back(pTop->m_pLeft);
            }
            else
            {
                flg = 0;
            }
        }
        else
        {
            cout << pTop->m_nValue << " ";
            ms.pop_back();
            if (pTop->m_pRight)
            {
                ms.push_back(pTop->m_pRight);
                flg = 1;
            }

            if (!pHead)
            {
                pHead = pTop;
                pNode = pTop;
                
                pNode->m_pLeft  = NULL;
                pNode->m_pRight = NULL;
            }
            else
            {
                pTop->m_pLeft  = NULL;
                pTop->m_pRight = NULL;

                pNode->m_pRight = pTop;
                pTop->m_pLeft   = pNode;

                pNode = pTop;
            }
        }
    }

    cout << endl;

    return pHead;
}

void TraverseList(BinaryTreeNode* node)
{
    while (node->m_pRight)
    {
        cout << node->m_nValue << " ";
        node = node->m_pRight;
    }

    cout << node->m_nValue << " ";
    cout << endl;

    while (node->m_pLeft)
    {
        cout << node->m_nValue << " ";
        node = node->m_pLeft;
    }
    
    cout << node->m_nValue << " ";
    cout << endl;
}

int main(int argc, char* argv[])
{
    BinaryTreeNode* tree = NULL;
    CreateBiTree(&tree);
    //InorderTraverse(tree);
    //MidorderTraverse(tree);
    //PostorderTraverse(tree);

    BinaryTreeNode* node = ConvertTreeToList(tree);
    TraverseList(node);


    return 0;
}
