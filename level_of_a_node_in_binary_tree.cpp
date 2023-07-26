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

void dfs(Node *root, int level, int target, int &ans)
{
    if (!root)
    {
        return;
    }

    if (root->data == target)
    {
        ans = level;
        return;
    }

    dfs(root->left, level + 1, target, ans);
    dfs(root->right, level + 1, target, ans);
}

// Time Complexity : O(N)
// Auxiliary Space : O(Height)
int getLevel(struct Node *root, int target)
{
    int ans = 0;
    dfs(root, 1, target, ans);
    return ans;
}

// Time Complexity : O(N)
// Auxiliary Space : O(N)
int getLevel(struct Node *root, int target)
{
    queue<Node *> q;
    q.push(root);
    int level = 1;

    while (!q.empty())
    {
        int n = q.size();

        while (n--)
        {
            Node *curr = q.front();
            q.pop();

            if (curr->data == target)
            {
                return level;
            }

            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
        }
        level++;
    }
    return 0;
}