//#pragma GCC optimize ("trapv")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int INF, MOD;

signed main() {
    IOS;

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            int cur = a[i] % k;
            if (cur) cur = k - cur;
            ans.push_back({cur, i + 1});
        }

        sort(ans.begin(), ans.end());

        for (int i = 0; i < n; i++) {
            cout << ans[i][1] << " ";
        }
        cout << endl;
    } 
}