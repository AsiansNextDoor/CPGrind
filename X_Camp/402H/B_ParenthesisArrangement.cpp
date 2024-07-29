#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

signed main() {
    IOS;

    ll n, a, b; cin >> n >> a >> b;
    string s; cin >> s;

    ll o = 0, c = 0;
    for (ll i = 0; i < 2 * n; i++) {
        if (s[i] == '(') o++;
        else c++;
    }
    a = min(2 * b, a);

    ll ans = 0;
    if (o < n) {
        ll diff = n - o;
        ll i = 0;
        while (diff--) {
            while (s[i] != ')') i++;
            s[i] = '(';
            i++;
            ans += b;
        }
    }
    else if (c < n) {
        ll diff = n - c;
        ll i = 2 * n - 1;
        while (diff--) {
            while (s[i] != '(') i--;
            s[i] = ')';
            i--;
            ans += b;
        }
    }

    ll minp = 0, p = 0;
    for (ll i = 0; i < 2 * n; i++) {
        if (s[i] == '(') p++;
        else p--;
        minp = min(p, minp);
    }

    if (minp < 0)ans += ((minp * -1) + 1) / 2 * a;
    cout << ans << endl;
}