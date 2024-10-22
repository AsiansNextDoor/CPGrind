// #pragma GCC optimize ("trapv")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define endl "\n"

ull INF, MOD = 998244353;

signed main()
{
    IOS;

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
            cin >> a[i];

        sort(a.begin(), a.end());

        ll cur = 0, left = k;
        ll i = 0;
        for (i; i < n; i++)
        {
            ll diff = a[i] - cur;
            left -= diff * (n - i);
            if (left <= 0)
                break;
            cur = a[i];
        }

        cout << k + i << endl;
    }
}