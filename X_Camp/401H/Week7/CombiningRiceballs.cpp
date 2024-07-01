#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

signed main() {
    IOS;
    
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<int>> dp(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++) dp[i][i] = a[i];

    for (int len = 1; len < n; len++) {
        for (int i = 0; i < n - len; i++) {
            int j = i + len;

            //pairs
            for (int mid = i; mid < j; mid++) {
                int r1 = dp[i][mid];
                int r2 = dp[mid+1][j]; 
                if (r1 != -1 && r1 == r2) {
                    dp[i][j] = r1 + r2;
                    break;
                }
            }

            //triples
            for (int mid1 = i + 1; mid1 < j; mid1++) {
                for (int mid2 = mid1; mid2 < j; mid2++) {
                    int r1 = dp[i][mid1-1];
                    int r2 = dp[mid1][mid2];
                    int r3 = dp[mid2+1][j];
                    if (r1 != -1 && r2 != -1 && r1 == r3) {
                        dp[i][j] = r1 + r2 + r3;
                        break;
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            ans = max(dp[i][j], ans);
        }
    }

    cout << ans << endl;
}