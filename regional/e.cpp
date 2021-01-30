#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int idade[100005];
vector<int> ga[100005];
vector<int> gaI[100005];
vector<pair<int, int>> gaF[100005];
int gaP[100005];
vector<int> lazy[100005];
int res[100005];

void prop(int anf, int l)
{
    auto p = lower_bound(gaI[anf].begin(), gaI[anf].end(), l);
    if (p == gaI[anf].end())
        return;
    int pp = p - gaI[anf].begin();
    // cout << pp << " " << anf << " " << l << endl;
    for (int i = pp; i < ga[anf].size(); i++)
    {
        lazy[ga[anf][i]].push_back(l);
    }
}

void DFS(int u)
{
    if (!lazy[u].empty())
    {
        res[u] += lazy[u].size();
        for (int idadeMin : lazy[u])
            prop(u, idadeMin);
    }
    for (int v : ga[u])
        DFS(v);
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        b--;
        idade[i] = a;
        if (i)
        {
            gaP[i] = b;
            gaF[b].push_back({a, i});
        }
    }

    for (int i = 0; i < n; i++)
        sort(gaF[i].begin(), gaF[i].end());
    for (int i = 0; i < n; i++)
    {
        for (auto u : gaF[i])
        {
            ga[i].push_back(u.second);
            gaI[i].push_back(u.first);
        }
    }

    for (int i = 0; i < m; i++)
    {
        int anf, l, r;
        scanf("%d %d %d", &anf, &l, &r);
        anf--;
        while (gaP[anf] != anf and idade[gaP[anf]] <= r)
        {
            anf = gaP[anf];
        }
        res[anf]++;
        if (!lazy[anf].empty())
        {
            res[anf] += lazy[anf].size();
            for (int idadeMin : lazy[anf])
                prop(anf, idadeMin);
            lazy[anf].clear();
        }

        prop(anf, l);
    }

    DFS(0);

    for (int i = 0; i < n; i++)
    {
        if (i)
            printf(" ");
        printf("%d", res[i]);
    }
    printf("\n");
}