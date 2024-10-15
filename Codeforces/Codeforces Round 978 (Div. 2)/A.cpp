//#pragma GCC optimize ("trapv")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int INF, MOD;

signed main() {
    IOS;

    int t; cin >> t;
    while (t--) {
        int n, r; cin >> n >> r;
        int tot = 0;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            tot += a[i];
        }
        int diff = r * 2 - tot;

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += a[i] / 2 * 2;
            if (diff) {
                diff -= a[i] % 2;
                ans += a[i] % 2;
            }
        }

        cout << ans << endl;
    }
}