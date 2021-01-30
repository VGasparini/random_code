#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;

vector<ii> aux[100005];
vector<int> adj[100005];
int festas[100005];
int a[100005], pai[25][100005], n, m;

int lazy[4 * 100005];
int seg[4 * 100005];

void propagate(int no, int i, int j)
{
    int esq = 2 * no, dir = 2 * no + 1;
    if (lazy[no])
    {
        seg[no] += lazy[no] * (j - i + 1);
        if (i != j)
        {
            lazy[esq] += lazy[no];
            lazy[dir] += lazy[no];
        }
        lazy[no] = 0;
    }
}

void update(int no, int i, int j, int a, int b, int valor)
{
    int esq = 2 * no, dir = 2 * no + 1;
    int meio = (i + j) / 2;

    propagate(no, i, j);
    if (i > j || i > b || a > j)
        return;

    if (a <= i && j <= b)
    {
        lazy[no] += valor;
        propagate(no, i, j);
    }
    else
    {
        update(esq, i, meio, a, b, valor);
        update(dir, meio + 1, j, a, b, valor);
        seg[no] = seg[esq] + seg[dir];
    }
}

int query(int no, int i, int j, int a, int b)
{
    int esq = 2 * no, dir = 2 * no + 1;
    int meio = (i + j) / 2;

    propagate(no, i, j);
    if (i > j || i > b || a > j)
        return 0;

    if (a <= i && j <= b)
        return seg[no];
    else
    {
        int qEsq = query(esq, i, meio, a, b);
        int qDir = query(dir, meio + 1, j, a, b);
        return qEsq + qDir;
    }
}

void dfs(int u)
{
    for (ii par : aux[u])
        update(1, 1, 1e5 + 5, par.first, par.second, +1);
    festas[u] = query(1, 1, 1e5 + 5, a[u], a[u]);
    for (int v : adj[u])
        dfs(v);
    for (ii par : aux[u])
        update(1, 1, 1e5 + 5, par.first, par.second, -1);
}

int main()
{
    cout.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        pai[0][i] = y;
        a[i] = x;
        if (i != 1)
            adj[y].push_back(i);
    }

    for (int i = 1; i < 22; i++)
        for (int j = 1; j <= n; j++)
            pai[i][j] = pai[i - 1][pai[i - 1][j]];

    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        for (int i = 21; i >= 0; i--)
            if (a[pai[i][x]] <= z)
                x = pai[i][x];
        aux[x].emplace_back(y, z);
    }

    dfs(1);
    for (int i = 1; i <= n; i++)
        cout << festas[i] << " ";
    cout << endl;
    return 0;
}
