#include <bits/stdc++.h>
using namespace std;

/*
Debug checklist
- DELETE CODE PORTIONS ONE BY ONE AND RUN
- Check bounds
- Long long
- Sample case
- Edge cases
*/

typedef long long ll;
#define f first
#define s second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

signed main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> fre1(26, 0);
        vector<int> fre2(26, 0);

        string a, b; cin >> a >> b;
        for (int i = 0; i < n; i++) {
            fre1[a[i] - 'a']++;
            fre2[b[i] - 'a']++;
        }

        int valid = true;
        for (int i = 0; i < 25; i++) {
            int diff = fre1[i] - fre2[i];
            if (diff < 0 || diff % k != 0) {
                valid = false;
                break;
            }
            fre1[i] -= diff;
            fre1[i+1] += diff;
        }

        if (!valid || fre1[25] != fre2[25]) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
}