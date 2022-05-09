#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    void destructRecursive(Node* n)
    {
        if(n)
        {
            destructRecursive(n->left);
            destructRecursive(n->right);
            delete n;
        }
    }
};

Node *createnode(int _data)
{
    Node *newnode = new Node();

    newnode->data = _data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int l = height(root->left);
        int r = height(root->right);
        if (l > r)
            return (l + 1);
        else
            return r + 1;
    }
}
void currentlevel(Node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1)
    {
        currentlevel(root->left, level - 1);
        currentlevel(root->right, level - 1);
    }
}
void bfs(Node *root)
{
    for (int i = 1; i <= height(root); i++)
    {
        currentlevel(root, i);
    }
}

/////////////////////////////////////////////////////////////
// DFS
/////////////////////////////////////////////////////////////

void printInorder(Node* node)
{
    if(node == nullptr)
        return;

    /* recur on left side */
    printInorder(node->left);

    cout << node->data << " " ;

    // recur on right side and print
    printInorder(node->right);
}

/* Given a binary tree, print its nodes in preorder*/
void printPreorder(Node* node)
{
    if (node == NULL)
        return;

    /* first print data of node */
    cout << node->data << " ";

    /* then recur on left subtree */
    printPreorder(node->left);

    /* now recur on right subtree */
    printPreorder(node->right);
}

/* Given a binary tree, print its nodes in postorder*/
void printPostorder(Node* node)
{
    if (node == NULL)
        return;


    /*  recur on left subtree */
    printPreorder(node->left);

    /* now recur on right subtree */
    printPreorder(node->right);

    /*  print data of node */
    cout << node->data << " ";
}

