#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define f first
#define s second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

signed main() {
    int n, k; cin >> n >> k;
    k--;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> diff(n-1);
    for (int i = 0; i < n-1; i++) {
        diff[i] = a[i+1] - a[i] - 1;
    }

    sort(diff.rbegin(), diff.rend());
    int ans = n;

    for (int i = 0; i < n-1; i++) {
        if (k <= i) ans += diff[i];
    }

    cout << ans << endl;
}