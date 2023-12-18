#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        ll rsum = 0;
        vector<ll> merge;
        for (ll i = n-1; i > 0; i--) {
            rsum += a[i];
            if (rsum < 0) {
                merge.push_back(1);
            }
            else {
                merge.push_back(0);
            }
        }
        
        merge.push_back(0);
        reverse(merge.begin(), merge.end());
        
        ll ans = 0, ind = 0, digit = 1;
        while (ind < n) {
            ll cur = a[ind];
            while (ind < n-1 && merge[ind+1]) {
                cur += a[ind+1];
                ind++;
            }
            
            ans += cur * digit;
            ind++;
            digit++;
        }
        
        cout << ans << endl;
    }
}