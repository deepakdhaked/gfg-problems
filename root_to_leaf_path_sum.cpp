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

// Time Complexity : O(N)
// Space Complexity : O(Height)
void recursiveTraversal(Node *root, long long path, long long &ans)
{
    if (root == NULL)
    {
        return;
    }

    path = path * 10 + root->data;

    if (!(root->left) && !(root->right))
    {
        ans += path;
    }

    recursiveTraversal(root->left, path, ans);
    recursiveTraversal(root->right, path, ans);
}

// Optimized Approach :
// Time Complexity : O(N)
// Space Complexity : O(Height)
int recursiveTraversal2(Node *root, int path)
{
    if (root == NULL)
    {
        return 0;
    }

    path = path * 10 + root->data;

    if (!(root->left) && !(root->right))
    {
        return path;
    }

    return recursiveTraversal2(root->left, path) + recursiveTraversal2(root->right, path);
}

long long treePathsSum(Node *root)
{
    long long ans = 0;
    recursiveTraversal(root, 0, ans);
    return ans;
}