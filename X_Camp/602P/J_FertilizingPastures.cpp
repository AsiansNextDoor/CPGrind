//#pragma GCC optimize ("trapv")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

ll INF, MOD;

int n, t, timer = 0;
vector<int> s, a, dp, rate; // size, 
vector<vector<int>> adj;
int subtree(int p, int u) {
    a[u] = rate[u];
    int ssize = 1;
    for (int v: adj[u]) {
        if (p == v) continue;
        ssize += subtree(u, v);
        a[u] += a[v];
    }
    return s[u] = ssize;
}

void solve(int p, int u) {
    dp[u] = timer * rate[u];
    timer++;

    set<pair<double, int>> c;
    for (int v: adj[u]) {
        if (p == v) continue;
        c.insert({{(double)s[v] / (double)a[v], v}});
    }

    for (auto data: c) {
        solve(data.second);
        timer++;
    }

    
}



signed main() {
    IOS;

    cin >> n >> t;
    vector<int> rate;
    rate.resize(n + 1);
    a.resize(n + 1);
    s.resize(n + 1);
    dp.resize(n + 1, 0);
    adj.resize(n + 1);
    
    for (int i = 2; i <= n; i++) {
        int p; cin >> p >> rate[i];
        adj[p].push_back(i);
        adj[i].push_back(p);
    }

    subtree(0, 1);
    solve(0, 1);

    int ans = 0;
    for (int i = 1; i <= n; i++) ans += dp[i];
    
    cout << ans << endl;
}