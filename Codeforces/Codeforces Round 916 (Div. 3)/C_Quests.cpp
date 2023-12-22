#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        
        int maxb = 0;
        int xp = 0;
        int mxp = 0;
        for (int i = 0; i < n; i++) {
            xp += a[i];
            maxb = max(b[i], maxb);
            int r = k - (i+1);
            if (r < 0) break;
            
            mxp = max(xp+maxb*r, mxp);
        }
        
        cout << mxp << endl;
    }
}