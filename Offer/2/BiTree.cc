#include <iostream>
#include <cstdlib>
#include <string.h>
#include <unistd.h>

using namespace std;

// 存整形
template<typename TElemType>
class MyBinaryTree
{
    typedef struct BiTNode
    {
        TElemType data;
        struct BiTNode * lchild;
        struct BiTNode * rchild;
    }BiTNode, *BiTree;

    typedef void (*VISIT)(TElemType data);

public:

    MyBinaryTree() 
    { 
        memset(&m_BiTreeRootNode, 0, sizeof m_BiTreeRootNode);
    }

// TODO : MyBinaryTree(const MyBinaryTree& tree) 
//        operator =

    int CreateBiTree()    
    {
        TElemType data;
        cin >> data;

        if (Nil != data)
        {
            m_BiTreeRootNode.data = data;
            PreOrderCreateBiTree(&m_BiTreeRootNode.lchild);
            PreOrderCreateBiTree(&m_BiTreeRootNode.rchild);
        }

        return 0;                
    }

    

    void PreOrderTraverse()
    {
        if (m_BiTreeRootNode.data != Nil)
        {
            cout << m_BiTreeRootNode.data << endl;
            PreOrderTraverseFunc(m_BiTreeRootNode.lchild);
            PreOrderTraverseFunc(m_BiTreeRootNode.rchild);
        }
    }

private:    

    void PreOrderTraverseFunc(BiTNode* pBiTNode)
    {
        if (NULL != pBiTNode)
        {
            cout << pBiTNode->data << endl;
            PreOrderTraverseFunc(pBiTNode->lchild);
            PreOrderTraverseFunc(pBiTNode->rchild);
        }
    }


    int PreOrderCreateBiTree(BiTNode * * pBiTNode)    
    {
        TElemType data;        
        cin >> data;                

        if (Nil == data)
        {
            *pBiTNode = NULL;
        }
        else
        {
            *pBiTNode = (BiTNode*) malloc ( sizeof(BiTNode) );
            if (!pBiTNode)
            {
                exit(-1);
            }

            (*pBiTNode)->data   = data;
            (*pBiTNode)->lchild = NULL;
            (*pBiTNode)->rchild = NULL;
            PreOrderCreateBiTree(&(*pBiTNode)->lchild);
            PreOrderCreateBiTree(&(*pBiTNode)->rchild);
        }

        return 0;
    }    

    BiTNode m_BiTreeRootNode;
    
    const TElemType Nil = 0;
};

int main(int argc, char * argv[])
{
    MyBinaryTree<int> bt;
    bt.CreateBiTree();
    cout << "input finish..." << endl;
    bt.PreOrderTraverse();

    return 0;
}
