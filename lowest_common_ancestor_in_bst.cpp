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

// Recursive Solution :
// Time Complexity: O(Height)
// Auxiliary Space: O(Height)
Node *LCA(Node *root, int n1, int n2)
{
    if (!root)
    {
        return NULL;
    }
    int curr = root->data;
    if (n1 < curr && n2 < curr)
    {
        return LCA(root->left, n1, n2);
    }
    if (n1 > curr && n2 > curr)
    {
        return LCA(root->right, n1, n2);
    }
    return root;
}

// Iterative Solution :
// Time Complexity: O(Height)
// Auxiliary Space: O(1)
Node *LCA(Node *root, int n1, int n2)
{
    while (root != NULL)
    {
        int curr = root->data;

        if (n1 < curr && n2 < curr)
        {
            root = root->left;
        }
        else if (n1 > curr && n2 > curr)
        {
            root = root->right;
        }
        else
        {
            break;
        }
    }
    return root;
}