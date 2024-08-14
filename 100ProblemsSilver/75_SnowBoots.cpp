#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int INF;

signed main() {
    IOS;

    int n, b; cin >> n >> b;

    vector<int> snow(n);
    vector<vector<int>> boots(b, vector<int>(2));
    for (int i = 0; i < n; i++) cin >> snow[i];
    for (int i = 0; i < b; i++) cin >> boots[i][0] >> boots[i][1];

    vector<int> dp(n, b);
    dp[0] = 0;
    for (int tile = 0; tile < n - 1; tile++) {
        for (int boot = dp[tile]; boot < b; boot++) {
            int s = boots[boot][0], d = boots[boot][1];
            if (s < snow[tile]) continue;
            for (int i = tile + 1; i <= min(tile + d, n - 1); i++) {
                if (snow[i] <= s) {
                    dp[i] = min(boot, dp[i]);
                }
            }
        }
    }
    cout << dp[n - 1] << endl;
}