//#pragma GCC optimize ("trapv")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int n, ans = 0;
vector<int> a;
vector<vector<int>> adj;
vector<vector<int>> cost; // rate, total

void bdfs(int p, int u) {
    int rate = 0, total = 0;
    for (int v: adj[u]) {
        if (v == p) continue;
        bdfs(u, v);
        rate += cost[v][0];
        total += cost[v][1];
    }
    cost[u][1] = total + rate;
    cost[u][0] += rate;
}

void dfs(int p, int u, int rate, int tot) {
    tot += rate;
    rate += a[u];
    for (int v: adj[u]) {
        if (v == p) continue;
        tot += cost[v][1];
        rate += cost[v][0];
    }
    ans = max(tot, ans);
    for (int v: adj[u]) {
        if (v == p) continue;
        dfs(u, v, rate - cost[v][0], tot - cost[v][1]);
    }
}

signed main() {
    IOS;
    
    cin >> n;
    a.resize(n + 1);
    adj.resize(n + 1);
    cost.resize(n + 1, vector<int>(2, 0));

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cost[i][0] = a[i];
    for (int i = 0; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bdfs(0, 1);
    dfs(0, 1, 0, 0);

    cout << ans << endl;
}