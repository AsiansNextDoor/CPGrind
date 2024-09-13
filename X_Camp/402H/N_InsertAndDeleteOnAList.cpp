#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int INF;

struct node {
    int val;
    node *prv;
    node *nxt;
    node(int val) : val(val), prv(NULL), nxt(NULL) {}
};

void insert(node *&cur, int val) {
    node *u = new node(val);
    u->prv = cur->prv;
    u->nxt = cur;
    cur->prv->nxt = u;
    cur->prv = u;
    cur = u;
}

void delmove(node *&cur) {
    cur->prv->nxt = cur->nxt;
    cur->nxt->prv = cur->prv;
    cur = cur->nxt;
}

signed main() {
    IOS;

    int n; cin >> n;
    node *cur1 = new node(0);
    node *cur2 = new node(0);
    cur1->prv = cur2;
    cur2->nxt = cur1;
    while (n--) {
        int q; cin >> q;
        if (q == 4) cout << cur1->val << endl;
        else if (q == 3) delmove(cur1);
        else {
            int y; cin >> y;
            if (q == 1) {
                if (y == 1) cur1 = cur1->nxt;
                else cur1 = cur1->prv;
            }
            else {
                insert(cur1, y);
            }
        }
    }
}