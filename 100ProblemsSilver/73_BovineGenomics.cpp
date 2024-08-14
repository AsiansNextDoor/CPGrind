#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

int INF;

signed main() {
    IOS;

    int n, m; cin >> n >> m;
    vector<string> scow(n), pcow(n);
    for (int i = 0; i < n; i++) cin >> scow[i];
    for (int i = 0; i < n; i++) cin >> pcow[i];

    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            for (int k = j + 1; k < m; k++) {
                bool pass = true;
                if (i == j || k == i || k == j) continue;
                set<vector<char>> cows;
                for (int l = 0; l < n; l++) cows.insert({scow[l][i], scow[l][j], scow[l][k]});
                for (int l = 0; l < n; l++) {
                    if (cows.find({pcow[l][i], pcow[l][j], pcow[l][k]}) != cows.end()) {
                        pass = false;
                        break;
                    }
                }

                if (pass) ans++;
            }
        }
    }

    cout << ans << endl;
}