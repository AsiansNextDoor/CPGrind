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

    int p = 0;
    set<int> ps; ps.insert(p);
    map<int, int> end;
    for (int i = 0; i < n; i++) {
        int units;
        char dir;
        cin >> units >> dir;
        if (dir == 'L') {
            end[p]--;
            p -= units;
            end[p]++;
        }
        else {
            end[p]++;
            p += units;
            end[p]--;
        }
        ps.insert(p);
    }

    int ans = 0;
    auto start = ps.begin();
    int prev = *start;
    int layers = end[prev];
    start++;
    for (start; start != ps.end(); start++) {
        if (layers >= k) {
            ans += *start - prev;
        }
        layers += end[*start];
        prev = *start;
    }

    cout << ans << endl;
}