#include <iostream>
#include <vector>
#include <algorithm>
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

void recursiveTraversal(Node *root, vector<int> &ans)
{
    if (!root)
    {
        return;
    }

    if (root->left && !(root->right))
    {
        ans.push_back(root->left->data);
    }
    else if (!(root->left) && root->right)
    {
        ans.push_back(root->right->data);
    }

    recursiveTraversal(root->left, ans);
    recursiveTraversal(root->right, ans);
}
// Time Complexity : O(N*Log(N))
// Auxiliary Space : O(Height)
vector<int> noSibling(Node *root)
{
    vector<int> ans;
    recursiveTraversal(root, ans);
    sort(ans.begin(), ans.end());
    if (ans.size() == 0)
    {
        ans.push_back(-1);
    }
    return ans;
}