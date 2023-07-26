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
vector<Node *> nodesAtOddLevels(Node *root)
{
    vector<Node *> ans;
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

            if (level & 1)
            {
                ans.push_back(curr);
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
    return ans;
}