//#pragma GCC optimize ("trapv")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int n, m, c;
vector<int> a;

bool check(int x) {
    int curc = 1, si = a[0], bus = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] - si > x || curc >= c) {
            bus++;
            si = a[i];
            curc = 1;
        }
        else curc++;
    }
    if (curc > 0) bus++;
    if (bus <= m) return true;
    return false;
}

signed main() {
    IOS;

    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);

    cin >> n >> m >> c;
    a.resize(n);

    for (int i = 0; i < n; i++) cin >> a[i];
    
    sort(a.begin(), a.end());

    int l = 0, r = 1e9, mid;
    int ans = 1e9;
    while (l <= r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            ans = min(ans, mid);
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    
    cout << ans << endl;
}