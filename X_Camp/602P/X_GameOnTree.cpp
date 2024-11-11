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

double ans = 0;

vector<vector<int>> adj;

void dfs(double depth, int p, int u)
{
    ans += 1.0 / depth;
    for (int v : adj[u])
    {
        if (v == p)
            continue;
        dfs(depth + 1.0, u, v);
    }
}

signed main()
{
    IOS;

    int n;
    cin >> n;
    adj.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1.0, 0, 1);

    cout << fixed << setprecision(6) << ans << endl;
}