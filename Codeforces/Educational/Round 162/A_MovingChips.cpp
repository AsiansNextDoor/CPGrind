#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

signed main() {
    IOS;
    ll t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n+1);
        for (int i = 1; i <= n; i++) cin >> a[i];

        bool block = false;
        int ans = 0;
        int extra = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == 1) {
                block = true;
                extra = 0;
            }
            else if (block) {
                ans++;
                extra++;
            }
        }
        cout << ans - extra << endl;
    }
}