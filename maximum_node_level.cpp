#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
#include <unordered_map>
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
int maxNodeLevel(Node *root)
{
    queue<Node *> q;
    q.push(root);
    int level = 0;
    int ans = 0;
    int element_at_level = INT_MIN;

    while (!q.empty())
    {
        int n = q.size();
        if (n > element_at_level)
        {
            ans = level;
        }
        element_at_level = n;

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
        level++;
    }
    return ans;
}

void dfs(Node *root, unordered_map<int, int> &level_frequency, int level)
{
    if (!root)
    {
        return;
    }

    level_frequency[level]++;

    dfs(root->left, level_frequency, level + 1);
    dfs(root->right, level_frequency, level + 1);
}

// Time Complexity : O(N)
// Auxiliary Space : O(Height)
int maxNodeLevel(Node *root)
{
    unordered_map<int, int> level_frequency;
    dfs(root, level_frequency, 0);

    int maxelement = INT_MIN, ans;
    for (auto it : level_frequency)
    {
        if (it.second > maxelement)
        {
            ans = it.first;
            maxelement = it.second;
        }
        else if (it.second == maxelement)
        {
            ans = min(ans, it.first);
        }
    }
    return ans;
}