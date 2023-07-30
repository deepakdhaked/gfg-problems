#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

// Time Complexity: O(Height of the BST).
// Auxiliary Space: O(1).
Node *inOrderSuccessor(Node *root, Node *x)
{
    Node *temp = root;
    Node *successor = nullptr;

    while (temp)
    {
        if (x->data < temp->data)
        {
            successor = temp;
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    return successor;
}