#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

signed main() {
    IOS;

    int n, k; cin >> n >> k;
    vector<vector<int>> grid(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == '#') grid[i][j] = 1;
        }
    }

    // total cost, index
    vector<deque<vector<int>>> horiz(n);
    vector<deque<vector<int>>> vert(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                horiz[i].push_front({0, 0});
                vert[j].push_front({0, 0});
            }
            else if (i == n-1 && j == n-1) {
                if (!horiz[i].empty() && horiz[i].back()[1] + k < j) horiz[i].pop_back();
                if (!vert[j].empty() && vert[j].back()[1] + k < i) vert[j].pop_back();
                int val = 1e9;
                if (!horiz[i].empty()) {
                    val = min(horiz[i].back()[0] + 1, val);
                }

                if (!vert[j].empty()) {
                    val = min(vert[j].back()[0] + 1, val);
                }

                if (val == 1e9) cout << -1 << endl;
                else cout << val << endl;
            }
            else {
                if (!horiz[i].empty() && horiz[i].back()[1] + k < j) horiz[i].pop_back();
                if (!vert[j].empty() && vert[j].back()[1] + k < i) vert[j].pop_back();
                if (grid[i][j] == 1) continue; 
                int val = 1e9;
                if (!horiz[i].empty()) {
                    val = min(horiz[i].back()[0] + 1, val);
                }

                if (!vert[j].empty()) {
                    val = min(vert[j].back()[0] + 1, val);
                }
                    
                if (val == 1e9) continue;
                while (!horiz[i].empty()) {
                    if (horiz[i].front()[0] >= val) horiz[i].pop_front();
                    else break;
                }

                while (!vert[j].empty()) {
                    if (vert[j].front()[0] >= val) vert[j].pop_front();
                    else break;
                }
                horiz[i].push_front({val, j});
                vert[j].push_front({val, i});
            }
        }
    }
    if (n == 1) cout << 0 << endl;
}