#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <array>
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
#include <numeric>

using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

int n, ans = 0;
map<int,int> potions;
vector<vector<int>> adj;


int solve(int node, int parent) { //count number of leaves; when encounter potion, add 1 to answer if remaining leaves > 0
    int rleaf = 0;
    int leaf = 1;
    for (int i: adj[node]) {
        if (i != parent) {
            rleaf += solve(i, node);
            leaf = 0;
        }
    }
    rleaf += leaf;

    while (potions[node] && rleaf > 0) {
        ans++;
        rleaf--;
        potions[node]--;
    }

    return rleaf;
}

signed main() {
    IOS;

    cin >> n;
    adj.resize(n+1);
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<vector<int>> bfs;
    bfs.push({1, 0});

    int leaves = 0;

    while (!bfs.empty()) {
        auto data = bfs.front(); bfs.pop();
        int node = data[0], parent = data[1];
        bool leaf = true;
        for (int i: adj[node]) {
            if (i == parent) continue;
            leaf = false;

            bfs.push({i, node});
        }

        if (leaf) leaves++;
    }

    for (int i = 0; i < leaves; i++) potions[p[i]]++;

    solve(1, 0);
    cout << ans << endl;
}