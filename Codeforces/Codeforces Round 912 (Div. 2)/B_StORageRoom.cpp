#include <bits/stdc++.h>
using namespace std;


signed main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        
        vector<vector<int>> m(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            int cur = m[i][0];
            if (i == 0) {
                cur = m[i][1];
            }
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    cur &= m[i][j];
                }
            }
            a[i] = cur;
        }
        
        bool check = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && ((a[i] | a[j]) != m[i][j])) {
                    check = false;
                    break;
                }
            }
        }
        
        if (check) {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}