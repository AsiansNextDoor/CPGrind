//#pragma GCC optimize ("trapv")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int INF = 1e9;

signed main() {
    IOS;

    freopen("gpsduel.in", "r", stdin);
    freopen("gpsduel.out", "w", stdout);

    int n, m; cin >> n >> m;
    vector<vector<vector<int>>> adj(n + 1);
    vector<vector<pair<int, int>>> adj1(n + 1);
    vector<vector<pair<int, int>>> adj2(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, p, q; cin >> a >> b >> p >> q;
        adj[a].push_back({b, 0});
        adj1[b].push_back({a, p});
        adj2[b].push_back({a, q});
    }

    vector<int> d(n + 1, 1e9), d1(n + 1, 1e9), d2(n + 1, 1e9);
    vector<int> p1(n + 1, -1), p2(n + 1, -1);

    set<pair<int, int>> q;

    d1[n] = 0;
    q.insert({0, n});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto edge: adj1[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d1[v] + len < d1[to]) {
                q.erase({d1[to], to});
                d1[to] = d1[v] + len;
                p1[to] = v;
                q.insert({d1[to], to});
            }
        }
    }

    d2[n] = 0;
    q.insert({0, n});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto edge: adj2[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d2[v] + len < d2[to]) {
                q.erase({d2[to], to});
                d2[to] = d2[v] + len;
                p2[to] = v;
                q.insert({d2[to], to});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            if (p1[i] != adj[i][j][0]) adj[i][j][1]++;
            if (p2[i] != adj[i][j][0]) adj[i][j][1]++;
        }
    }


    d[1] = 0;
    q.insert({0, 1});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto edge: adj[v]) {
            int to = edge[0];
            int len = edge[1];

            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                q.insert({d[to], to});
            }
        }
    }

    cout << d[n] << endl;
}