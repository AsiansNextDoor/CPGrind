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

    int n; cin >> n;
    vector<vector<int>> cows(n, vector<int>(3));
    for (int i = 0; i < n; i++) cin >> cows[i][1] >> cows[i][0] >> cows[i][2];

    sort(cows.begin(), cows.end());

    set<int> times;
    set<vector<int>> start;

    for (int i = 0; i < n; i++) {
        int l = (abs(cows[i][1]) - 1) * cows[i][2], r = abs(cows[i][1]) * cows[i][2], y = cows[i][0];
        times.insert(l);
        times.insert(r);
        start.insert({l, r, y});
    }

    set<vector<int>> ans;
    set<vector<int>> order;
    set<vector<int>> end;

    for (auto t: times) {
        auto sit = start.begin();
        while (!start.empty() && (*sit)[0] == t) {
            order.insert({(*sit)[2], (*sit)[1]});
            end.insert({(*sit)[1], (*sit)[2]});
            start.erase(sit);
            sit = start.begin();
        }
        auto eit = end.begin();
        while (!end.empty() && (*eit)[0] == t) {
            order.erase({(*eit)[1], (*eit)[0]});
            end.erase(eit);
            eit = end.begin();
        }
        if (!order.empty()) ans.insert(*order.begin());
    }

    cout << ans.size() << endl;
}