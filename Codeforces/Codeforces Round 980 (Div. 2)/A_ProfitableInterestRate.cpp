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

    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        if (a >= b)
        {
            cout << a << endl;
            continue;
        }
        a -= b - a;
        if (a < 0)
            cout << 0 << endl;
        else
            cout << a << endl;
    }
}