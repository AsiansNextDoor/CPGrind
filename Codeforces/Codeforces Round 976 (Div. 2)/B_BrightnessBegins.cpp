//#pragma GCC optimize ("trapv")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int INF, MOD;

bool square(int x) {
    int y = floor(sqrt(x));
    if (y * y != x) return false;
    return true;
}

signed main() {
    IOS;

    int t; cin >> t;
    while (t--) {
        int k; cin >> k;
        int x = floor(sqrt(k));
        int diff = floor(sqrt(k));
        int n = k + x;
        while ((x + 1) * (x + 1) - k < diff) {
            x++;
            n++
        }
        cout << n << endl;
    }
}