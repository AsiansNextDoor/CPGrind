#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
#define f first
#define s second

ll solve(string s) {
    ll sum = 0;
    ll n = s.length();
    ll fix = 0;
    ll ten = pow(10, n);
    for (ll i = 0; i < n; i++) {
        ten /= 10;
        ll val = s[i] - '0';
        ll remain = n-1 - i;
        for (ll j = 0; j < val; j++) {
            sum += (fix + j) * ten + 45 * ten / 10 * remain;
        }
        fix += val;
    }

    return sum + fix;
}

signed main() {
    IOS;
    ll t; cin >> t;
    while (t--) {
        ll left;
        string right; 
        cin >> left >> right;
        if (left > 0) left--;
        

        ll ans = solve(right) - solve(to_string(left));
        cout << ans << endl;
    }
}