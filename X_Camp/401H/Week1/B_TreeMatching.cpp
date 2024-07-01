#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

vector<vector<int>> adj;
vector<vector<int>> dp; // [node][include?] = number of matches in subtree
vector<bool> visited;

void dfs(int u) {
    visited[u] = true;
    int a = 0; //total of include
    int diff = -1; //biggest not_include - include
    int count = 0;
    for (int i: adj[u]) {
        if (visited[i]) continue;
        count++;
        dfs(i);
        a += dp[i][1];
        diff = max(dp[i][0] - dp[i][1], diff);
    }
    dp[u][0] = a;
    if (count) dp[u][1] = a+diff+1;
}

signed main() {
    IOS;

    int n; cin >> n;
    adj.resize(n+1);
    dp.resize(n+1, vector<int>(2, 0));
    visited.resize(n+1, false);
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);
    cout << max(dp[1][0], dp[1][1]);
}