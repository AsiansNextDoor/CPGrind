//#pragma GCC optimize ("trapv")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int INF, MOD;

int sum[1000005];

int query(int p, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) return 0;
    if (ql <= l && r <= qr) return sum[p];

    int m = (l + r) / 2;
    return (query(2 * p, l, m, ql, qr) + query(2 * p + 1, m + 1, r, ql, qr));
}

void update(int p, int l, int r, int idx, int val) {
    if (l == r) {
        //cout << "idx: " << idx << endl;
        sum[p] = val;
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

    vector<vector<int>> a;
    set<int> s;
    for (int i = 0; i < n; i++) {
        int ai; cin >> ai;
        a.push_back({ai, i + 1});
        s.insert(ai);
    }


    int q; cin >> q;
    vector<vector<int>> qs;
    for (int i = 0; i < q; i++) {
        int x, y, k; cin >> x >> y >> k;
        qs.push_back({k, x, y, i});
    }

    sort(a.rbegin(), a.rend());
    sort(qs.rbegin(), qs.rend());

    int j = 0;
    vector<int> ans(q);
    for (int i = 0; i < q; i++) {
        int k = qs[i][0], x = qs[i][1], y = qs[i][2];
        //cout << endl << k << endl;
        while (j < n && a[j][0] > k) {
            //cout << a[j][0] << endl;
            update(1, 1, n, a[j][1], 1);
            j++;
        }

        ans[qs[i][3]] = query(1, 1, n, x, y);
    }

    for (int ans1: ans) cout << ans1 << endl;
}