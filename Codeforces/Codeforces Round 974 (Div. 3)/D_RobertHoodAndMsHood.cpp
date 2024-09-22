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
        int n, d, k; cin >> n >> d >> k;
        
        vector<vector<int>> jobin(n + 2);
        vector<vector<int>> jobout(n + 2);
        for (int i = 0; i < k; i++) {
            int l, r; cin >> l >> r;
            jobin[l].push_back(i);
            jobout[r].push_back(i);
        }

        set<int> s;
        for (int i = 1; i <= d; i++) {
            for (int j: jobin[i]) s.insert(j);
        }
        int maxj = s.size(), minj = s.size();
        int maxi = 1, mini = 1;
        for (int i = d + 1; i <= n; i++) {
            for (int j: jobout[i - d]) s.erase(j);
            for (int j: jobin[i]) s.insert(j);

            if (s.size() >  maxj) {
                maxj = s.size();
                maxi = i - d + 1;
            }
            if (s.size() < minj) {
                minj = s.size();
                mini = i - d + 1;
            }
        }

        cout << maxi << " " << mini << endl;
    }
}