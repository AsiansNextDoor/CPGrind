//#pragma GCC optimize ("trapv")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int INF, MOD;

int sum[10000000];
int lazy[10000000];

vector<int> query(int p, int l, int r, int ql, int qr) {
    if (qr < l || ql > r) return {0, 0};
    if (ql <= l && r <= qr) 
        return {!!sum[p] + lazy[p] * (r - l + 1), (r - l + 1)};

    int m = (l + r) / 2;
    auto q1 = query(2 * p, l, m, ql, qr);
    auto q2 = query(2 * p + 1, m + 1, r, ql, qr);
    return {q1[0] + q2[0] + (q1[1] + q2[1]) * lazy[p], q1[1] + q2[1]};
}

int range(int p, int l, int r, int ql, int qr, int val) {
    if (qr < l || ql > r) return 0;
    if (ql <= l && r <= qr) {
        lazy[p] += val;
        return val * (r - l + 1);
    }
    
    int m = (l + r) / 2;
    int r1 = range(2 * p, l, m, ql, qr, val);
    int r2 = range(2 * p + 1, m + 1, r, ql, qr, val);
    sum[p] += r1 + r2;
    return r1 + r2;
}

signed main() {
    IOS;

    int n; cin >> n;
    vector<vector<vector<int>>> add(2e6 + 1);
    vector<vector<vector<int>>> sub(2e6 + 1);
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        add[x1 + 1e6].push_back({y1 + 1000001, y2 + 1000001});
        sub[x2 + 1e6].push_back({y1 + 1000001, y2 + 1000001});
    }

    for (int i = 0; i <= 2e6; i++) {
        for (auto j: add[i]) range(1, 1, 2e6 + 1, j[0], j[1], 1);
        for (auto j: sub[i]) range(1, 1, 2e6 + 1, j[0], j[1], -1);
    }

    cout << (query(1, 1, 1e6 + 1, 1, 1e6 + 1))[0] << endl;
}