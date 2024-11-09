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

const ll INF = 10000000000000000;

signed main()
{
    IOS;

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll tot = 0;
        vector<ll> a(n), b(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            tot += a[i];
        }
        for (ll i = 0; i < n; i++)
            cin >> b[i];

        vector<ll> d(n, INF);
        d.assign(n, INF);

        d[0] = 0;

        ll visited = 1;
        multiset<ll> s;
        vector<vector<ll>> rem(n + 1);
        for (ll i = 0; i < visited; i++)
        {
            for (ll j : rem[i])
                s.erase(s.find(j));
            if (!s.empty())
                d[i] = *s.begin();
            if (d[i] + a[i] < d[b[i] - 1])
            {
                d[b[i] - 1] = d[i] + a[i];
                s.insert(d[i] + a[i]);
                rem[b[i]].push_back(d[i] + a[i]);
            }
            visited = max(b[i], visited);
        }
        ll missed = 0, ans = tot;
        for (ll i = n - 1; i >= 0; i--)
        {
            ans = min(d[i] + missed, ans);
            missed += a[i];
        }

        cout << tot - ans << endl;
    }
}