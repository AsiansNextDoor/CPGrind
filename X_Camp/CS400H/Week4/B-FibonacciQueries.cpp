#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll MOD = 998244353;

vector<ll> fib(1e5+1, 0);

signed main() {
    fib[1] = 1;
    fib[2] = 1;
    for (ll i = 3; i < 1e5+1; i++) {
        fib[i] = (fib[i-2] + fib[i-1]) % MOD;
    }
    ll t; cin >> t;
    while (t--) {
        ll n, q; cin >> n >> q;
        
        vector<ll> ans(n+2, 0);
        vector<ll> compute(n+2, 0);// include end compensation and += ans
        
        
        for (ll i = 0; i < q; i++) {
            ll l, r; cin >> l >> r;
            ans[l] += 1;
            ans[l] %= MOD;
            ans[r+1] -= fib[r-l+2];
            ans[r+1] %= MOD;
            compute[r] -= fib[r-l+1];
            compute[r] %= MOD;
        }
        
        for (ll i = 1; i <= n; i++) {
            compute[i] += ans[i];
            compute[i] %= MOD;
            ans[i+1] += compute[i-1] + ans[i];
            ans[i+1] %= MOD;
            cout << ans[i] % MOD << " ";
        }
        cout << endl;
    }
}