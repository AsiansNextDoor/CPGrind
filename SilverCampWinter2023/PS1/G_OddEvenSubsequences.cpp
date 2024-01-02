#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define f first
#define s second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int n, k;
vector<int> a;

bool check(int x, int cur) { // x is indexes of cost of subsequence k

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (cur == 0) {
            ans++;
            cur = 1 - cur;
        }
        else {
            if (a[i] <= x) {
                ans++;
                cur = 1 - cur;
            }
        }
    }

    return (ans >= k);
}

signed main() {
    IOS;
    
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }


    int l = 0, r = 1e9, ans;
    while (l <= r) {
        int mid = (l + r) / 2;
        //cout << "lr: " << l << " " << r << endl;
        //cout << "mid: " << mid << '\n';
        if (check(mid, 0) || check(mid, 1)) {
            ans = mid;
            //cout << "ans: " << ans << endl;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
        //cout << '\n';
    }

    cout << ans << '\n';
}