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
        int n, q, c; cin >> n >> q >> c;
        vector<int> l(n+1), r(n+1);
        vector<int> scores(n+1);
        for (int i = 1; i <= n; i++) cin >> scores[i];

        vector<pair<int,int>> pairs(q);
        for (int i = 0; i < q; i++) cin >> pairs[i].f >> pairs[i].s;

        vector<int> pmax(n+1, 0);
        for (int i = 0; i < n; i++) pmax[i] = max(scores[i], pmax[i-1]);

        for (int i = 0; i < q; i++) {
            int a = pairs[i].f, h = pairs[i].s;
            if (scores[h] == 0) 
        }
    }
}