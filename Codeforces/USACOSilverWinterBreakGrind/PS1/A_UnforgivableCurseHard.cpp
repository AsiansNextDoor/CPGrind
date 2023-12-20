#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
    ll t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        string s1, s2; cin >> s1 >> s2;
        
        int r = k-1, l = n - k;
        
        l = max(0, l);
        r = min(r, n-1);
        
        bool valid = true;
        for (int i = l; i <= r; i++) {
            if (s1[i] != s2[i]) {
                valid = false;
                break;
            }
        }
        
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                valid = false;
                break;
            }
        }
        
        if (valid) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}