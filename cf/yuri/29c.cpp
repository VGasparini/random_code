#include <bits/stdc++.h>
using namespace std;

map<int, vector<int>> graph;
map<int, int> visited;

void solve(int u)
{
    cout << u << " ";
    visited[u] = 1;
    for (int v : graph[u])
        if (!visited[v])
            solve(v);
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int root = -1;
    for (auto i : graph)
        if (i.second.size() == 1)
        {
            root = i.first;
            break;
        }
    if (root == -1)
    {
        for (auto i : graph)
        {
            root = i.first;
            break;
        }
    }

    solve(root);

    return 0;
}