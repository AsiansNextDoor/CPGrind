#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

ll MOD = 1e9 + 7;

signed main() {
    IOS;

    vector<ll> dp1(1e6 + 1), dp2(1e6 + 1);
    dp1[1] = 0; // 2 vertical blocks on top
    dp2[1] = 0; // 1 horizontal block on top
    ll d1 = 1, d2 = 1;
    for (ll i = 1; i <= 1e6; i++) {
        dp1[i] = d1;
        dp2[i] = d2;
        d1 *= 4; d1 %= MOD;
        d2 *= 2; d2 %= MOD;
        d1 += dp2[i];
        d2 += dp1[i];
    }

    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        cout << (dp1[n] + dp2[n]) % MOD << endl;
    }
}