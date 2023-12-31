#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define f first
#define s second

signed main() {
    int n, m; cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n+1);

    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    int q; cin >> q;
    while (q--) {
        int u, v; cin >> u >> v;
        vector<set<int>> visited(n+1);

        queue<pair<int,int>> bfs;

        bfs.push({u, 0});

        int c = 0;
        while (!bfs.empty()) {
            auto data = bfs.front();
            bfs.pop();
            int node = data.f;
            int color = data.s;
            auto it = visited[node].lower_bound(color);
            if (it != visited[node].end() && *it == color) continue;
            visited[node].insert(color);
            if (node == v) {
                c++;
                continue;
            }
            for (auto i: adj[node]) {
                if (color == 0 || color == i.s) bfs.push({i.f, i.s});
            }
        }

        cout << c << endl;
    }
}