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

ll INF, MOD = 1e9 + 7;

signed main()
{
    IOS;

    ll t;
    cin >> t;
    vector<ll> n(t);
    vector<ll> k(t);
    for (ll i = 0; i < t; i++)
        cin >> n[i];
    for (ll i = 0; i < t; i++)
        cin >> k[i];

    vector<ll> pow2(1e5 + 1, 1);
    for (ll i = 1; i <= 1e5; i++)
    {
        pow2[i] = pow2[i - 1] * 2;
        pow2[i] %= MOD;
    }

    for (ll i = 0; i < t; i++)
        cout << pow2[k[i]] << endl;
    /*
        ll N = 10;
        vector<vector<ll>> C(N, vector<ll>(N));
        for (ll n = 0; n < N; n++) {
            C[n][0] = 1;
            C[n][n] = 1;
            for (ll k = 1; k < n; k++) {
                C[n][k] = C[n][k - 1] + C[n - 1][k - 1];
            }
        }

        for (ll i = 0; i < N; i++) {
            for (ll j = 0; j < N; j++) cout << C[i][j] << " ";
            cout << endl;
        }*/
}