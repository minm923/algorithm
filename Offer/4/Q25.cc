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

void solution2(BinaryTreeNode* root)
{

}

int main(int argc, char* argv[])
{
    BinaryTreeNode* tree = NULL;
    CreateBiTree(&tree);
    vector<int> mv;
    solution(tree, mv, 8);

    return 0;
}

