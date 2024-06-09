#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

vector<int> dp((1 << 20), 1e5);
vector<vector<int>> adj(21, vector<int>(21, 0));

signed main() {
    IOS;
    string s; cin >> s;
    vector<string> a = {"bdeilmrs", "abcfghjknopqstuvwxyz"};
    int t = 1;

    int n = s.length();
    for (int i = 0; i < n; i++) {
        if (a[1].find(s[i]) == string::npos) {
            t = 0;
            break;
        }
    }


    for (int i = 0; i < n-1; i++) {
        int x = a[t].find(s[i]), y = a[t].find(s[i+1]);
        adj[x][y]++;
    }
    dp[0] = 0;
    for (int mask = 0; mask < (1 << a[t].length()); mask++) {
        for (int i = 0; i < a[t].length(); i++) {
            int next = (1 << i);
            if (next & mask) {
                continue;
            }
            int cnt = adj[i][i];
            for (int j = 0; j < a[t].length(); j++) {
                int check = (1 << j);
                if (mask & check) cnt += adj[i][j];
            } 
            dp[mask^next] = min(dp[mask] + cnt, dp[mask^next]);
        }
    }

    cout << dp[(1 << a[t].length()) - 1] + 1 << endl;
}