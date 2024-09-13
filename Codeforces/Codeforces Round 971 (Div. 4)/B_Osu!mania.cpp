//#pragma GCC optimize ("trapv")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int INF, MOD;

signed main() {
    IOS;

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            for (int j = 0; j < 4; j++) if (s[j] == '#') ans[i] = j + 1;
        }

        reverse(ans.begin(), ans.end());
        for (int i = 0; i < n; i++) cout << ans[i] << " ";
        cout << endl;
    }
}