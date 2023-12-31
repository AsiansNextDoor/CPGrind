#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define f first
#define s second

ll n;

vector<ll> a;
vector<ll> dp;

ll calc(ll i) {
    ll add = a[i];
    if (i + add > n) return dp[i] = add;
    if (dp[i] == -1) return dp[i] = add + calc(i + add);
    return dp[i];
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t; cin >> t;
    while (t--) {
        cin >> n;
        a.clear(); a.push_back(0);
        dp.clear(); dp.resize(n+1, -1);
        for (ll i = 0; i < n; i++) {
            ll ai; cin >> ai;
            a.push_back(ai);
        }
        ll ans = 0;
        for (ll i = 1; i <= n; i++) {
            ans = max(calc(i), ans);
        }

        cout << ans << endl;
    }
    
}