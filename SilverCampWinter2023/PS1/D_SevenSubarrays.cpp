#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define f first
#define s second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

signed main() {
    IOS;
    int n; cin >> n;
    vector<int> a(n+1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i-1];
        a[i] %= 7;
    }

    //for (int i = 1; i <= n; i++) cout << a[i] << " ";
    //cout << endl;
    int ans = 0;
    for (int i = 0; i < 7; i++) {
        int firsti = -1, lasti = -1;
        for (int j = 0; j <= n; j++) {
            if (a[j] == i) {
                if (firsti == -1) {
                    firsti = j;
                }
                lasti = j;
            }
        }

        ans = max(lasti - firsti, ans);
    }

    cout << ans << endl;
}