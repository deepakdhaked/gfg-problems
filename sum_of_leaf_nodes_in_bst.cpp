#include <iostream>
#include <vector>
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

// Time Complexity : O(N);
// Space Complexity : O(Height)
void recursiveTraversal(Node *root, int &leaf_sum)
{
    if (!root)
    {
        return;
    }

    if (!(root->left) && !(root->right))
    {
        leaf_sum += root->data;
    }

    recursiveTraversal(root->left, leaf_sum);
    recursiveTraversal(root->right, leaf_sum);
}

int sumOfLeafNodes(Node *root)
{
    int leaf_sum = 0;
    recursiveTraversal(root, leaf_sum);
    return leaf_sum;
}