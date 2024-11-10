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
        int n, m; cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(2));
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i][0];
            a[i][1] = i;
            b[i] = a[i][0];
        }
        sort(a.begin(), a.end());

        int cur = 0, prep = 0, prev = 0;
        set<int> beat;
        for (int i = 0; i < n; i++) {
            if (prep + a[i][0] <= m) {
                prep += a[i][0];
                prev = a[i][0];
                cur++;
                beat.insert(a[i][1]);
            }
            else break;
        }
        if (cur == n) {
            cout << 1 << endl;
            continue;
        }
        if (beat.find(cur) == beat.end()) {
            if ((prep - prev) + b[cur] <= m) {
                cur++;
            }
        }
        else cur++;

        cout << n - cur + 1 << endl;
    }
}