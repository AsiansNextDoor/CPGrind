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
        int n, x; cin >> n >> x;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int l = 1, r = n + 1;
        while (l < r - 1) {
            int mid = (l + r) / 2;
            if (a[mid - 1] <= x) l = m;
            else r = m;
        }

        int ans;
        for (int i = 0; i < n; i++) if (a[i] == x) ans = i + 1;
        cout << 1 << endl;
        cout << ans << " " << l << endl;
    }
}