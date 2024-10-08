//#pragma GCC optimize ("trapv")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

// large static array, stores sum of each segment tree node
// in this implementation, node range [l, r] is calculated when we recurse
int sum[400005];

// node index, [l, r] for node range, [ql, qr] for query range
int query(int p, int l, int r, int ql, int qr) {
    // no overlap between query and node range
    if (ql > r || qr < l) return 0;
    // node range completely covered by query
    if (ql <= l && r <= qr) return sum[p];
    // keep descending down
    // 2 * p and 2 * p + 1 are left and right child
    int m = (l + r) / 2;
    return query(2 * p, l, m, ql, qr) + query(2 * p + 1, m + 1, r, ql, qr);
}

// node index, [l, r] for node range, set element at idx to val
void update(int p, int l, int r, int idx, int val) {
    if (l == r) { // leaf node
        sum[p] = val;
        return;
    }

    // descend down correct branch that the leaf is under
    int m = (l + r) / 2;
    if (idx <= m) update(2 * p, l, m, idx, val);
    else update(2 * p + 1, m + 1, r, idx, val);
    sum[p] = sum[2 * p] + sum[2 * p + 1]; // recalculate value
}

signed main() {
    IOS;
}