#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

ll n, timec, timem;
vector<vector<ll>> cows(100, vector<ll>(3)); // cookies, muffins, wait

bool check(ll m) { //money
    ll maxl=0, minr=1e9; //range of possible changes to cookie efficiency

    for (ll i = 0; i < n; i++) {
        ll crate = cows[i][0];
        ll mrate = cows[i][1];
        ll target = cows[i][2];

        ll tot, ccount, mcount, l, r;
        if (crate > mrate) {
            if (m > timec-1) {
                ccount = timec-1;
                mcount = min(m - ccount, timem-1);
            }
            else {
                ccount = m;
                mcount = 0;
            }
            tot = crate*(timec - ccount) + mrate*(timem - mcount);
            if (tot > target) return false;
            
            ll diffrate = crate - mrate;
            ll diff;
            if (diffrate == 0) {
                diff = 1e9;
            }
            l = max(ccount-diff, 0LL);
            r = ccount;
        }
        else {
            if (m > timem-1) {
                mcount = timem-1;
                ccount = min(m - mcount, timec-1);
            }
            else {
                mcount = m;
                ccount = 0;
            }
            tot = crate*(timec - ccount) + mrate*(timem - mcount);
            if (tot > target) return false;
            
            ll diffrate = mrate - crate;
            ll diff;
            if (diffrate == 0) {
                diff = 1e9;
            }
            else diff = (target - tot) / diffrate;
            l = ccount;
            r = min(ccount+diff, timec-1);
        }

        cout << "l: " << l << endl;
        cout << "r: " << r << endl;
        cout << endl;

        maxl = max(l, maxl);
        minr = min(r, minr);
    }

    if (maxl > minr) return false;
    cout << maxl << " " << minr << endl;
    return true;
}

signed main() {
    IOS;
    ll t; cin >> t;
    while (t--) {
        cin >> n >> timec >> timem;
        for (ll i = 0; i < n; i++) cin >> cows[i][0] >> cows[i][1] >> cows[i][2];

        ll l = 0, r = timec+timem-2, ans = 5;
        while (l <= r) {
            ll mid = (l + r) / 2;
            if (check(mid)) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        cout << ans << endl;
    }
}