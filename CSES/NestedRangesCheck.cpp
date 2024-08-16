#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int INF;

signed main() {
    IOS;

    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
        a[i][1] *= -1;
    }

    sort(a.begin(), a.end());

    int c = 0;
    
    set<vector<int>> ends;
    vector<int> cs(n, 0);
    vector<int> cby(n, 0);
    for (int i = 0; i < n; i++) {
        int x = a[i][0], y = a[i][1];
        while (!ends.empty()) {
            auto it = ends.begin();
            int y1 = (*it)[0], x1 = -(*it)[1];
            if ((*it)[0] <= x) {
                ends.erase(it);
            }
        }
        cur.insert({x, y});
        ends.insert({y, -x});
        if (ends.find({y, }))
    }
}