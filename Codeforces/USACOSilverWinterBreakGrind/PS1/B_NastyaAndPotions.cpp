#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, k;

vector<ll> costs(3e5);
vector<ll> dp(3e5, 1e14);
vector<vector<ll>> recipes(3e5);
ll mix(ll p) {
    if (dp[p] == 1e14) {
        ll c = 0;
        for (ll i = 0; i < recipes[p].size(); i++) {
            c += mix(recipes[p][i]);
        }
        if (recipes[p].size() != 0) dp[p] = min(c, costs[p]);
        else dp[p] = costs[p];
        return dp[p];
    }
    return dp[p];
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll t; cin >> t;
    while (t--) {
        cin >> n >> k;
        
        costs.clear();
        costs.resize(n+1);
        dp.clear();
        dp.resize(n+1, 1e14);
        recipes.clear();
        recipes.resize(n+1);
        
        for (ll i = 1; i <= n; i++) cin >> costs[i];
        
        for (ll i = 0; i < k; i++) {
            ll p; cin >> p;
            dp[p] = 0;
        }
        
        for (ll i = 1; i <= n; i++) {
            ll m; cin >> m;
            recipes[i].clear();
            for (ll j = 0; j < m; j++) {
                ll e; cin >> e;
                recipes[i].push_back(e);
            }
        }
        
        for (int i = 1; i <= n; i++) {
            mix(i);
        }
        for (int i = 1; i <= n; i++) {
            cout << dp[i] << " ";
        }
        cout << endl;
    }
}