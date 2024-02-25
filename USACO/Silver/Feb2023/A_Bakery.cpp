#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

int n, tc, tm;
vector<vector<int>> cows(100, vector<int>(3));

bool checkc (int x, int m) {
    for (int i = 0; i < n; i++) {
        int a = cows[i][0], b = cows[i][1], c = cows[i][2];
        if (a < b) continue;
        
        int tot = a*(tc-x) + b*(tm-(m-x));
        if (tot > c) return false;
    }

    return true;
}

bool checkm (int x, int m) {
    for (int i = 0; i < n; i++) {
        int a = cows[i][0], b = cows[i][1], c = cows[i][2];
        if (a >= b) continue;
        
        int tot = a*(tc-(m-x)) + b*(tm-x);
        if (tot > c) return false;
    }

    return true;
}

bool check (int x) {
    int c, m;
    int l = 0, r = min(tc-1, x);
    while (l <= r) {
        int mid = (l + r) / 2;
        if (checkc(mid, x)) {
            c = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    
    l = 0, r = min(tm-1, x);
    while (l <= r) {
        int mid = (l + r) / 2;
        if (checkm(mid, x)) {
            m = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    cout << x << " " << c << " " << m << endl;
    if (c + m > x) return false;
    return true;
}

signed main() {
    IOS;
    ll t; cin >> t;
    while (t--) {
        int n, tc, tm; cin >> n >> tc >> tm;
        for (int i = 0; i < n; i++) cin >> cows[i][0] >> cows[i][1] >> cows[i][2];

        int l = 0, r = tc+tm-2, ans = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (check(mid)) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        cout << ans << endl;
    }
}