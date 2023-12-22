#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define f first
#define s second

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        
        int maxn = 0, maxi1, maxi2;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (maxn < a[i]) {
                maxn = a[i];
                maxi1 = i;
            }
        }
        
        int i = maxi1+1;
        while (i != maxi1) {
            if (i == n) {
                i = 0;
            }
            if (a[i] != maxn) break;
            i++;
        }
        if (i == 0) i = n-1;
        maxi2 = i;
        
        i = maxi1-1;
        while (i != maxi1) {
            if (i == 0) {
                i = n-1;
            }
            if (a[i] != maxn) break;
            i--;
        }
        if (i == n) i = 0;
        maxi1 = i;
        
        
        
        i = maxi2 + 1;
        int prev = maxn;
        int order = 0;
        bool ordered = true;
        while (i != maxi1) {
            if (i == n) {
                i = 0;
            }
            
            if (a[i] < prev && order <= 0) order = -1;
            else if (a[i] > prev && order >= 0) order = 1;
            else if (a[i] == prev) order = order;
            else {
                ordered = false;
                break;
            }
            prev = a[i];
            i++;
        }
        
        
        int ans = -1;
        if (ordered) {
            ans = 0;
            if (order == -1) ans += (n - maxi1 + 1) + 2;
            else ans += n - (maxi2 + 1);
        }
        cout << ans << endl;
    }
}