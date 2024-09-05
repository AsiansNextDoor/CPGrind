//#pragma GCC optimize ("trapv")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int INF, MOD;

struct node {
    node *val;
    node *prv;
    node *nxt;
    node(node *&val) : val(val), prv(NULL), nxt(NULL) {}
};

void insert(node *&cur, node*&val) {
    node *u = new node(val);
    u->prv = cur->prv;
    u->nxt = cur;
    cur->prv->nxt = u;
    cur->prv = u;
    cur = u;
}

signed main() {
    IOS;

    int n, b; cin >> n >> b;

    vector<int> snow(n);
    for (int i = 0; i < n; i++) cin >> snow[i];
    vector<vector<int>> boots(b, vector<int>(2));
    for (int i = 0; i < b; i++) cin >> boots[i][0] >> boots[i][1];

    sort(boots.rbegin(), boots.rend());

    vector<vector<int>> bi;
    for (int i = 0; i < n; i++) bi.push_back({boots[i][0], i});

    sort(bi.rbegin(), bi.rend());

    node *snode = new node(snode);
    node *enode = new node(snode);

    vector<node> nodes(n);
    for (int i = 0; i < n; i++) {
        m 
    }
}