#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define f first
#define s second

vector<int> visited;
vector<vector<int>> adj;

int cnode = -1;

int dfs(int node, int prev) {
    if (visited[node]) {
        if (visited[node] == 1) return cnode = node;
        else return 0;
    }
    visited[node] = 1;
    for (int i: adj[node]) {
        if (i == prev) continue;
        dfs(i, node);
    }
    visited[node] = 2;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while (t--) {
        int n, a, b; cin >> n >> a >> b; // b needs to win
        visited.clear(); visited.resize(n+1, 0);
        adj.clear(); adj.resize(n+1);
        for (int i = 0; i < n; i++) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        if (a != b) {
            dfs(b, -1);
            if (cnode == b) {
                cout << "YES" << endl;
                continue;
            }
            else if (cnode == a) {
                cout << "NO" << endl;
                continue;
            }
            visited.clear(); visited.resize(n+1, 0);
            
            visited[b] = 2;
            visited[a] = 3;
            queue<vector<int>> pq;
            pq.push({1, cnode});
            string ans = ""; int ansLevel;
            while (!pq.empty()) {
                auto data = pq.front(); pq.pop();
                int level = data[0], node = data[1];
                if (visited[node] == 1) {
                    continue;
                }
                else if (visited[node] == 2) {
                    if (ans == "NO") break;
                    ans = "YES";
                    ansLevel = level;
                }
                else if (visited[node] == 3) {
                    if (ans == "YES") {
                        if (ansLevel == level) ans = "NO";
                        break;
                    }
                    ans = "NO";
                }
                
                for (int i: adj[node]) {
                    pq.push({level+1, i});
                }
                visited[node] = 1;
            }
            cout << ans << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}