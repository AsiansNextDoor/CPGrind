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

signed main()
{
    IOS;

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<vector<ll>> a(n, vector<ll>(3, 0));
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i][0] >> a[i][1];
            if (a[i][0] > a[i][1])
            {
                swap(a[i][0], a[i][1]);
                a[i][2] = 1;
            }
        }

        sort(a.begin(), a.end());

        for (auto i : a)
        {
            if (i[2])
                swap(i[0], i[1]);
            cout << i[0] << " " << i[1] << " ";
        }
        cout << endl;
    }
}