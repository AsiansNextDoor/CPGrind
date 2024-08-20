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
    map<vector<int>, int> indexes;
    vector<vector<int>> a(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
        indexes[a[i]] = i;
        a[i][1] *= -1;
    }

    sort(a.begin(), a.end());
    
    set<vector<int>> ends;
    vector<int> cs(n, 0);
    vector<int> cby(n, 0);
    for (int i = 0; i < n; i++) {
        int x = a[i][0], y = -a[i][1];
        ends.insert({y, -x});
        auto it = ends.end(); it--;
        if (ends.find({y, -x}) != it) cby[indexes[{x, y}]]++;
    }
    
    ends.clear();
    set<vector<int>> cur;
    for (int i = 0; i < n; i++) {
        int x = a[i][0], y = -a[i][1];
        while (!ends.empty()) {
            int x1 = -(*ends.begin())[1], y1 = (*ends.begin())[0];
            if (y1 > x) break;

            ends.erase(ends.begin());
            auto it = cur.find({x1, -y1});
            if (it == cur.end()) continue;
            else {
                while (cur.begin() != it) {
                    int x2 = (*cur.begin())[0], y2 = -(*cur.begin())[1];
                    cs[indexes[{x2, y2}]]++;
                    cur.erase(cur.begin());
                }
                cur.erase(cur.begin());
            }
        }
        cur.insert({x, -y});
        ends.insert({y, -x});
    }
    
    while (!ends.empty()) {
        int x1 = -(*ends.begin())[1], y1 = (*ends.begin())[0];

        ends.erase(ends.begin());
        auto it = cur.find({x1, -y1});
        if (it == cur.end()) continue;
        else {
            while (cur.begin() != it) {
                int x2 = (*cur.begin())[0], y2 = -(*cur.begin())[1];
                cs[indexes[{x2, y2}]]++;
                cur.erase(cur.begin());
            }
            cur.erase(cur.begin());
        }
    }
    
    for (int i: cs) cout << i << " ";
    cout << endl;
    for (int i: cby) cout << i << " ";
    cout << endl;
}