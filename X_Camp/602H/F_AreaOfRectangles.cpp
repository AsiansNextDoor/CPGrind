//#pragma GCC optimize ("trapv")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int INF, MOD;

int sum[10000000];

int query(int p, int l, int r, int ql, int qr) {
    if (r < ql || l > qr) return 0;
    if (ql <= l && r <= qr) return !!sum[p];

    int m = (l + r) / 2;
    int q1 = query(2 * p, l, m, ql, qr);
    int q2 = query(2 * p + 1, m + 1, r, ql, qr);
    return q1 + q2;
}

void update(int p, int l, int r, int idx, int val) {
    if (l == r) {
        sum[p] += val;
        return;
    }

    int m = (l + r) / 2;
    if (idx <= m) update(2 * p, l, m, idx, val);
    else update(2 * p + 1, m + 1, r, idx, val);
    sum[p] = sum[2 * p] + sum[2 * p + 1];
}

signed main() {
    IOS;

    int n; cin >> n;
    vector<vector<vector<int>>> add(2e6 + 2);
    vector<vector<vector<int>>> sub(2e6 + 2);
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        add[x1 + 1e6 + 1].push_back({y1, y2});
        sub[x2 + 1e6 + 1].push_back({y1, y2});
    }

    for (int i = 0; i <= 2e6 + 1; i++) {
        for (auto j: add[i]) {
            update(1, 1, 2e6 + 1, )
        }
    }
}