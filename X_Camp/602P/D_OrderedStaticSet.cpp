//#pragma GCC optimize ("trapv")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int INF, MOD;

int sum[800005];

int query(int p, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) return 0;
    if (ql <= l && r <= qr) return sum[p];

    int m = (l + r) / 2;
    return (query(2 * p, l, m, ql, qr) + query(2 * p + 1, m + 1, r, ql, qr));
}

void update(int p, int l, int r, int idx, int val) {
    if (l == r) {
        sum[p] = val;
        return;
    }

    int m = (l + 2) / 2;
    if (idx <= m) update(2 * p, l, m, idx, val);
    else update(2 * p + 1, m + 1, r, idx, val);
    sum[p] = sum[2 * p] + sum[2 * p + 1];
}

signed main() {
    IOS;

    int n; cin >> n;

    vector<int> a;
    vector<vector<int>> q(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        char c; cin >> c >> q[i][1];
        if (c == 'I') {
            q[i][0] = 0;
            a.push_back(q[i][1]);
        }
        else if (c == 'D') {
            q[i][0] = 1;
            a.push_back(q[i][1]);
        }
        else if (c == 'K') q[i][0] = 2;
        else q[i][0] = 3;
    }

    sort(a.begin(), a.end());

    map<int, int> m;
    for (int i = 0; i < a.size(); i++) {
        m[a[i]] = i + 1;
    }

    for (int i = 0; i < n; i++) {
        int q1 = q[i][0], val = q[i][1];
        if (q1 == 0) update(1, 1, a.size(), m[val], 1);
        else if (q1 == 1) update(1, 1, a.size(), m[val], 0);
        else if (q1 == 2) {
            int l = 0;
            int r = a.size(), mid;
            int ans = a.size();
            while (l <= r) {
                mid = (l + r) / 2;
                if (query(1, 1, a.size(), 1, mid) >= val) {
                    ans = min(ans, mid);
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }

            cout << ans << endl;
        }
        else {
            int v = upper_bound(a.begin(), a.end(), val) - a.begin();
            cout << query(1, 1, a.size(), 1, v) << endl;
        }
    }
}