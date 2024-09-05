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
        int x, y, k; cin >> x >> y >> k;
        int xans = x / k + !!(x % k);
        int yans = y / k + !!(y % k);
        if (xans > yans) cout << xans * 2 - 1;
        else cout << yans * 2;
        cout << endl;
    }
}