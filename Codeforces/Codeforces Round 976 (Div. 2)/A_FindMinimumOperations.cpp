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

    int n, k; cin >> n >> k;
    int ans = 0;
    while (n > 0) {
        int tot = 1;
        while (tot < n) {
            tot *= k;
        }
        n -= tot;
        ans++;
    }
    cout << ans << endl;
}