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

ull INF, MOD = 1e9 + 7;

signed main()
{ // turn everything ullo ull
    IOS;

    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

    ll t;
    cin >> t;
    while (t--)
    {
        ull n, q;
        cin >> n >> q;
        vector<ull> a(n);
        for (ull i = 0; i < n; i++)
            cin >> a[i];

        string s;
        cin >> s;

        vector<ull> hash(n + 1, 0);
        for (ull i = 1; i <= n; i++)
        {
            hash[i] = rng() % MOD;
        }

        vector<ull> h_asc(n + 1, 0);
        for (ull i = 1; i <= n; i++)
            h_asc[i] = (hash[i] + h_asc[i - 1]) % MOD;

        vector<ull> h_p(n + 1, 0);
        for (ull i = 1; i <= n; i++)
            h_p[i] = (hash[a[i - 1]] + h_p[i - 1]) % MOD;

        set<ull> ls, rs;
        ls.insert(0ULL);
        rs.insert(n + 1);
        for (ull i = 0; i < n; i++)
        {
            if (s[i] == 'L')
                ls.insert(i + 1);
            else
                rs.insert(i + 1);
        }

        set<ull> mismatch;
        ull cur = 1;
        while (cur <= n)
        {
            auto it = rs.upper_bound(*(ls.upper_bound(cur)));
            if (h_p[*it - 1] - h_p[cur - 1] != h_asc[*it - 1] - h_asc[cur - 1])
            {
                mismatch.insert(h_p[*it - 1] - h_p[cur - 1]);
            }
            cur = *it;
        }
        while (q--)
        {
            ull idx;
            cin >> idx;
            for (ull i = idx - 1; i <= idx + 1; i++)
            {
                auto it1 = rs.upper_bound(i);
                it1--;
                auto l = ls.upper_bound(*it1);
                l--;

                auto it = rs.upper_bound(*(ls.lower_bound(i)));

                auto it2 = mismatch.find(h_p[*it - 1] - h_p[*l]);
                if (it2 != mismatch.end())
                    mismatch.erase(it2);
            }

            if (s[idx - 1] == 'L')
            {
                ls.erase(ls.find(idx));
                rs.insert(idx);
                s[idx - 1] = 'R';
            }
            else
            {
                rs.erase(rs.find(idx));
                ls.insert(idx);
                s[idx - 1] = 'L';
            }

            for (ull i = idx - 1; i <= idx + 1; i++)
            {
                auto it1 = rs.upper_bound(i);
                it1--;
                auto l = ls.upper_bound(*it1);
                l--;

                auto it = rs.upper_bound(*(ls.lower_bound(i)));

                if (h_p[*it - 1] - h_p[*l] != h_asc[*it - 1] - h_asc[*l])
                {
                    mismatch.insert(h_p[*it - 1] - h_p[*l]);
                }
            }

            if (mismatch.empty())
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
}