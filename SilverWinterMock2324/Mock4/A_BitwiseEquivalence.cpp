#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

signed main() {
    IOS;

    int n; cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; i++) cin >> b[i];

    int maxb = 0;
    for (int i = 0; i < n; i++) maxb = max(b[i], maxb);
    ll ans = 0;
    for (int i = 0; i < n; i++) ans += (ll)(maxb - b[i]);

    cout << ans << endl;
}