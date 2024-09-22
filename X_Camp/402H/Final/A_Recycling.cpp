#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

ll INF;

signed main() {
    IOS;

    ll n; cin >> n;
    vector<ll> week(n);
    for (ll i = 0; i < n; i++) cin >> week[i];

    stack<vector<ll>> stk;
    vector<ll> left(n, 0), right(n, n);
    for (ll i = 0; i < n; i++) {
        ll cur = week[i];
        while (!stk.empty() && (stk.top())[0] >= cur) stk.pop();
        if (!stk.empty()) left[i] = (stk.top())[1] + 1;
        else left[i] = 0;
        stk.push({cur, i});
    }
    while (!stk.empty()) stk.pop();
    for (ll i = n - 1; i >= 0; i--) {
        ll cur = week[i];
        while (!stk.empty() && (stk.top())[0] >= cur) stk.pop();
        if (!stk.empty()) right[i] = (stk.top())[1];
        else right[i] = n;
        stk.push({cur, i});
    }

    ll ans = 0, l, r;
    for (ll i = 0; i < n; i++) {
        ll tot = (right[i] - left[i]) * week[i];
        if (tot > ans) {
            ans = tot;
            l = left[i] + 1;
            r = right[i];
        } 
        else if (tot == ans) {
            if (l > left[i]) {
                l = left[i] + 1;
                r = right[i];
            }
        }
    }
    cout << l << " " << r << " " << ans << endl;
}