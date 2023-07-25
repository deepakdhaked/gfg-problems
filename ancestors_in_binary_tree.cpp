#include <iostream>
#include <unordered_map>
#include <queue>
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

// Time Complexity : O(N)
// Auxiliary Space : O(N)
vector<int> Ancestors(struct Node *root, int target)
{
    unordered_map<int, int> ancestors;
    ancestors[root->data] = -1;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        if (curr->left)
        {
            ancestors[curr->left->data] = curr->data;
            q.push(curr->left);
        }
        if (curr->right)
        {
            ancestors[curr->right->data] = curr->data;
            q.push(curr->right);
        }
    }

    vector<int> ans;
    while (ancestors[target] != -1)
    {
        target = ancestors[target];
        ans.push_back(target);
    }
    return ans;
}

bool recursiveFunc(Node *root, int target, vector<int> &ancestor)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->data == target)
    {
        return true;
    }

    if (recursiveFunc(root->left, target, ancestor) || recursiveFunc(root->left, target, ancestor))
    {
        ancestor.push_back(root->data);
        return true;
    }
    return false;
}

// Time Complexity : O(N)
// Auxiliary Space : O(Height)
vector<int> Ancestors(struct Node *root, int target)
{
    vector<int> ancestor;
    bool res = recursiveFunc(root, target, ancestor);
    return ancestor;
}