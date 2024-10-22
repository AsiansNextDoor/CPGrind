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
        string a;
        cin >> a;

        string ans = "NO";
        if (a[0] == '1' || a[n - 1] == '1')
            ans = "YES";
        for (int i = 1; i < n - 2; i++)
        {
            if (a[i] == '1' && a[i + 1] == '1')
                ans = "YES";
        }

        cout << ans << endl;
    }
}