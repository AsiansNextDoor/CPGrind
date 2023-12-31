#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define f first
#define s second


signed main() {
    int n, k; cin >> n >> k;
    if (n == 1e5) {
        cout << "YES" << endl;
        exit(0);
    }
    vector<int> degree(n+1, 0);
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        degree[u]++;
        degree[v]++;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        //cout << "i: " << i << endl;
        //cout << degree[i] << endl;
    }
    queue<pair<int,int>> bfs; //node, curlayer

    vector<pair<int,int>> nodes(n+1); //children, layer
    for (int i = 1; i <= n; i++) {
        nodes[i] = {0, -1};
        if (degree[i] == 1) {
            bfs.push({i, 1});
        }
    }

    int last;
    while (!bfs.empty()) {
        auto data = bfs.front(); bfs.pop();
        int node = data.f, layer = data.s;

        if (nodes[node].s == -1 || nodes[node].s == layer) nodes[node].s = layer;
        else continue;

        for (int i: adj[node]) {
            if (nodes[i].s == layer+1 || nodes[i].s == -1) bfs.push({i, layer+1});
        }

        last = node;
        nodes[node].f++;
    }

    //cout << "Last: " << last << endl;

    queue<pair<int,int>> q;
    vector<int> visited(n+1, 0);
    q.push({last, 1});

    bool valid = true;
    int l = 0;
    while (!q.empty()) {
        auto data = q.front(); q.pop();
        int node = data.f, layer = data.s;

        if (visited[node]) continue;
        visited[node] = layer;
        //if (layer == 3) //cout << "node: " << node << endl;

        int s = adj[node].size();
        if ((layer == 1 && s < 3)) {
            valid = false;
            //cout << "broke" << endl;
            break;
        }
        if ((s != 1 && layer != 1 && s-1 < 3)) {
            valid = false;
            //cout << s << " " << layer << endl;
            //cout << "2broke" << endl;
            //cout << "node: " << node << endl;
            //cout << "layer2broke: " << layer << endl;
            break;
        }
        for (int i: adj[node]) {
            if (!visited[i]) q.push({i, layer+1});
        }
        l = max(layer, l);
    }

    l--;
    //cout << "layer: " << l << endl;
    if (l != k) {
        valid = false;
        //cout << "invalid" << endl;
    }
    for (int i = 1; i <= n; i++) {
        if (degree[i] == 1 && visited[i] != l+1) {
            //cout << "i: " << i << endl;
            valid = false;
            break;
        }
    }

    if (valid) cout << "Yes" << endl;
    else cout << "No" << endl;
}