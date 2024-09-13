#pragma GCC optimize ("trapv")
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second
 
ll MOD = 1420696969;
 
long long convert(char c){
    return (long long)(c-'a'+1);
}

signed main() {
    IOS;
 
    
    ll p = 31ll;
    vector<ll> ppows(1e6, 1ll);
    for (ll i = 1; i < 1e6; i++) ppows[i] = (ppows[i - 1] * p) % MOD;
 
    string s; cin >> s;
    ll n = s.size();
    string c; cin >> c;
    ll m = c.size();
 
 
    vector<ll> psum(n + 1, 0ll);
    for (ll i = 0; i < n; i++) psum[i + 1] = (psum[i] + ((convert(s[i])) * ppows[i])) % MOD;
 
    ll hash = 0ll;
    for (ll i = 0; i < m; i++) hash = (hash + ((convert(c[i])) * ppows[i])) % MOD;
 
    ll ans = 0ll;
    for (ll i = 0; i <= n - m; i++) {
        ll subs = (psum[i + m] - psum[i] + MOD) % MOD;
        if (((hash * ppows[i]) % MOD) == subs) ans++;
    }
 
    cout << ans << endl;
}