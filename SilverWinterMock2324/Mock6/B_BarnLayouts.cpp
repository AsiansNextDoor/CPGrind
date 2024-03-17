#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <iterator>
#include <set>
#include <map>
#include <string>
#include <queue>

using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

signed main() {
    IOS;

    int n, m; cin >> n >> m;

    vector<vector<int>> graph(n+1);
    vector<bool> visited(n+1, false);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bool valid = true;
    int cgs = 0; // complete graphs
    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        visited[i] = true;

        queue<int> bfs;
        bfs.push(i);

        int e = -1;
        int nodes = 0;
        while (!bfs.empty()) {
            int node = bfs.front(); bfs.pop();
            nodes++;

            int edges = 0;
            for (int j: graph[node]) {
                if (!visited[j]) {
                    bfs.push(j);
                    visited[j] = true;
                }
                edges++;
            }
            if (e != -1 && e != edges) {
                //cout << "b1" << endl;
                valid = false;
                break;
            }
            e = edges;
        }

        if (e != nodes - 1){
            //cout << "b2" << endl;
            valid = false;
        }

        if (!valid) break;
        cgs++;
    }

    if ((valid && cgs == 2) || m == (int)n*(n-1)/2) cout << "YES" << endl;
    else cout << "NO" << endl;
}