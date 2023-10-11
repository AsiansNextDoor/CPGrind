#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        string s; cin >> s;
        vector<ll> arr(n+1, 0);
        
        for (ll i = 0; i < n; i++) {
            arr[i+1] = s[i] - '0';
        }
        
        for (ll i = 1; i <= n; i++) {
            arr[i] += arr[i-1];
        }
        
        map<ll, ll> m;
        for (ll i = 0; i <= n; i++) {
            m[arr[i]-i]++;
        }
        
        ll ans = 0;
        for (auto it = m.begin(); it != m.end(); it++) {
            ans += it->second * (it->second-1) / 2;
        }
        
        cout << ans << endl;
    }
}