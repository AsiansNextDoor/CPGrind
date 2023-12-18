#include <bits/stdc++.h>
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        bool check = true;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < cur) {
                check = false;
                break;
            }
            cur = a[i];
        }
        
        if (!check && k == 1) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }
    }
}