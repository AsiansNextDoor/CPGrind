#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define f first
#define s second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const ll maxv = 2e9;

signed main() {
    IOS;
    ll n, q; cin >> n >> q;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];

    vector<ll> fcost(61);


    for (ll i = 1; i <= 60; i++) {
        ll count = 0;
        ll andv = (1LL << i) - 1;
        for (ll j = 0; j < n; j++) {
            ll cur = a[j] & andv;
            ll bit = (1LL << (i - 1));
            count += max((ll)0, bit - cur);
        }

        fcost[i] = count;
    }
    
    
    for (ll i = 1; i < 10; i++) {
        cout << fcost[i] << " ";
    }
    cout << endl;

    while (q--) {
        ll k; cin >> k;
        ll i = 60;
        ll mand = 0;
        for (i; i >= 1; i--) {
            if (fcost[i] <= k) {
                k -= fcost[i];
                cout << "fcost: " << fcost[i] << endl;
                mand += (1LL << (i-1)); cout << "mand: " << mand << endl;;
                break;
            }
        }

        cout << k << endl;
        mand += k / n;

        cout << mand << endl;
    }
}