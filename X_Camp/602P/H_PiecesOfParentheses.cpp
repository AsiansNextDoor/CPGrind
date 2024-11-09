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

/*
sort by
net positive psum is 0
net positive psum < 0
net negative
*/

signed main()
{
    IOS;

    int n;
    cin >> n;
    vector<vector<int>> npos, nneg;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        int minpsum = 0, sum = 0;
        for (char c : s)
        {
            if (c == '(')
                sum++;
            else
                sum--;
            minpsum = min(sum, minpsum);
        }
        int maxrsum = 0, s1 = 0;
        for (int j = s.size() - 1; j >= 0; j--)
        {
            if (s[j] == '(')
                s1++;
            else
                s1--;
            maxrsum = max(s1, maxrsum);
        }
        if (sum >= 0)
            npos.push_back({minpsum, sum, (int)s.size()});
        else
            nneg.push_back({maxrsum, minpsum, sum, (int)s.size()});
    }

    sort(npos.rbegin(), npos.rend());
    sort(nneg.rbegin(), nneg.rend());

    int i = 0;
    vector<vector<int>> dp(n + 1, vector<int>(90001, 0));

    if (!npos.empty() && npos[0][0] >= 0)
        dp[i][npos[0][1]] = npos[0][2];
    for (int j = 1; j < npos.size(); j++)
    {
        auto data = npos[j];
        int mpsum = data[0], sum = data[1], len = data[2];
        for (int j = 0; j <= 90000; j++)
        {
            if (!dp[i][j])
                continue;
            dp[i + 1][j] = max(dp[i][j], dp[i + 1][j]);
            if (j >= max(-mpsum, 0))
                dp[i + 1][j + sum] = max(dp[i][j] + len, dp[i + 1][j + sum]);
        }
        if (mpsum >= 0)
            dp[i + 1][sum] = max(len, dp[i + 1][sum]);
        i++;
    }
    for (int j = 0; j < nneg.size(); j++)
    {
        auto data = nneg[j];
        int mpsum = data[1], sum = data[2], len = data[3];
        for (int j = 0; j <= 90000; j++)
        {
            if (!dp[i][j])
                continue;
            dp[i + 1][j] = max(dp[i][j], dp[i + 1][j]);
            if (j >= max(-mpsum, 0))
                dp[i + 1][j + sum] = max(dp[i][j] + len, dp[i + 1][j + sum]);
        }
        i++;
    }

    cout << dp[n - 1][0] << endl;
}