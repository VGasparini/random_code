#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;
int n, m;
vector<string> matriz;
int vis[45][45];
int res[45][45];

void solveHor(map<char, int> &mapa, string x)
{
    int xs = x.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= m - xs; j++)
        {
            map<char, int> mapa2;
            for (int k = 0; k < xs; k++)
            {
                if (mapa2.count(matriz[i][j + k]))
                    mapa2[matriz[i][j + k]]++;
                else
                    mapa2[matriz[i][j + k]] = 1;
            }
            if (mapa2 == mapa)
            {
                for (int k = 0; k < xs; k++)
                {
                    if (!vis[i][j + k])
                    {
                        vis[i][j + k] = 1;
                        res[i][j + k]++;
                    }
                }
            }
        }
    }
}

void solveVer(map<char, int> &mapa, string x)
{
    int xs = x.size();
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i <= n - xs; i++)
        {

            map<char, int> mapa2;
            for (int k = 0; k < xs; k++)
            {
                if (mapa2.count(matriz[i + k][j]))
                    mapa2[matriz[i + k][j]]++;
                else
                    mapa2[matriz[i + k][j]] = 1;
            }
            if (mapa2 == mapa)
            {
                for (int k = 0; k < xs; k++)
                {
                    if (!vis[i + k][j])
                    {
                        vis[i + k][j] = 1;
                        res[i + k][j]++;
                    }
                }
            }
        }
    }
}

void solveDiag(map<char, int> &mapa, string x)
{
    int xs = x.size();
    for (int i = 0; i <= n - xs; i++)
    {
        for (int j = 0; j <= m - xs; j++)
        {
            map<char, int> mapa2;
            for (int k = 0; k < xs; k++)
            {
                if (mapa2.count(matriz[i + k][j + k]))
                    mapa2[matriz[i + k][j + k]]++;
                else
                    mapa2[matriz[i + k][j + k]] = 1;
            }
            if (mapa2 == mapa)
            {
                for (int k = 0; k < xs; k++)
                {
                    if (!vis[i + k][j + k])
                    {
                        vis[i + k][j + k] = 1;
                        res[i + k][j + k]++;
                    }
                }
            }
        }
    }

    for (int i = 0; i <= n - xs; i++)
    {
        for (int j = m - 1; j >= xs - 1; j--)
        {
            map<char, int> mapa2;
            for (int k = 0; k < xs; k++)
            {
                if (mapa2.count(matriz[i + k][j - k]))
                    mapa2[matriz[i + k][j - k]]++;
                else
                    mapa2[matriz[i + k][j - k]] = 1;
            }
            if (mapa2 == mapa)
            {
                for (int k = 0; k < xs; k++)
                {
                    if (!vis[i + k][j - k])
                    {
                        vis[i + k][j - k] = 1;
                        res[i + k][j - k]++;
                    }
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        matriz.push_back(x);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        memset(vis, 0, sizeof vis);
        string x;
        cin >> x;
        map<char, int> mapa;
        for (char c : x)
        {
            if (mapa.count(c) > 0)
                mapa[c]++;
            else
                mapa[c] = 1;
        }

        solveHor(mapa, x);
        solveVer(mapa, x);
        solveDiag(mapa, x);
    }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << res[i][j] << " ";
    //     } cout << endl;
    // }

    int rc = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            rc += res[i][j] >= 2;
    }
    cout << rc << endl;
}

/*



*/