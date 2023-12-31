#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define f first
#define s second

int n, m;
vector<int> parent;
vector<int> depth;
vector<vector<int>> adj;

int t = 0;
vector<int> tstart;
vector<int> tend;


void bfs(int p, int node, int d) {
    t++;
    parent[node] = max(p, 1);
    tstart[node] = t;
    depth[node] = d;
    for (int i: adj[node]) {
        if (i != p) {
            bfs(node, i, d+1);
        }
    }
    tend[node] = t;
}

bool comp(int u, int v) {
    return depth[u] < depth[v];
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;

    parent.resize(n+1);
    depth.resize(n+1);
    adj.resize(n+1);
    tstart.resize(n+1);
    tend.resize(n+1);

    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(1, 1, 1);

    while (m--) {
        int k; cin >> k;
        vector<int> v(k);
        for (int i = 0; i < k; i++) {
            cin >> v[i];
            v[i] = parent[v[i]];
        }
        //for (int i = 0; i < k; i++) cout << v[i] << " ";
        //cout << endl;
        sort(v.begin(), v.end(), comp);
        bool yes = true;

        for (int i = 0; i < k-1; i++) {
            if (!(tstart[v[i]] <= tstart[v[i+1]] && tend[v[i]] >= tend[v[i+1]])) {
                yes = false;
                break;
            }
        }

        if (yes) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}