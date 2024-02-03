#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

signed main() {
    IOS;
    
    ll i = 1;
    set<ll> right;
    while (i * (i + 1) / 2 <= 2e6) {
        right.insert(i * (i + 1) / 2);
        i++;
    } 


    vector<ll> dp(3e6+1, -1);

    dp[1] = 0;
    dp[2] = 5;
    ll rprev = 1;
    ll lprev = 1;
    for (auto it = right.begin(); it != right.end(); it++) {
        dp[*it] = dp[rprev] + (*it) * (*it);
        rprev = *it;

        dp[rprev+1] = dp[lprev] + (rprev+1) * (rprev+1);
        lprev = rprev + 1; 
    }
    for (ll i = 2; i <= 1e6; i++) {
        if (dp[i] != -1) continue;
        auto it = right.upper_bound(i);
        auto it2 = it;
        it2--;
        ll diff = *it - *it2;
        ll l = i - diff;
        ll r = i - diff + 1;
        ll ovlp = r - (diff - 1);
        dp[i] = dp[l] + dp[r] + i * i - dp[ovlp];
    }
    //cout << dp[1] << endl;
    //cout << dp[2] << " " << dp[3] << endl;
    //cout << dp[4] << " " << dp[5] << " " << dp[6] << endl;
    //cout << dp[7] << " " << dp[8] << " " << dp[9] << " " << dp[10] << endl;
    
    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        cout << dp[n] << endl;
    }

    //change ll to ll
}