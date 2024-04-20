#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}

void makeSet(vector<int> &parent, vector<int> &rank, int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(int node, vector<int> &parent)
{
    if (parent[node] == node)
    {
        return node;
    }
    return parent[node] = findParent(parent[node], parent);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{

    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[v] < rank[u])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

int minimumSpanningTree(vector<vector<int>> &edges, int n)
{
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n);

    sort(edges.begin(), edges.end(), cmp);

    int minWt = 0;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = findParent(edges[i][0], parent);
        int v = findParent(edges[i][1], parent);
        int wt = edges[i][2];

        if (u != v)
        {
            minWt += wt;
            unionSet(u, v, parent, rank);
        }
    }

    return minWt;
}

int main()
{
    vector<vector<int>> edges = {
        {0, 1, 2},
        {1, 0, 2},
        {0, 3, 6},
        {3, 0, 6},
        {1, 3, 8},
        {3, 1, 8},
        {1, 4, 5},
        {4, 1, 5},
        {1, 2, 3},
        {2, 1, 3},
        {2, 4, 7},
        {4, 2, 7}};
    int ans = minimumSpanningTree(edges, 5);
    cout << ans << endl;
    return 0;
}