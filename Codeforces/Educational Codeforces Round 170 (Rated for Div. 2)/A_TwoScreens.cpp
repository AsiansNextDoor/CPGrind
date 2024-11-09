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

    int q; cin >> q;
    while (q--) {
        string s, t; cin >> s >> t;

        int same = 0;
        for (int i = 0; i < min(s.size(), t.size()); i++) {
            if (s[i] == t[i]) same++;
            else break;
        }

        int ans = s.size() + t.size();
        cout << min(ans, ans - same + 1) << endl;
    }
}