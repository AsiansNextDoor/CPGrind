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
        int n; cin >> n;
        string s1, s2;
        cin >> s1 >> s2;
        
        int jump = 0;
        string ans = "YES";
        for (int i = 0; i < n; i++) {
            if (s1[i] == '#' && s2[i] == '-') jump = 0;
            else if (s1[i] == '-' && s2[i] == '#') {
                ans = "banned";
                break;
            }
            else jump++;
            if (jump > 4) {
                ans = "banned";
                break;
            }
        }
        
        cout << ans << endl;
    }
}