#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

signed main() {
    IOS;

    freopen("cowrun.in", "r", stdin);
    freopen("cowrun.out", "w", stdout);
    
    ll n; cin >> n;
    vector<ll> left, right; left.push_back(0); right.push_back(0);
    for (ll i = 0; i < n; i++) {
        ll p; cin >> p;
        if (p > 0) right.push_back(p);
        else left.push_back(-p);
    }
    
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    ll l = left.size(), r = right.size();
    vector<vector<vector<ll>>> dp(l+1, vector<vector<ll>>(r+1, vector<ll>(2, 2e9))); // left cows, right cows, sign
    dp[0][0][0] = 0;
    dp[0][0][1] = 0;
    for (ll i = 0; i < l; i++) {
        for (ll j = 0; j < r; j++) {
            for (ll sign = 0; sign <= 1; sign++) {
                ll step;
                ll cows = n - (i + j);
                if (i != l - 1) {
                    if (sign == 0) {
                        step = left[i+1] - left[i];
                    }
                    else {
                        step = left[i+1] + right[j];
                    }
                    dp[i+1][j][0] = min(dp[i][j][sign] + step * cows, dp[i+1][j][0]);
                }
                if (j != r - 1) {
                    if (sign == 0) {
                        step = right[j+1] + left[i];
                    }
                    else {
                        step = right[j+1] - right[j];
                    }
                    dp[i][j+1][1] = min(dp[i][j][sign] + step * cows, dp[i][j+1][1]);
                }
            }
        }
    }

    cout << min(dp[l-1][r-1][0], dp[l-1][r-1][1]) << endl;
}