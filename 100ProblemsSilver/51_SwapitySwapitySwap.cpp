#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int INF;

vector<int> p;
vector<int> s;

void make_set(int v) {
    p[v] = v;
    s[v] = 1;
}

int find_set(int v) {
    if (v == p[v])
        return v;
    return p[v] = find_set(p[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (s[a] < s[b])
            swap(a, b);
        p[b] = a;
        s[a] += s[b];
    }
}

signed main() {
    IOS;

    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);

    int n, m, k; cin >> n >> m >> k;
    p.resize(n);
    s.resize(n);
    
    vector<int> swaps(n);
    iota(swaps.begin(), swaps.end(), 0);
    for (int i = 0; i < m; i++) {
        int l, r; cin >> l >> r;
        l--;
        reverse(swaps.begin() + l, swaps.begin() + r);
    }

    for (int i = 0; i < n; i++) make_set(i);
    for (int i = 0; i < n; i++) {
        union_sets(i, swaps[i]);
    }

    for (int i = 0; i < n; i++) find_set(i);

    vector<int> move(n);
    for (int i = 0; i < n; i++) move[swaps[i]] = i;

    vector<int> visited(n, 0);
    vector<int> ind(n);
    map<int, vector<int>> cowset;
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        int j = i;
        int curi = 0;
        while (!visited[j]) {
            visited[j]++;
            cowset[p[j]].push_back(j);
            ind[j] = curi++;
            j = move[j];
        }
    }

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        int MOD = s[p[i]];
        int fi = (ind[i] + (k % MOD)) % MOD;
        ans[cowset[p[i]][fi]] = i + 1;
    }

    for (int i = 0; i < n; i++) cout << ans[i] << endl;
}