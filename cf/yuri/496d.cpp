#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int dp[N][2], b[N];
int i, j, n, m, ans, x, y, t, z, k;
pair<int, int> p[N];

int bs(int x, int s)
{
    int l = x, r = n;
    while (r - l > 1)
    {
        int t = (l + r) / 2;
        if (dp[t][1] - dp[x][1] < s && dp[t][2] - dp[x][2] < s)
            l = t;
        else
            r = t;
    }
    if (dp[r][1] - dp[x][1] < s && dp[r][2] - dp[x][2] < s)
        return n + 1;
    return r;
}

int main()
{
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> x;
        dp[i][1] = dp[i - 1][1] + (x == 1);
        dp[i][2] = dp[i - 1][2] + (x == 2);
        m = x;
    }

    for (z = 1; z <= max(dp[n][1], dp[n][2]); z++)
    {
        int t1 = 0, t2 = 0, l = 0;
        while (l < n)
        {
            int ll = bs(l, z);
            if (ll > n)
            {
                l = ll;
                break;
            }
            if (dp[ll][1] - dp[l][1] == z)
                t1++;
            else
                t2++;
            l = ll;
        }
        if (l > n)
            continue;
        if ((m == 1 && t1 > t2) || (m == 2 && t1 < t2))
            p[ans++] = make_pair(max(t1, t2), z);
    }
    sort(p, p + ans);
    cout << ans << endl;
    for (i = 0; i < ans; i++)
        cout << p[i].first << ' ' << p[i].second << endl;
}