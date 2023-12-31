#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define f first
#define s second

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n1, n2, n3; cin >> n1 >> n2 >> n3;
    vector<ll> a(n1), b(n2), c(n3);
    ll tot = 0, sa = 0, sb = 0, sc = 0, ma = 1e9, mb = 1e9, mc = 1e9;
    for (ll i = 0; i < n1; i++) {
        cin >> a[i];
        tot += a[i];
        sa += a[i];
        ma = min(a[i], ma);
    }
    for (ll i = 0; i < n2; i++) {
        cin >> b[i];
        tot += b[i];
        sb += b[i];
        mb = min(b[i], mb);
    }
    for (ll i = 0; i < n3; i++) {
        cin >> c[i];
        tot += c[i];
        sc += c[i];
        mc = min(c[i], mc);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    if (n1 > n2) {
        swap(n1, n2);
        swap(a, b);
        swap(sa, sb);
        swap(ma, mb);
    }
    if (n2 > n3) {
        swap(n2, n3);
        swap(b, c);
        swap(sb, sc);
        swap(mb, mc);
    }
    if (n1 > n2) {
        swap(n1, n2);
        swap(a, b); 
        swap(sa, sb);
        swap(ma, mb);
    }

    if (n1 == 1) {
        if (n2 == 1) {
            cout << tot - 2*min(min(sa, sb), sc);
        }
        else {
            cout << tot - 2*min(mb + mc, min(sa, min(sb, sc))) << endl;
        }
    }
    else {
        ll min1 = 1e9, min2 = 1e9;
        for (ll i = 0; i < n1; i++) {
            if (a[i] < min2) min2 = a[i];
            if (min2 < min1) swap(min1, min2);
        }
        for (ll i = 0; i < n2; i++) {
            if (b[i] < min2) min2 = b[i];
            if (min2 < min1) swap(min1, min2);
        }
        for (ll i = 0; i < n3; i++) {
            if (c[i] < min2) min2 = c[i];
            if (min2 < min1) swap(min1, min2);
        }

        cout << tot - 2*min(min(min(sa, sb), sc) ,min(mb + mc, min(mb + ma, ma + mc))) << endl;
    }
} 