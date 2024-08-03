#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

int INF = 1e9;

int b, e, p, n, m;
vector<vector<int>> adj;
vector<int> bfs(int s) {
    vector<int> visited(n+1, 0);
    vector<int> dist(n+1, INF);

    queue<int> q;
    q.push(s);
    visited[s]++;
    dist[s] = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v: adj[u]) {
            if (visited[v]) continue;
            q.push(v);
            visited[v]++;
            dist[v] = dist[u] + 1;
        }
    }

    return dist;
 }

signed main() {
    IOS;

    cin >> b >> e >> p >> n >> m;

    adj.resize(n+1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> d1 = bfs(1);
    vector<int> d2 = bfs(2);
    vector<int> dn = bfs(n);

    int ans = INF;
    for (int u = 1; u <= n; u++) {
        if (d1[u] == INF) continue;
        ans = min(d1[u] * b + d2[u] * e + dn[u] * p, ans);
    }

    cout << ans << endl;
}