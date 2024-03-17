#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

ll n, tc, tm;
vector<vector<ll>> cows(100, vector<ll>(3));

bool checkc (ll x, ll m) {
    //cout << x << " xm " << m << endl;
    for (ll i = 0; i < n; i++) {
        ll a = cows[i][0], b = cows[i][1], c = cows[i][2];
        if (a < b) continue;
        
        ll tot = a*(tc-x) + b*(tm-(m-x));
        //cout << tot << " " << c << endl;
        if (tot > c) return false;
    }

    return true;
}

bool checkm (ll x, ll m) {
    for (ll i = 0; i < n; i++) {
        ll a = cows[i][0], b = cows[i][1], c = cows[i][2];
        if (a >= b) continue;
        
        ll tot = a*(tc-(m-x)) + b*(tm-x);
        if (tot > c) return false;
    }

    return true;
}

bool check (ll x) {
    ll c = tc-1, m = tm-1;
    ll l = 0, r = min(tc-1, x);
    while (l <= r) {
        ll mid = (l + r) / 2;
        //cout << "mid: " << mid << endl;
        if (checkc(mid, x)) {
            c = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
        //cout << endl << endl;
    }

    
    l = 0, r = min(tm-1, x);
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (checkm(mid, x)) {
            m = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    //cout << x << " " << c << " " << m << endl;
    if (c + m > x) return false;
    return true;
}

signed main() {
    IOS;
    ll t; cin >> t;
    while (t--) {
        cin >> n >> tc >> tm;
        for (ll i = 0; i < n; i++) cin >> cows[i][0] >> cows[i][1] >> cows[i][2];

        ll l = 0, r = tc+tm-2, ans = 0;
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