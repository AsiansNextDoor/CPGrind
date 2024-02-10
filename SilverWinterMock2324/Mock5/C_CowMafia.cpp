#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

signed main() {
    IOS;

    int n; cin >> n;
    vector<vector<int>> adj(n+1);
    for (int i = 1; i <= n; i++) {
        int m; cin >> m;
        for (int j = 0; j < m; j++) {
            int c; cin >> c;
            adj[c].push_back(i);
        }
    }

    int fans = n*(n+1)/2;
    for (int root = 1; root <= n; root++) {
        int nodes = 0;
        vector<int> visited(n+1, 0);

        int ans = 0;
        queue<pair<int,int>> bfs;
        bfs.push({root, 1});
        visited[root] = 1;
        while (!bfs.empty()) {
            auto data = bfs.front(); bfs.pop();
            int node = data.f, d = data.s;
            for (int i: adj[node]) {
                if (!visited[i]) {
                    visited[i] = 1;
                    bfs.push({i, d+1});
                }
            }

            ans += d;
            nodes++;
        }

        if (nodes == n) fans = min(ans, fans);
    }

    cout << fans << endl;
}