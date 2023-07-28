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
void inorderTraversal(Node *root, vector<int> &inorder)
{
    if (!root)
    {
        return;
    }

    inorderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    inorderTraversal(root->right, inorder);
}
float findMedian(Node *root)
{
    vector<int> inorder;
    inorderTraversal(root, inorder);

    int mid = inorder.size() / 2;
    if (inorder.size() & 1)
    {
        return inorder[mid];
    }
    return (inorder[mid] + inorder[mid - 1]) / 2;
}