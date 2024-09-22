//#pragma GCC optimize ("trapv")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int INF, MOD;

void check(int x) {
    if (x % 2) cout << "NO" << endl;
    cout << "YES" << endl;
}

signed main() {
    IOS;

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        if (n <= k) check(n);
        else {
            if (k % 2 == 0) cout << "YES" << endl;
            else if (n % 2) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}