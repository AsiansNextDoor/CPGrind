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
    map<int,int> child;
    vector<vector<int>> adj(n+1);
    for (int i = 1; i <= n; i++) {
        int m; cin >> m;
        for (int j = 0; j < m; j++) {
            int c; cin >> c;
            child[c]++;
            adj[c].push_back(i);
        }
    }


    int maxc = 0, root = 1;
    for (int i = 1; i <= n; i++) {
        if (maxc < child[i]) {
            maxc = child[i];
            root = i;
        }
    }

    vector<int> visited(n+1, 0);
    priority_queue<pair<int,int>> pq;
    vector<int> parent(n+1);
    parent[root] = 0;
    
    queue<pair<int,int>> bfs;
    bfs.push({root, 1});
    visited[root] = 1;
    while (!bfs.empty()) {
        auto data = bfs.front(); bfs.pop();
        int node = data.f, layer = data.s;

        bool leaf = true;
        for (int i: adj[node]) {
            if (!visited[i]) {
                leaf = false;
                visited[i] = true;
                bfs.push({i, layer+1});
                parent[i] = node;
            }
        }

        if (leaf) {
            pq.push({layer, node});
        }
    }
    
    visited.clear();
    visited.resize(n+1, 0);
    visited[0] = 1;

    vector<int> wages(n+1, 1);

    ll ans = 0;
    
    while (!pq.empty()) {
        auto data = pq.top(); pq.pop();
        int layer = data.f, node = data.s;
        int p = parent[node];
        wages[p] += wages[node];
        if (!visited[p]) {
            pq.push({layer-1, p});
            visited[p] = 1;
        }
    }
    for (int i = 1; i <= n; i++) ans += wages[i];

    cout << ans << endl;
}