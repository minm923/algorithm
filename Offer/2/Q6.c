#include <stdio.h>
#include <exception>
#include <stdexcept>

struct BinaryTreeNode
{
    int m_nValue;
    struct BinaryTreeNode * m_pLeft;
    struct BinaryTreeNode * m_pRight;
};

BinaryTreeNode* ConstructCore(int * startPreorder, int * endPreorder, int * startInorder, int * endInorder)
{
    int rootValue = startPreorder[0];    
    BinaryTreeNode* root = new BinaryTreeNode();
    root->m_nValue = rootValue;    
    root->m_pLeft  = NULL;
    root->m_pRight = NULL;

    if (startPreorder == endPreorder)
    {
        if (startInorder == endInorder
            && *startPreorder == *startInorder)
        {
            return root;
        }
        else
        {
            std::logic_error ex("Invalid input.");            
            throw std::exception(ex);
        }
    }

    int * rootInorder = startInorder;
    while(rootInorder <= endInorder && *rootInorder != rootValue)
    {
        ++rootInorder;
    }

    if (rootInorder > endInorder)
    {
            std::logic_error ex("Invalid input.");            
            throw std::exception(ex);
    }

    int leftLength = rootInorder - startInorder;    
    int * leftPreorderEnd = startPreorder + leftLength;

    // 构建左子树
    if (leftLength > 0)
    {
        root->m_pLeft = ConstructCore(startPreorder+1, leftPreorderEnd,
                                      startInorder, rootInorder-1);
    }

    // 构建右子树
    if (leftLength < endPreorder - startPreorder)
    {
        root->m_pRight = ConstructCore(leftPreorderEnd+1, endPreorder,
                                       rootInorder+1, endInorder);        
    }

    return root;
}

BinaryTreeNode* Construct(int * preorder, int *inorder, int length)
{
    if (!preorder || !inorder || length <=0)
    {
        return NULL;
    }

    return ConstructCore(preorder, preorder+length-1, inorder, inorder+length-1);
}

int main(int argc, char *argv[])
{




    return 0;
}
