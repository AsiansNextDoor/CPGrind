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

    vector<string> abc = {"a", "b", "c"};
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = s.size();
        if (n == 1) {
            for (string c: abc) {
                if (c != s) {
                    cout << s + c << endl;
                    break;
                }
            }
        }
        else {
            int add = 0;
            string ans;
            for (int i = 0; i < n - 1; i++) {
                int cur;
                if (s[i] != s[i + 1]) cur = 1;
                else cur = 2;
                if (cur > add) {
                    add = cur;
                    for (string c: abc) {
                        if (c[0] != s[i] && c[0] != s[i + 1]) {
                            ans = s.substr(0, i + 1) + c + s.substr(i + 1, n - (i + 1));
                            break;
                        }
                    }
                }
            }

            cout << ans << endl;
        }
    }
}