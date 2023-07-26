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

// Time Complexity : O(N)
// Auxiliary Space : O(N)
int depthOfOddLeaf(Node *root)
{
    queue<Node *> q;
    q.push(root);
    int level = 1, depth = 0;

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
            if (!(curr->left) && !(curr->right) && (level & 1))
            {
                depth = level;
            }
        }
        level++;
    }
    return depth;
}

int recursiveTraversal(Node *root, int level)
{
    if (!root)
    {
        return 0;
    }

    if (!(root->left) && !(root->right) && (level & 1))
    {
        return level;
    }

    int left = recursiveTraversal(root->left, level + 1);
    int right = recursiveTraversal(root->right, level + 1);

    return max(left, right);
}

// Time Complexity : O(N)
// Auxiliary Space : O(Height)
int depthOfOddLeaf(Node *root)
{
    int level = 1;
    return recursiveTraversal(root, level);
}