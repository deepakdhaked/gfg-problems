#include <iostream>
#include <unordered_map>
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
int kthAncestor(Node *root, int k, int node)
{
    unordered_map<int, int> ancestor;
    ancestor[root->data] = -1;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp->left)
        {
            ancestor[temp->left->data] = temp->data;
            q.push(temp->left);
        }
        if (temp->right)
        {
            ancestor[temp->right->data] = temp->data;
            q.push(temp->right);
        }
    }

    while (node != -1)
    {
        node = ancestor[node];
        k--;

        if (k == 0)
        {
            break;
        }
    }
    return node;
}

Node *recursiveFunc(Node *root, int &k, int node)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == node)
    {
        return root;
    }

    Node *left = recursiveFunc(root->left, k, node);
    Node *right = recursiveFunc(root->right, k, node);

    if (left != NULL && right == NULL)
    {
        k--;
        if (k == 0)
        {
            return root;
        }
        return left;
    }
    if (left == NULL && right != NULL)
    {
        k--;
        if (k == 0)
        {
            return root;
        }
        return right;
    }
    return NULL;
}

// Time Complexity : O(N)
// Auxiliary Space : O(Height)
int kthAncestor(Node *root, int k, int node)
{
    Node *ans = recursiveFunc(root, k, node);
    if (ans == NULL || ans->data == node)
    {
        return -1;
    }
    return ans->data;
}