#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int, vector<pair<int, int>>> adj;

    for (auto p : g)
    {
        int u = p.first.first;
        int v = p.first.second;
        int d = p.second;

        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
    }

    vector<int> key(n + 1, INT_MAX);
    vector<bool> mst(n + 1, false);
    vector<int> parent(n + 1, -1);

    key[1] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});

    while (!pq.empty())
    {
        int u;

        u = pq.top().second;
        pq.pop();

        mst[u] = true;

        for (auto v : adj[u])
        {
            if (!mst[v.first] && v.second < key[v.first])
            {
                key[v.first] = v.second;
                parent[v.first] = u;
                pq.push({v.second, v.first});
            }
        }
    }

    vector<pair<pair<int, int>, int>> res;

    for (int i = 2; i <= n; i++)
    {
        res.push_back({{parent[i], i}, key[i]});
    }

    return res;
}

int main()
{
    vector<pair<pair<int, int>, int>> g = {
        {{1, 2}, 1},
        {{1, 3}, 2},
        {{2, 3}, 3},
        {{2, 4}, 4},
        {{3, 4}, 5},
        {{3, 5}, 6},
        {{4, 5}, 7}};
    vector<pair<pair<int, int>, int>> res = calculatePrimsMST(5, 7, g);
    for (auto p : res)
    {
        cout << p.first.first << " " << p.first.second << " " << p.second << endl;
    }
    return 0;
}