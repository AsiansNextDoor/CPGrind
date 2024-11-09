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
        int n; cin >> n;
        int maxw = 0, maxh = 0;
        for (int i = 0; i < n; i++) {
            int w, h; cin >> w >> h;
            maxw = max(w, maxw);
            maxh = max(h, maxh);
        }

        cout << maxh * 2 + maxw * 2 << endl;
    }
}