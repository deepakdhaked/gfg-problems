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

void recursiveTraversal(Node *root, vector<int> &ans, int level)
{
    if (root == NULL)
    {
        return;
    }

    if (ans.size() == level)
    {
        ans.push_back(root->data);
    }

    recursiveTraversal(root->right, ans, level + 1);
    recursiveTraversal(root->left, ans, level + 1);
}

vector<int> rightView(Node *root)
{
    vector<int> ans;
    recursiveTraversal(root, ans, 0);
    return ans;
}