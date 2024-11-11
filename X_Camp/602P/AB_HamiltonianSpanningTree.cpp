// #pragma GCC optimize ("trapv")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define endl "\n"

int INF, MOD;
vector<vector<int>> tree;
vector<vector<int>> dp;

int dfs(int p, int u)
{
    int tot = 0;
    multiset<int> diffs;
    for (auto v : tree[u])
    {
        if (v == p)
            continue;
        dfs(u, v);
        tot += dp[v][1];
        diffs.insert(dp[v][0] - dp[v][1]);
    }
    if (!diffs.empty())
    {
        auto it = diffs.end();
        it--;
        tot += *it;
        diffs.erase(it);
    }
    dp[u][0] = 1 + tot;
    if (!diffs.empty())
    {
        auto it = diffs.end();
        it--;
        tot += *it;
        diffs.erase(it);
    }
    dp[u][1] = 2 + tot;
}

signed main()
{
    IOS;

    int n, x, y;
    cin >> n >> x >> y;
    tree.resize(n + 1);
    dp.resize(n + 1, vector<int>(2));
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    if (x > y)
    {
        int ans = (n - 1) * y;
        for (int i = 1; i <= n; i++)
        {
            if (tree[i].size() == n - 1)
                ans += x - y;
        }

        cout << ans << endl;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (tree[i].size() > 1)
            {
                dfs(0, i);
                cout << dp[i][1] << endl;
                break;
            }
        }
    }
}