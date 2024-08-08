#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

int INF;

signed main() {
    IOS;

    int n; cin >> n;

    vector<vector<int>> events, cows;
    
    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        events.push_back({l, i, 1});
        events.push_back({r, i, 2});
        cows.push_back({l, r});
    }

    sort(events.begin(), events.end());

    int ptime, tot = 0;
    set<int> shift;
    map<int, int> cover;
    for (auto data: events) {
        int t = data[0], id = data[1], op = data[2];
        if (!shift.empty()) {
            tot += t - ptime;
            if (shift.size() == 1) cover[*shift.begin()] += t - ptime;
        }

        if (op == 1) shift.insert(id);
        else shift.erase(shift.find(id));

        ptime = t;
    }

    int minc = 1e9;
    for (int i = 0; i < n; i++) minc = min(cover[i], minc);

    cout << tot - minc << endl;
}