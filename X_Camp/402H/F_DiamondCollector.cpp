#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int INF;

signed main() {
    IOS;
    
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);

    int n, k; cin >> n >> k;
    vector<int> d(n);
    for (int i = 0; i < n; i++) cin >> d[i];

    sort(d.begin(), d.end());

    map<int, int> m;
    int j = 0;
    for (int i = 0; i < n; i++) {
        int cur = d[i];
        while (j < n && cur + k >= d[j]) j++;
        m[i] = j - i;
    }

    vector<int> pmax(n, m[0]);
    vector<int> smax(n, m[n - 1]);
    for (int i = 1; i < n; i++) pmax[i] = max(m[i], pmax[i - 1]);
    for (int i = n - 2; i >= 0; i--) smax[i] = max(m[i], smax[i + 1]);
    
    // for (int i: pmax) cout << i << " ";
    // cout << endl;
    // for (int i: smax) cout << i << " ";
    // cout << endl;

    int ans = 0, l = 0;
    for (int i = 0; i < n; i++) {
        int cur = m[i];
        int add = 0;
        int j = i + cur;
        if (l + m[l] <= i) {
            while (l + m[l] <= i) l++;
            l--;
            add = max(pmax[l], add);
        }
        if (j < n) add = max(smax[j], add);

        ans = max(cur + add, ans);
    }

    cout << ans << endl;
}