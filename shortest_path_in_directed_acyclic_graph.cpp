#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <limits.h>
using namespace std;

class Solution
{
public:
    unordered_map<int, vector<pair<int, int>>> adj;

    void addEdge(int u, int v, int weight)
    {
        pair<int, int> p = make_pair(v, weight);
        adj[u].push_back(p);
    }

    void topological_sort(unordered_map<int, bool> &visited, stack<int> &topo, int src)
    {
        visited[src] = true;

        for (auto neighbour : adj[src])
        {
            if (!visited[neighbour.first])
            {
                topological_sort(visited, topo, neighbour.first);
            }
        }

        topo.push(src);
    }

    void shortestPathUtils(vector<int> &distance, stack<int> &topo, int src)
    {
        distance[src] = 0;

        while (!topo.empty())
        {
            int top = topo.top();
            topo.pop();

            if (distance[top] != INT_MAX)
            {
                for (auto i : adj[top])
                {
                    if (distance[top] + i.second < distance[i.first])
                    {
                        distance[i.first] = distance[top] + i.second;
                    }
                }
            }
        }
    }

    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        // create adjacency list
        for (int i = 0; i < M; i++)
        {
            int u = edges[i][0], v = edges[i][1];
            int weight = edges[i][2];

            addEdge(u, v, weight);
        }

        // find topological order
        unordered_map<int, bool> visited;
        stack<int> topo;
        for (int i = 0; i < N; i++)
        {
            if (!visited[i])
            {
                topological_sort(visited, topo, 0);
            }
        }

        // find distance
        vector<int> distance(N, INT_MAX);
        shortestPathUtils(distance, topo, 0);

        // change all INT_MAX values with -1
        for (auto &i : distance)
        {
            if (i == INT_MAX)
            {
                i = -1;
            }
        }

        return distance;
    }
};
