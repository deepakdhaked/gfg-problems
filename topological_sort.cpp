#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> getIndegree(vector<int> adj[], vector<int> &indegree, int v)
{
    for (int i = 0; i < v; i++)
    {
        for (auto j : adj[i])
        {
            indegree[j]++;
        }
    }
    return indegree;
}

vector<int> topoSort(int v, vector<int> adj[])
{
    vector<int> indegree(v);
    getIndegree(adj, indegree, v);

    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> ans;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        ans.push_back(front);

        for (auto i : adj[front])
        {
            indegree[i]--;
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
    }
    return ans;
}