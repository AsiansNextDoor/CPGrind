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
        map<int, int> a;
        for (int i = 0; i < n; i++) {
            int ai; cin >> ai;
            a[ai]++;
        }
        int i;
        for (i = 0; i <= n; i++) {
            if (a[i] <= 0) break;
            a[i + x] += a[i] - 1;
        }
        cout << i << endl;
    }
}