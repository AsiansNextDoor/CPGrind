#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

string s;
bool check(int i, int j) {
    if (s[i] == '?' || s[j] == '?') return true;
    if (s[i] == s[j]) return true;
    return false;
}

signed main() {
    IOS;

    int t; cin >> t;
    while (t--) {
        cin >> s;
        
        int ans = 0, n = s.size();
        for (int d = 1; d <= n/2; d++) { // d is half 
            int checks = 0;
            for (int i = 0; i < d; i++) { //initial check for checks
                if (check(i, i+d)) checks++;
            }
            if (checks == d) {
                ans = d;
                continue;
            }

            for (int i = 1; i < (n-d-d+1); i++) { // only start and end points change, everything
                if (check(i-1, i-1+d)) checks--; // else shifts by one
                if (check(i+d-1, i+d-1+d)) checks++;
                if (checks == d) {
                    ans = d;
                    break;
                }
            }
        }

        ans *= 2;
        cout << ans << endl;
    }
}