#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

signed main() {
    IOS;

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int prev = 0;
        string ans = "SQUARE";
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            int a = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] == '1') a++;
            }
            if (prev == 0) prev = a;
            else {
                if (a != prev && a != 0) ans = "TRIANGLE";
            }
        }

        cout << ans << endl;
    }
} 