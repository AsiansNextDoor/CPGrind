//#pragma GCC optimize ("trapv")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

ll INF, MOD;

signed main() {
    IOS;

    ll t; cin >> t;
    while (t--) {
        ll n, x; cin >> n >> x;
        multiset<ll> a;
        ll tot = 0;
        for (ll i = 0; i < n; i++) {
            ll ai; cin >> ai;
            tot += ai;
            a.insert(ai);
        }

        ll cur = 0;
        multiset<ll> cura;
        
        ll i = 0;
        auto it2 = a.end(); it2--;
        ll most = *it2;
        if (most < tot - most) {
            cout << (tot - 1) / x + 1  << endl;
        } 
        else {
            while (!a.empty()) {
                while (!cura.empty() && *cura.begin() <= cur) cura.erase(cura.begin());
                while (cura.size() < x && !a.empty()) {
                    auto it = a.end(); it--;
                    cura.insert(*it + cur);
                    a.erase(it);
                }

                cur = *cura.begin();
            }
            auto it = cura.end(); it--;
            cout << *it << endl;
        }
    }
}