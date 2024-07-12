#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    typedef pair<int, int> pi;
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> res(V, INT_MAX);
        priority_queue<pi, vector<pi>, greater<pi>> pq;

        res[S] = 0;
        pq.push({0, S});

        while (!pq.empty())
        {
            pi p = pq.top();
            pq.pop();
            int node = p.second;
            int minDist = p.first;

            for (auto vec : adj[node])
            {
                int d = vec[1];
                int v = vec[0];
                if (minDist + d < res[v])
                {
                    res[v] = minDist + d;
                    pq.push({res[v], v});
                }
            }
        }

        return res;
    }
};