#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

ll m, magicd; 
ll MOD = 1e9 + 7;
vector<vector<ll>> dvalid(2);
//dp[length][remainder]
vector<vector<ll>> dp1(2001, vector<ll>(2000, 0));
//dp[length][remainder][tight]
vector<vector<vector<ll>>> dp2(2001, vector<vector<ll>>(2000, vector<ll>(2, 0)));

ll solve(string s) {
    ll ans = 0;
    ll len = s.length();
    dp1[0][0] = 1;
    for (ll i = 0; i < len; i++) {
        for (ll j = 0; j < m; j++) {
            dp1[i][j] %= MOD;
            
            for (ll d: dvalid[i%2]) {
                if (i == 0 && d == 0) continue;
                ll nj = (j * 10 + d) % m;
                dp1[i+1][nj] += dp1[i][j];
            }
        }
    }
    for (ll i = 0; i < len; i++) ans += dp1[i][0];
    ans %= MOD;

    dp2[0][0][1] = 1;
    for (ll i = 0; i < len; i++) {
        for (ll j = 0; j < m; j++) {
            dp2[i][j][0] %= MOD;
            dp2[i][j][1] %= MOD;
            for (ll d: dvalid[i%2]) {
                if (i == 0 && d == 0) continue;
                ll nj = (j * 10 + d) % m;
                ll c = s[i] - '0';
                if (d == c) dp2[i+1][nj][1] += dp2[i][j][1];
                else if (d < c) dp2[i+1][nj][0] += dp2[i][j][1];
                dp2[i+1][nj][0] += dp2[i][j][0];
            }
        }
    }
    

    ans += dp2[len][0][0] + dp2[len][0][1];
    ans %= MOD;

    return ans;
}


signed main() {
    IOS;

    cin >> m >> magicd;
    for (ll i = 0; i <= 9; i++) if (i != magicd) dvalid[0].push_back(i);
    dvalid[1].push_back(magicd);
    string a, b; cin >> a >> b;
    

    // subtract 1 from string a
    for (ll i = a.length()-1; i >= 0; i--) {
        if (a[i] == '0') a[i] = '9';
        else {
            a[i]--;
            break;
        }
    }
    if (a[0] == '0' && a.length() != 1) a = a.substr(1, a.length());

    ll sb = solve(b);
    for (int i = 0; i <= a.length(); i++) {
        for (int j = 0; j < m; j++) {
            dp1[i][j] = 0;
            dp2[i][j][0] = 0;
            dp2[i][j][1] = 0;
        }
    }
    ll sa = solve(a);
    cout << (sb - sa + MOD) % MOD  << endl;
}