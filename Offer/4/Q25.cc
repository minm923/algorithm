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
        printf("输入%d的左子节点：",ch);
        CreateBiTree(&((*T)->m_pLeft));
        printf("输入%d的右子节点：",ch);
        CreateBiTree((&(*T)->m_pRight));
    }

    return;
}

int sumOfVector(vector<int>& my)
{
    int sum = 0;
    for (int i=0; i<my.size(); ++i)
    {
        sum += my[i];
    }
    return sum;    
}

int sumOfpVector(vector<BinaryTreeNode*>& ps)
{
    int sum = 0;

    for (int i=0; i<ps.size(); ++i)
    {
        sum += ps[i]->m_nValue;
    }

    return sum;
}

void PrintPVector(vector<BinaryTreeNode*>& ps)
{
    cout << endl;
    for (int i=0; i<ps.size(); ++i)
    {
        cout << ps[i]->m_nValue << " ";
    }
    cout << endl;
}

void PrintVector(vector<int>& my)
{
    cout << endl;
    for (int i=0; i<my.size(); ++i)
    {
        cout << my[i] << " ";
    }
    cout << endl;
}

void solution(BinaryTreeNode* root, vector<int>& my, int value)
{
    if (!root)
        return ;

    if (root->m_pLeft == NULL && root->m_pRight == NULL)
    {
        my.push_back(root->m_nValue);
        if (sumOfVector(my) == value)
            PrintVector(my);
        my.pop_back();
    }
    else
    {
        my.push_back(root->m_nValue);
        solution(root->m_pLeft, my, value);
        solution(root->m_pRight, my, value);
        my.pop_back();
    }
}

// attention 试探与回溯
void solution2(BinaryTreeNode* root, int value)
{
    if (!root)
        return ;

    vector<BinaryTreeNode*> ps;
    ps.push_back(root);
    BinaryTreeNode* pFlg = NULL;
    BinaryTreeNode* pTop = NULL;
    bool bTest = 1;

    while (ps.size() > 0)
    {
        pTop = ps.back();

        if (bTest)// 试探
        {
            if (pTop->m_pLeft)
            {
                ps.push_back(pTop->m_pLeft);
            }
            else
            {
                if (pTop->m_pRight)
                {
                    ps.push_back(pTop->m_pRight);
                }
                else// 叶子节点
                {
                    if (sumOfpVector(ps) == value)
                    {
                        PrintPVector(ps);
                    }
                    pFlg = ps.back();
                    ps.pop_back();
                    bTest = 0;
                }
            }
        }
        else// 回溯
        {
            if (pFlg == pTop->m_pLeft)
            {
                if (pTop->m_pRight)
                {
                    ps.push_back(pTop->m_pRight);
                    bTest = 1;
                }
                else
                {
                    pFlg = ps.back();
                    ps.pop_back();
                }
            }
            else if (pFlg == pTop->m_pRight)
            {
                    pFlg = ps.back();
                    ps.pop_back();
            }
            else
            {
                cout << " what the hell" << endl;
            }
        }
    }
}

int main(int argc, char* argv[])
{
    BinaryTreeNode* tree = NULL;
    CreateBiTree(&tree);
    vector<int> mv;
    //solution(tree, mv, 8);
    solution2(tree, 9);

    return 0;
}

