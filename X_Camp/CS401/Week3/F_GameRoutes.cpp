#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <deque>
#include <stack>
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

ll MOD = 1e9+7;

signed main() {
    IOS;

    ll n, m; cin >> n >> m;

    vector<ll> in(n+1, 0);
    vector<vector<ll>> adj(n+1);
    vector<ll> dp(n+1, 0);

    for (ll i = 0; i < m; i++) {
        ll a, b; cin >> a >> b;
        adj[a].push_back(b);
        in[b]++;
    }

    queue<ll> bfs;

    //taking out unnecessary edges
    for (ll i = 2; i <= n; i++) {
        if (!in[i]) bfs.push(i);
    }
    while (!bfs.empty()) {
        ll u = bfs.front(); bfs.pop();

        for (ll v: adj[u]) {
            in[v]--;
            if (in[v] == 0 && v != 1) {
                bfs.push(v);
            }
        }
    }

    bfs.push(1);
    dp[1] = 1;

    

    while (!bfs.empty()) {
        ll u = bfs.front(); bfs.pop();

        for (ll v: adj[u]) {
            in[v]--;
            dp[v] += dp[u];
            dp[v] %= MOD;
            if (in[v] == 0) {
                bfs.push(v);
            }
        }
    }

    cout << dp[n] << endl;
}