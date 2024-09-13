#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int INF = 1000000000;
vector<vector<pair<int, int>>> adj;

signed main() {
    IOS;

    int n, m; cin >> n >> m;

    vector<vector<vector<int>>> e1(n + 1);
    vector<vector<vector<int>>> e2(n + 1)
    for (int i = 0; i < m; i++) {
        int a, b, p, q; cin >> a >> b >> p >> q;
        e1[a].push_back({b, p, q});
        e2[b].push_back({a, p, q});
    }

    vector<int> nxtedge(n + 1, 0);
    
    
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    set<pair<int, int>> q;
    q.insert({0, s});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                p[to] = v;
                q.insert({d[to], to});
            }
        }
    }
}