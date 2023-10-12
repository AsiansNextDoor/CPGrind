//Incomplete

#include <bits/stdc++.h>
using namespace std;

int MOD = 998244353;

vector<int> fib(1e5+1, 0);

signed main() {
    fib[1] = 1;
    fib[2] = 1;
    for (int i = 3; i < 1e5+1; i++) {
        fib[i] = (fib[i-2] + fib[i-1]) % MOD;
    }
    int t; cin >> t;
    while (t--) {
        int n, q; cin >> n >> q;
        
        vector<int> ans(n+2, 0);
        
        for (int i = 0; i < q; i++) {
            int l, r; cin >> l >> r;
            ans[l]++;
            ans[r+1]--;
        }
        
        for (int i = 1; i <= n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}