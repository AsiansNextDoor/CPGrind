#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

signed main() {
    IOS;

    ll t; cin >> t;
    while (t--) {
        int n, q, c; cin >> n >> q >> c; //cows, pairs, max score
        vector<int> scores(n);
        for (int i = 0; i < n; i++) cin >> scores[i];
        vector<pair<int,int>> pairs(q);
        for (int i = 0; i < q; i++) cin >> pairs[i].f >> pairs[i].s;

        sort(pairs.begin(), pairs.end());

        vector<int> pmax(n);
        for (int i = 1; i < n; i++)

        vector<int> temppairs;
        int prevh = -1;
        for (int i = 0; i < q; i++) {
            int a = pairs[i].f, h = pairs[i].s;
            if (a <= prevh)
        }
    }
}