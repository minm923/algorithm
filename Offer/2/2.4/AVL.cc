#include <iostream>

#define HEIGHT(p) ( (p==NULL)?0:(((Node*)(p))->height) )

#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef int Type;

typedef struct AVLTreeNode
{
    Type key;
    int height;
    AVLTreeNode * left;
    AVLTreeNode * right;
}Node, *AVLTree;

Node* avltree_create_node (Type key, Node* left, Node* right)
{
    Node * p   = new AVLTreeNode();
    if (!p)
    {
        p->key     = key;
        p->height  = 0;
        p->left    = left;
        p->right   = right;
    }
    
    return p;
}

int avltree_height(AVLTree tree)
{
    return HEIGHT(tree);
}

Node* avltree_insert(AVLTree tree, Type key)
{

}

int main(int argc, char * argv[])
{

    return 0;
}
