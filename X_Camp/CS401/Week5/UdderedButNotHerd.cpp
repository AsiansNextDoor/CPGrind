#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

vector<vector<int>> dpstep(21, vector<int>((1 << 21), 0));
vector<int> dp((1 << 21), 1e5);

signed main() {
    IOS;
    string s; cin >> s;
    vector<string> a = {"deilmr", "abcfghjknopqstuvwxyz"};
    int t = 0;

    int n = s.length();
    if (a[0].find(s[0]) == string::npos) {
        t = 1;
    }



    for (int mask = 0; mask < (1 << (a[t].length())) - 1; mask++) {
        for (int i = 0; i < a[t].length(); i++) {
            int next = (1 << i);
            if (next & mask) {
                continue;
            }

            int cnt = 0;
            string small;
            for (int j = 0; j < a[t].length(); j++) {
                if ((1 << j) & mask) {
                    small += a[t][j];
                }
            }
            for (int j = 0; j < n; j++) {
                if (s[j] != a[t][i]) {
                    continue;
                }
                if (j != n-1 && (small.find(s[j+1]) != string::npos || s[j+1] == s[j])) { //smaller
                    cnt++;
                }
            }

            dpstep[i][mask] = cnt;
        }
    }

    dp[0] = 0;
    for (int mask = 0; mask < (1 << (a[t].length())) - 1; mask++) {
        for (int i = 0; i < a[t].length(); i++) {
            int next = (1 << i);
            if (next & mask) {
                continue;
            }
            dp[mask^next] = min(dp[mask] + dpstep[i][mask], dp[mask^next]);
        }
    }

    cout << dp[(1 << a[t].length()) - 1] + 1 << endl;
}