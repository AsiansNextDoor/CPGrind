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

        int c = a[k - 1];
        int cur = 0;
        bool start = false;
        int next = 0;
        for (int i = 0; i < n; i++) {
            if (i == k - 1) continue;
            if (start) {
                if (a[i] < c) next++;
                else break;;
            }
            else {
                if (a[i] < c) cur++;
                else start = true;
            }
            
        }

        cout << max(cur, next) << endl;
    }
}