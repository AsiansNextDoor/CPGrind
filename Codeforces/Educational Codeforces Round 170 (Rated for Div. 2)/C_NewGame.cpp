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
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        sort(a.begin(), a.end());

        int ans = 0;
        set<int> s;
        queue<int> q;
        int cur;
        for (int i = 0; i < n; i++)
        {
            if (q.empty())
            {
                q.push(a[i]);
                s.insert(a[i]);
            }
            else
            {
                if (cur + 1 < a[i])
                {
                    queue<int>().swap(q);
                    s.clear();
                }
                else if (s.size() == k && a[i] != cur)
                {
                    int r = q.front();
                    while (!q.empty() && q.front() == r)
                    {
                        q.pop();
                    }
                    s.erase(s.find(r));
                }
                q.push(a[i]);
                s.insert(a[i]);
            }
            ans = max(ans, (int)q.size());
            cur = a[i];
        }

        cout << ans << endl;
    }
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