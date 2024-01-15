#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define f first
#define s second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

signed main() {
    IOS;
    int l, r; cin >> l >> r;

    vector<vector<int>> laser(l);
    vector<int> sum(l, 0);
    for (int i = 0; i < l; i++) {
        int c; cin >> c;
        for (int j = 0; j < c; j++) {
            int l1; cin >> l1;
            laser[i].push_back(l1);
            sum[i] += l1;
        }
        laser[i].push_back(0);
    }

    vector<pair<int,int>> range;
    for (int i = 0; i < l; i++) {
        int left = 1;
        int right = l-sum[i];
        int r1, l1;
        for (int j = 0; j < laser[i].size(); j++) {
            r1 = left + laser[i][j] - 1;
            l1 = right - laser[i][j] + 1;
            if (l1 <= r1) {
                range.push_back({l1, r1});
            }
            left += laser[i][j];
            right += laser[i][j];
        }
    }

    vector<int> blocked(l+2, 0);
    for (int i = 0; i < range.size(); i++) {
        blocked[range[i].f]++;
        blocked[range[i].s+1]--;
    }

    int sums = 0, ans = 0;
    for (int i = 1; i <= l; i++) {
        sums += blocked[i];
        if (sums > 0) ans++;
    }

    cout << ans << endl;
}