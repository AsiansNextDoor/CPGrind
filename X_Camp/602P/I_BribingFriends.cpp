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

    ll n, a, b;
    cin >> n >> a >> b;
    vector<vector<ll>> cows(n, vector<ll>(3));
    for (ll i = 0; i < n; i++)
    {
        cin >> cows[i][2] >> cows[i][1] >> cows[i][0];
    }

    sort(cows.begin(), cows.end());

    vector<vector<ll>> dp(n + 1, vector<ll>(a + b + 1, 0));

    for (ll i = 0; i < n; i++)
    {
        ll x = cows[i][0], c = cows[i][1], p = cows[i][2];

        for (ll j = 0; j <= a + b; j++)
        {
            dp[i + 1][j] = max(dp[i][j], dp[i + 1][j]);
            if (j + x * c <= b)
            {
                dp[i + 1][j + x * c] = max(dp[i][j] + p, dp[i + 1][j + x * c]);
            }
            else if (j < b)
            {
                dp[i + 1][b + (c - (b - j) / x)] = max(dp[i][j] + p, dp[i + 1][b + (c - (b - j) / x)]);
            }
            else if (c + j <= a + b)
            {
                dp[i + 1][j + c] = max(dp[i][j] + p, dp[i + 1][j + c]);
            }
        }
    }

    cout << dp[n][a + b] << endl;
}