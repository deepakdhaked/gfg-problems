#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> findOrder(int v, int p, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(v);
        vector<int> indegree(v, 0);
        for (auto i : prerequisites)
        {
            indegree[i[0]]++;
            adj[i[1]].push_back(i[0]);
        }

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
        if (ans.size() == v)
        {
            return ans;
        }
        return {};
    }
};