#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

int INF;

signed main() {
    IOS;

    int n, q; cin >> n >> q;
    vector<int> cows(n + 1); cows[0] = -1;
    for (int i = 1; i <= n; i++) cin >> cows[i];
    
    sort(cows.begin(), cows.end());

    while (q--) {
        int l, r; cin >> l >> r;
        auto it1 = lower_bound(cows.begin(), cows.end(), l);
        auto it2 = upper_bound(cows.begin(), cows.end(), r);
        it1--;
        cout << it2 - it1 << endl;
    }
}