#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

int INF;

vector<vector<int>> adj;

int dfs(int p, int u) {
    int ans = 0, cur = adj[u].size() + 1;

    for (int v: adj[u]) {
        if (v == p) continue;
        ans = max(dfs(u, v), ans);
    }
    return max(ans, cur);
}

signed main() {
    IOS;

    int n; cin >> n;
    adj.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << dfs(0, 1) << endl;
}