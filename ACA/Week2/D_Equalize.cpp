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
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());

        int j = 0, ans = 0;
        set<int> vals; vals.insert(a[0]); 
        map<int, int> freq; freq[a[0]]++;
        for (int i = 0; i < n; i++) {
            while (j < n - 1 && a[j + 1] - a[i] + 1 <= n) {
                j++;
                vals.insert(a[j]);
                freq[a[j]]++;
            }
            ans = max((int)vals.size(), ans);
            freq[a[i]]--;
            if (!freq[a[i]]) vals.erase(a[i]);
        }
        
        cout << ans << endl;
    }
}