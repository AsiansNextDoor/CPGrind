#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define f first
#define s second


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int q, x; cin >> q >> x;
    set<pair<int,int>> a;
    for (int i = 0; i < x; i++) {
        a.insert({0, i});
    }
    vector<int> bases(x);
    while (q--) {
        int y; cin >> y;
        y %= x;
        a.erase(a.find({bases[y], y}));
        bases[y]++;
        a.insert({bases[y], y});
        auto it = a.begin(); auto data = *it;
        int times = data.f, base = data.s;
        cout << base + times * x << endl;
    }
}