#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

int INF;

int n;
set<int> start;
map<int, int> end;

bool check(int x) {
    int pcow = *start.begin();
    
    bool pass = true;
    auto it = start.begin();
    for (int i = 1; i <= n; i++) {
        int pos = pcow + x;
        while (end[*it] < pos && it != start.end()) it++;
        if (it == start.end()) {
            pass = false;
            break;
        }
        pcow = max(*it, pos);
    }

    return pass;
}

signed main() {
    IOS;

    int m; cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int l, r; cin >> l >> r;
        start.insert(l);
        end[l] = r;
    }

    int l = 0;
    int r = 1e9, mid;
    int ans = 1e9;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (check(mid))
        {
            ans = min(ans, mid);
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << ans << endl;
}