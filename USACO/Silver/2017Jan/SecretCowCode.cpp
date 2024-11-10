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

    freopen("cowcode.in", "r", stdin);
    freopen("cowcode.out", "w", stdout);

    string s; cin >> s;
    ll n; cin >> n;

    ll greed = s.size();
    while (greed < n) greed *= 2;
    greed /= 2;

    while (n > s.size()) {
        if (n - 1 == greed) n--;
        else if (n > greed) {
            n -= greed;
            n--;
        }
        greed /= 2;
    }

    cout << s[n - 1] << endl;
}