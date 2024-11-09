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

ll INF, MOD;

signed main()
{
    IOS;

    ll t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);

        int low = 1000, high = 1;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            low = min(a[i], low);
            high = max(a[i], high);
        }

        cout << (high - low) * (n - 1) << endl;
    }
}