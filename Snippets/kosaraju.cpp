#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution
{
public:
    void findTopo(vector<vector<int>> &adj, int u, vector<bool> &visited, stack<int> &topoSort)
    {
        visited[u] = true;

        for (int v : adj[u])
        {
            if (!visited[v])
            {
                findTopo(adj, v, visited, topoSort);
            }
        }

        topoSort.push(u);
    }
    void findScc(vector<vector<int>> &adj, int u, vector<bool> &visited)
    {
        visited[u] = true;

        for (int v : adj[u])
        {
            if (!visited[v])
            {
                findScc(adj, v, visited);
            }
        }
    }

    int kosaraju(int V, vector<vector<int>> &adj)
    {
        // toposort
        stack<int> topoSort;
        vector<bool> visited(V, false);
        for (int u = 0; u < V; u++)
        {
            if (!visited[u])
            {
                findTopo(adj, u, visited, topoSort);
            }
        }

        // reverse the graph
        vector<vector<int>> newAdj(V);
        for (int u = 0; u < V; u++)
        {
            for (int &v : adj[u])
            {
                newAdj[v].push_back(u);
            }
        }

        // dfs again on reversed graph
        fill(visited.begin(), visited.end(), false);
        int cntScc = 0;
        while (!topoSort.empty())
        {
            int u = topoSort.top();
            topoSort.pop();
            if (!visited[u])
            {
                cntScc++;
                findScc(newAdj, u, visited);
            }
        }

        return cntScc;
    }
};