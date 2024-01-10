#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define f first
#define s second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

vector<int> parent(2e5+1);

void make_set(int v) {
    parent[v] = v;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        parent[b] = a;
}

signed main() {
    IOS;
    int n, q; cin >> n >> q;

    for (int i = 1; i <= 2*n; i++) {
        make_set(i);
    }

    while (q--) {
        char t; cin >> t;
        int a, b; cin >> a >> b;
        if (t == 'A') {
            union_sets(a, b+n);
            union_sets(a+n, b);
        }
        else if (t == 'R') {
            union_sets(a, b);
            union_sets(a+n, b+n);
        }
        else {
            if (find_set(a) == find_set(b)) cout << "R" << endl;
            else if (find_set(a) == find_set(b+n)) cout << "A" << endl;
            else cout << "?" << endl;
        }
    }
}