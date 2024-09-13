//#pragma GCC optimize ("trapv")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int INF, MOD;

int blobs = 0;
vector<int> p;
vector<int> s;

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
    
    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);

    int n, b; cin >> n >> b;

    p.resize(n, -1);
    s.resize(n, -1);

    vector<int> snow(n);
    for (int i = 0; i < n; i++) cin >> snow[i];

    vector<vector<int>> boots(b, vector<int>(3));
    for (int i = 0; i < b; i++) {
        cin >> boots[i][0] >> boots[i][1];
        boots[i][2] = i;
    }


    vector<vector<int>> si(n);
    for (int i = 0; i < n; i++) si[i] = {snow[i], i};
    
    sort(boots.rbegin(), boots.rend());
    sort(si.rbegin(), si.rend());

    int j = 0;
    vector<int> ans(b, 0);
    for (int i = 0; i < b; i++) {
        int curd = boots[i][0], curs = boots[i][1], curi = boots[i][2];
        while (j < n && si[j][0] > curd) {
            int k = si[j][1];
            make_set(k);
            if (k > 0 && p[k - 1] != -1) union_sets(k - 1, k);
            if (k < n - 1 && p[k + 1] != -1) union_sets(k + 1, k);
            j++;
        }

        if (curs > blobs) ans[curi]++;
    }

    for (int i = 0; i < b; i++) cout << ans[i] << endl;
}