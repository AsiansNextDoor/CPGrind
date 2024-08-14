#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int INF;

signed main() {
    IOS;

    int n, k; cin >> n >> k; k--;

    int ans = 0;
    set<int> yrs;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        int y = ((t + 11) / 12) * 12;
        yrs.insert(y);
        ans = max(y, ans);
    }
    
    priority_queue<int> skips;
    int prev = 0;
    for (int y: yrs) {
        skips.push((y - 12) - prev);
        prev = y;
    }

    while (!skips.empty() && k--) {
        ans -= skips.top(); skips.pop();
    }

    cout << ans << endl;
}