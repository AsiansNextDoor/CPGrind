#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

int INF;

signed main() {
    IOS;

    int n, q; cin >> n >> q;

    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    
    map<int, unsigned long long> hash;
    for (int i = 1; i <= n; i++) hash[i] = rng();

    vector<int> a(n + 1);
    vector<unsigned long long> p(n + 1, 0);
    vector<unsigned long long> per(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        p[i] += p[i - 1] + hash[a[i]];
        per[i] += per[i - 1] + hash[i];
    }

    while (q--) {
        int l, r; cin >> l >> r;
        l--;
        if (per[r - l] == p[r] - p[l]) cout << 1 << endl;
        else cout << 0 << endl;
    }
}