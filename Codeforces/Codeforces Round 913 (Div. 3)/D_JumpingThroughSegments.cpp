#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> l; vector<int> r;

bool check(int k) {
    int lrange = 0, rrange = 0;
    for (int i = 0; i < n; i++) {
        lrange -= k; rrange += k;
        if (lrange > r[i] || rrange < l[i]) {
            return false;
        }
        lrange = max(l[i], lrange);
        rrange = min(r[i], rrange);
    }
    
    return true;
}

signed main() {
    int t; cin >> t;
    while (t--) {
        cin >> n;
        
        l.clear(); r.clear();
        l.resize(n);
        r.resize(n);
        
        for (int i = 0; i < n; i++) {
            cin >> l[i] >> r[i];
        }
        
        int left = 0;
        int right = 1e9, mid;
        int ans = 1e9;
        while (left <= right) {
            mid = (left+right)/2;
            if (check(mid)) {
                ans = min(ans, mid);
                right = mid-1;
            }
            else {
                left = mid+1;
            }
        }
        
        cout << ans << endl;
    }
}