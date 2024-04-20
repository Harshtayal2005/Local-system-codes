#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    unordered_map<int, vector<pair<int, int>>> adj;
    for (vector<int> &i : vec)
    {
        int u = i[0];
        int v = i[1];
        int d = i[2];

        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
    }

    vector<int> dist(vertices, INT_MAX);
    dist[source] = 0;
    set<pair<int, int>> mySet;

    mySet.insert({0, source});

    while (!mySet.empty())
    {
        auto top = *mySet.begin();
        mySet.erase(mySet.begin());

        int node = top.second;
        int d = top.first;

        for (auto v : adj[node])
        {
            if (d + v.second < dist[v.first])
            {
                auto record = mySet.find({dist[v.first], v.first});
                if (record != mySet.end())
                {
                    mySet.erase(record);
                }
                mySet.insert({d + v.second, v.first});
                dist[v.first] = d + v.second;
            }
        }
    }
    return dist;
}

int main() {
    vector<vector<int>> vec = {{0, 1, 4}, {0, 7, 8}, {1, 2, 8}, {1, 7, 11}, {2, 3, 7}, {2, 8, 2}, {2, 5, 4}, {3, 4, 9}, {3, 5, 14}, {4, 5, 10}, {5, 6, 2}, {6, 7, 1}, {6, 8, 6}, {7, 8, 7}};
    vector<int> result = dijkstra(vec, 9, 14, 0);
    for (int i = 0; i < result.size(); i++) {
        cout << "Distance from 0 to " << i << " is " << result[i] << endl;
    }
    return 0;
}