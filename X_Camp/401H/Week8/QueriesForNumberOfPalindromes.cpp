#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

signed main() {
    IOS;

    string s; cin >> s;
    int n = s.length();
    vector<vector<int>> a(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) a[i][i] = 1;

    for (int len = 1; len < n-1; len++) {
        for (int i = 0; i < n-len; i++) {
            int j = i + len;

            if (s[i] != s[j]) continue;
            if (len > 1 && a[i+1][j-1] == 0) continue;
            
            a[i][j] = 1;
        }
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = i; j < n; j++) {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) dp[i][i] = 1;
    
    for (int len = 1; len <= n-1; len++) {
        for (int i = 0; i < n-len; i++) {
            int j = i + len;
            dp[i][j] += dp[i][j-1] + dp[i+1][j] + a[i][j];
            if (len > 1) dp[i][j] -= dp[i+1][j-1];
        }
    }
    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        cout << dp[l-1][r-1] << endl;
    }
}