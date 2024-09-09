//#pragma GCC optimize ("trapv")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int INF, MOD;

vector<int> p;
vector<int> s;
int blobs = 0;

void make_set(int v) {
    p[v] = v;
    s[v] = 1;
    blobs = max(blobs, 1);
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
        blobs = max(s[a], blobs);
    }
}

signed main() {
    IOS;

    int n; cin >> n;
    p.resize(n, -1);
    s.resize(n, -1);
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<int>> ai(n);
    for (int i = 0; i < n; i++) ai[i] = {a[i], i};
    sort(ai.rbegin(), ai.rend());

    vector<int> ans(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int s = ai[i][0], j = ai[i][1];
        make_set(j);
        if (j > 0 && p[j - 1] != -1) union_sets(j - 1, j);
        if (j < n - 1 && p[j + 1] != -1) union_sets(j + 1, j);

        ans[blobs] = max(s, ans[blobs]);
    }

    for (int i = n - 1; i > 0; i--) ans[i] = max(ans[i + 1], ans[i]);
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
}