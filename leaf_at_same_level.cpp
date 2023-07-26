#include <iostream>
#include <queue>
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

bool recursiveTraversal(Node *root, int level, int &leaf_level)
{
    if (!root)
    {
        return true;
    }

    if (!(root->left) && !(root->right))
    {
        if (leaf_level != -1)
        {
            return (level == leaf_level);
        }
        else
        {
            leaf_level = level;
            return true;
        }
    }

    return recursiveTraversal(root->left, level + 1, leaf_level) && recursiveTraversal(root->right, level + 1, leaf_level);
}

// Recursive Traversal :
// Time Complexity : O(N)
// Auxiliary Space : O(Height)
bool check(Node *root)
{
    int level = 1, leaf_level = -1;
    return recursiveTraversal(root, level, leaf_level);
}

// LevelOrder Traversal :
// Time Complexity : O(N)
// Auxiliary Space : O(N)
bool check(Node *root)
{
    if (!root)
    {
        return true;
    }

    queue<Node *> q;
    q.push(root);
    bool flag = false;

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
            }
        }
        if (flag && !q.empty())
        {
            return false;
        }
    }
    return true;
}