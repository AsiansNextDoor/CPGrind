//#pragma GCC optimize ("trapv")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

ll INF, MOD;

ll n, k; 
bool check(ll i) {
    ll left = (i) * (i + 1) / 2 + i * k;
    ll right = (n) * (n + 1) / 2 - (i) * (i + 1) / 2 + (n - i) * k;
    ll x = left - right;
    if (x >= 0) return true;
    return false;
}

signed main() {
    IOS;

    ll t; cin >> t;
    while (t--) {
        cin >> n >> k;

        ll l = 1;
        ll r = n, mid;
        ll ans = n;
        while (l <= r) {
            mid = (l + r) / 2;
            if (check(mid)) {
                ans = min(ans, mid);
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        ll left = (ans - 1) * (ans) / 2 + ans * k;
        ll right = (n - 1) * (n) / 2 - (ans - 1) * (ans) / 2 + (n - ans) * k;
        ll x1 = left - right;
        ans--;
        left = (ans - 1) * (ans) / 2 + ans * k;
        right = (n - 1) * (n) / 2 - (ans - 1) * (ans) / 2 + (n - ans) * k;
        ll x2 = left - right;
        
        cout << min(abs(x1), abs(x2)) << endl;
    }
}