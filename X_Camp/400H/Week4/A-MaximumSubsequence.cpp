#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
    ll n, m; cin >> n >> m;
    
    vector<ll> first; vector<ll> second;

    for (ll i = 0 ; i < n; i++) {
        ll a; cin >> a;
        if (i < n/2) {
            first.push_back(a % m);
        }
        else {
            second.push_back(a % m);
        }
    }
    
    vector<ll> s1;
    vector<ll> s2;
    
    for (ll bit = 0; bit < (1 << first.size()); bit++) {
        ll c = 0;
        for (ll i = 0; i < first.size(); i++) {
            if ((bit >> i) & 1) {
                c += first[i];
            }
        }
        s1.push_back(c % m);
    }
    
    for (ll bit = 0; bit < (1 << second.size()); bit++) {
        ll c = 0;
        for (ll i = 0; i < second.size(); i++) {
            if ((bit >> i) & 1) {
                c += second[i];
            }
        }
        s2.push_back(c % m);
    }
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    ll maxc = 0;
    for (ll i = 0; i < s1.size(); i++) {
        auto it2 = lower_bound(s2.begin(), s2.end(), m-s1[i]);
        if (it2 != s2.begin()) {
            it2--;
        }
        else {
            it2 = s2.end()-1;
        }
        maxc = max((s1[i]+*it2)%m, maxc);
    }
    
    cout << maxc << endl;
}