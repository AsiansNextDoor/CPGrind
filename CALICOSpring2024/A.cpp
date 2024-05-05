#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

signed main() {
    IOS;

    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = s.size();
        
        string ans = s;
        string s1 = "CALICO";
        vector<string> find = {"o", "co", "ico", "lico", "alico", "calico"};
        
        for (int i = max(6, n); i >= 1; i--) {
            if (s.substr(0, i) == find[i-1]) {
                ans = s1 + s.substr(i, n-i);
            }
        }
        
        cout << ans << endl;
    }
}