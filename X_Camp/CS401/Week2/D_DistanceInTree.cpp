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

vector<int> dp;
vector<vector<int>> adj;

signed main() {
    IOS;

    int n, k; cin >> n >> k;

    dp.resize(n+1, 0);
    adj.resize(n+1);

    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    
}