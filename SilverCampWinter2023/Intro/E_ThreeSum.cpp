#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define f first
#define s second

signed main() {
    ll t; cin >> t;
    while (t--) {
        int n; cin >> n;

        map<int, int> m;
        for (int i = 0; i < n; i++) {
            int ai; cin >> ai;
            ai %= 10;
            m[ai]++;
        }

        multiset<int> a;
        for (int i = 0; i <= 9; i++) {
            if (m[i] > 3) m[i] = 3;
            if (m[i] == 0) continue;
            for (int j = 0; j < m[i]; j++) a.insert(i);
        }
        bool ans = false;
        for (auto i = a.begin(); i != a.end(); i++) {
            for (auto j = a.begin(); j != a.end(); j++) {
                for (auto k = a.begin(); k != a.end(); k++) {
                    if (i == j || j == k || i == k) continue;
                    if (((*i + *j + *k) % 10) == 3) ans = true;
                }
            }
        }

        if (ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
 }