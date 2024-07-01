#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

signed main() {
    IOS;

    int n, m; cin >> n >> m;
    vector<int> in(n+1, 0);
    vector<vector<int>> adj(n+1);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        in[b]++;
    }

    queue<int> bfs;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) bfs.push(i);
    }

    vector<int> ans;
    vector<bool> visited(n+1, false);
    while (!bfs.empty()) {
        int u = bfs.front(); bfs.pop();
        if (visited[u] == true) {
            ans.clear();
            break;
        }
        visited[u] = true;

        for (int v: adj[u]) {
            in[v]--;
            if (in[v] == 0) bfs.push(v);
        }
        ans.push_back(u);
    }

    if (ans.size() != n) cout << "IMPOSSIBLE" << endl;
    else for (int i = 0; i < n; i++) cout << ans[i] << " ";
}