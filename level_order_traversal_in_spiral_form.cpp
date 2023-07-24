#include <iostream>
#include <vector>
#include <queue>
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

vector<int> findSpiral(Node *root)
{
    vector<int> ans;
    if (!root)
    {
        return ans;
    }

    queue<Node *> q;
    q.push(root);
    int level = 1;

    while (!q.empty())
    {
        int n = q.size();
        vector<int> temp;

        while (n--)
        {
            Node *curr = q.front();
            q.pop();

            temp.push_back(curr->data);

            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
        }
        if (level & 1)
        {
            reverse(temp.begin(), temp.end());
        }
        level++;

        for (int i : temp)
        {
            ans.push_back(i);
        }
    }
    return ans;
}