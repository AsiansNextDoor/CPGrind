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

int INF, MOD;

signed main()
{
    IOS;

    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);

    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        cin >> a[i][0] >> a[i][2];
        a[i][1] = i;
    }

    sort(a.begin(), a.end());

    int atime = 0, ans = 0;
    set<vector<int>> s;
    for (int i = 0; i < n; i++)
    {
        int t = a[i][0], dur = a[i][2], rank = a[i][1];
        while (!s.empty() && atime < t)
        {
            auto it = s.begin();
            if (atime < (*it)[1])
                atime = (*it)[1];
            ans = max(atime - (*it)[1], ans);
            atime += (*it)[2];
            s.erase(it);
        }

        s.insert({rank, t, dur});
    }
    while (!s.empty())
    {
        auto it = s.begin();
        ans = max(atime - (*it)[1], ans);
        atime += (*it)[2];
        s.erase(it);
    }

    cout << ans << endl;
}