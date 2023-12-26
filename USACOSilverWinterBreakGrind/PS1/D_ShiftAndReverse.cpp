#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define f first
#define s second

signed main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n); 
        for (int i = 0; i < n; i++) cin >> a[i];
        
        int inc = 0, dec = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] > a[i-1]) inc++;
            if (a[i] < a[i-1]) dec++;
        }
        if (a[0] > a[n-1]) inc++;
        else if (a[0] < a[n-1]) dec++;
        
        int minn = a[0], mini1 = 0, mini2 = 0;
        bool streak = true;
        bool lock = false;
        for (int i = 1; i < n; i++) {
            int cur = a[i];
            if (cur < minn) {
                minn = cur;
                mini1 = i;
                lock = false;
                mini2 = i;
                streak = true;
            }
            else if (cur == minn) {
                if (!streak) mini1 = i;
                if (!lock) mini2 = i;
                streak = true;
            }
            else {
                if (streak = true) lock = true;
                streak = false;
            }
        }
        
        // cout << "inc: " << inc << " dec: " << dec << endl;
        if (inc == 0 && dec == 0) cout << 0 << endl;
        else if (inc != 1 && dec != 1) cout << -1 << endl;
        else if (dec == inc) {
            //cout << "mini2: " << mini2 << endl;
            if (mini1 == 0) cout << 0 << endl;
            else cout << min(min(mini1+2, n-mini1), min(n-mini2, mini2+2)) << endl;
        }
        else if (dec == 1) {
            // cout << mini1 << endl;
            if (mini1 == 0) cout << 0 << endl;
            else cout << min(mini1+2, n-mini1) << endl;
        }
        else if (inc == 1) {
            cout << min(n-mini2, mini2+2) << endl;
        }
    }
}