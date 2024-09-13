#include <bits/stdc++.h>
using namespace std;

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

signed main() {
    node *cur1 = new node(0);
    node *cur2 = new node(0);
}