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
// Space Complexity : O(Height)
int getMaxWidth(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    queue<Node *> q;
    q.push(root);
    int maxWidth = 0;

    while (!q.empty())
    {
        int n = q.size();
        maxWidth = max(maxWidth, n);

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
        }
    }
    return maxWidth;
}