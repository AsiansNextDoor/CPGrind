//#pragma GCC optimize ("trapv")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

ll INF, MOD = 998244353;

int cnt = 0, n;
string s;
int order(int u) {
    if (2 * u < pow(2, n)) cnt += order(2 * u) ^ order(2 * u + 1);
    return 'B' - s[u - 1];
}

signed main() {
    IOS;

    cin >> n;
    cin >> s;

    ll ans = 1;
    for (int i = 0; i < cnt; i++) {
        ans *= 2;
        ans %= MOD;
    }

    cout << ans << endl;
}