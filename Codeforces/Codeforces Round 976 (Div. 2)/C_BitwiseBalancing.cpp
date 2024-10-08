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
        ll b, c, d; cin >> b >> c >> d;
        ll a = 0LL;

        for (ll bit = 0LL; bit <= 61LL; bit++) {
            ll curb = (1LL << bit) & b;
            ll curc = (1LL << bit) & c;
            ll curd = (1LL << bit) & d;
            if ((curb && !curc && !curd) || (!curb && curc && curd)) {
                a = -1LL;
                break;
            }
            ll b1 = !!(curb);
            ll d1 = !!(curd);
            if (!(b1 == d1)) a |= (1LL << bit);
        }
        if (a > (1LL << 61LL)) a = -1LL;
        cout << a << endl;
    }
}