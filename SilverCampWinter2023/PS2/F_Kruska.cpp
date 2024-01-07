#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define f first
#define s second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

signed main() {
    // int n, k; cin >> n >> k;
    // int m; cin >> m;
    // vector<vector<int>> grid(n+1, vector<int>(n+1));
    // vector<vector<int>> wizards(m+1, vector<int>(8));
    // for (int i = 1; i <= m; i++) {
    //     int x, y; cin >> x >> y;
    //     string s; cin >> s;
    //     for (int j = 1; j <= 7; j++) {
    //         if (s[j-1] == 'S') wizards[i][j] = 0;
    //         else if (s[j-1 == 'L']) wizards[i][j] = 1;
    //         else wizards[i][j] = 2;
    //     }
    // }
    int n; cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a, b, c; cin >> a >> b >> c;
        if (a + b + c >= 2) ans++;
    }

    cout << ans << endl;
}