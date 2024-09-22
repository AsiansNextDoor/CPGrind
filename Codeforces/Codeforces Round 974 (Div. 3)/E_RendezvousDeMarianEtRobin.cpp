//#pragma GCC optimize ("trapv")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int INF = 1000000000;

signed main() {
    IOS;

    int t; cin >> t;
    while (t--) {
        int n, m, h; cin >> n >> m >> h;
        vector<int> hnodes(n + 1, 0);
        for (int i = 0; i < h; i++) {
            int c; cin >> c;
            hnodes[c]++;
        }
        vector<vector<vector<int>>> adj(2, vector<vector<int>>(n + 1)); // foot, horse
        for (int i = 0; i < m; i++) {
            int u, v, w; cin >> u >> v >> w;
            adj[0][u].push_back({v, w});
            adj[0][v].push_back({u, w});
            adj[1][u].push_back({v, w / 2});
            adj[1][v].push_back({u, w / 2});
        }

        vector<vector<int>> d(2, vector<int>(n + 1, INF));

        d[0][1] = 0;
        set<vector<int>> q; // cost, node, horse
        map<vector<int>, int> hmap;
        q.insert({0, 1});
        hmap[{0, 1}] = 0;
        while (!q.empty()) {
            int i = q.begin()[0], u = q.begin()[1];
            q.erase(q.begin());

            curh = hmap[{i, u}] | hnodes[u];

            for (auto edge: adj[horse[u]][u]) {
                int to = edge[0];
                int len = edge[1];

                if (d[curh][u] + len < d[curh][to]) {
                    q.erase({d[curh][to], to});
                    d[curh][to] = d[curh][u] + len;
                    q.insert({d[curh][u], to});
                    hmap[{[curh]d[u], to}] = curh;
                }
            }
        }
    }
}