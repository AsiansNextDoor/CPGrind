#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

signed main() {
    IOS;

    ll n, m; cin >> n >> m;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];

    for (ll i = 0; i < n; i++) a[i] -= (i+1) * m;
    
    reverse(a.begin(), a.end());
    cout << endl;
    vector<ll> seq; seq.push_back(-1e9);
    for (ll i = 0; i < n; i++) {
        if (a[i] > 0) continue;
        else if (seq.back() <= a[i]) seq.push_back(a[i]);
        else {
            ll ind = upper_bound(seq.begin(), seq.end(), a[i]) - seq.begin();
            seq[ind] = a[i];
        }
    }
    
    cout << n - (ll)seq.size() + 1 << endl;
}