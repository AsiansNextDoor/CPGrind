#include <iostream>
#include <algorithm>
#include <vector>
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
        
        int maxn = 0, maxi;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (maxn < a[i]) {
                maxn = a[i];
                maxi = i;
            }
        }
        
        int i = maxi + 1;
        int prev = maxn;
        int order = 0;
        bool ordered = true;
        while (i != maxi) {
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
            if (order == -1) ans += 2;
            ans += n - (maxi + 1);
        }
        cout << ans << endl;
    }
}