#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int INF;

signed main() {
    IOS;

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> b(n);
        for (int i = 0; i < n; i++) cin >> b[i];

        vector<int> pmax(n, b[0]);
        vector<int> smax(n, b[n - 1] - (n - 1));

        for (int i = 1; i < n; i++) pmax[i] = max(b[i] + i, pmax[i - 1]);
        for (int i = n - 2; i >= 0; i--) smax[i] = max(b[i] - i, smax[i + 1]);

        int ans = 0;
        for (int i = 1; i < n - 1; i++) ans = max(pmax[i - 1] + b[i] + smax[i + 1], ans);

        cout << ans << endl;
    }
}