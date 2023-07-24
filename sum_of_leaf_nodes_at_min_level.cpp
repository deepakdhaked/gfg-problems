#include <iostream>
#include <queue>
#include <map>
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
// Space Complexity : O(N)
int minLeafSum(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    queue<Node *> q;
    q.push(root);
    bool flag = false;
    int sum = 0;

    while (!q.empty())
    {
        int n = q.size();

        while (n--)
        {
            Node *curr = q.front();
            q.pop();

            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
            if (!(curr->left) && !(curr->right))
            {
                flag = true;
                sum += curr->data;
            }
        }
        if (flag)
        {
            return sum;
        }
    }
    return sum;
}

void recursiveTraversal(Node *root, int level, map<int, int> &mp)
{
    if (root == NULL)
    {
        return;
    }

    if (!(root->left) && !(root->right))
    {
        mp[level] += root->data;
    }
    recursiveTraversal(root->left, level + 1, mp);
    recursiveTraversal(root->right, level + 1, mp);
}

// Time Complexity : O(N)
// Space Complexity : O(Height)
int minLeafSum(Node *root)
{
    map<int, int> mp;
    recursiveTraversal(root, 0, mp);
    return mp.begin()->second;
}