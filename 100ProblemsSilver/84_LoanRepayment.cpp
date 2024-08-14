#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

ll INF;

ll n, k, m;

bool check(ll x) {
    ll g = 0;

    ll cur = 0;
    ll y = (n - g) / x;
    while (y >= m && g < n) {
        g += y;
        y = (n - g) / x;
        cur++;
    }
    if (g < n) cur += (n - g + m - 1) / m;
    if (cur > k) return false;
    return true;
}

signed main() {
    cin >> n >> k >> m;

    ll l = 1;
    ll r = n, mid;
    ll ans = 1;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (check(mid))
        {
            ans = max(ans, mid);
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    cout << ans << endl;
}