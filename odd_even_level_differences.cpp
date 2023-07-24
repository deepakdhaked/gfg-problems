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
int getLevelDiff(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    queue<Node *> q;
    q.push(root);
    int odd_level_sum = 0, even_level_sum = 0;
    int level = 1;

    while (!q.empty())
    {
        int n = q.size();

        while (n--)
        {
            Node *curr = q.front();
            q.pop();
            if (level % 2 == 0)
            {
                even_level_sum += curr->data;
            }
            else
            {
                odd_level_sum += curr->data;
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
    return (odd_level_sum - even_level_sum);
}