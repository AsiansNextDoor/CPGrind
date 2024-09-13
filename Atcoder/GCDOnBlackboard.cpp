#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int INF;

signed main() {
    IOS;

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> psum(n, a[0]);
    vector<int> ssum(n, a[n - 1]);

    for (int i = 2; i < n; i++) psum[i] = __gcd(psum[i - 1], a[i - 1]);
    for (int i = n - 3; i >= 0; i--) ssum[i] = __gcd(ssum[i + 1], a[i + 1]);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0) ans = max(ssum[i], ans);
        else if (i == n - 1) ans = max(psum[i], ans);
        else ans = max(__gcd(psum[i], ssum[i]), ans);
    }

    cout << ans << endl;
}