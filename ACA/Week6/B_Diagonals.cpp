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
        int n, k; cin >> n >> k;
        int flip = 0, ans = 0;
        while (k > 0) {
            k -= n;
            if (!flip) n--;
            flip = 1 - flip;
            ans++;
        }

        cout << ans << endl;
    }
}