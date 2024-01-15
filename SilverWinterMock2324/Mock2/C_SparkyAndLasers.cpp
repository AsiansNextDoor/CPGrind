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
    IOS;
    int l, r; cin >> l >> r;

    vector<vector<int>> laser(r+1);
    vector<int> sum(r+1, 0);
    for (int i = 0; i < r; i++) {
        int c; cin >> c;
        for (int j = 0; j < c; j++) {
            int l1; cin >> l1;
            laser[i].push_back(l1);
            sum[i] += l1;
        }
    }

    vector<pair<int,int>> range;
    for (int i = 0; i < r; i++) {
        int lsum = 0;
        int rsum = sum[i];
        for (int j = 0; j < laser[i].size(); j++) {
            int block = laser[i][j];
            rsum -= block;
            int l1 = lsum + 1, r1 = l - rsum; //cout << "l1: " << l1 << "  r1: " << r1 << endl;
            int l2 = r1 - block + 1; 
            int r2 = l1 + block - 1;
            //cout << "l2: " << l2 << "  r2: " << r2 << endl;

            if (l2 <= r2) range.push_back({l2, r2});

            lsum += block;
        }
        //cout << endl;
    }

    sort(range.begin(), range.end());
    // for (int i = 0; i < range.size(); i++) {
    //     cout << range[i].s << " " << range[i].f << endl;
    // }

    int ans = 0;
    int left = 0, right = -1;
    for (int i = 0; i < range.size(); i++) {
        if (i == 0) {
            left = range[i].f;
            right = range[i].s;
        }
        else {
            int l1 = range[i].f;
            int r1 = range[i].s;
            if (l1 <= right) {
                right = max(r1, right);
            }
            else {
                ans += right - left + 1;
                left = l1;
                right = r1;
            }
        }
        //cout << "left: " << left << endl;
        //cout << "right: " << right << endl;
    }

    ans += right - left + 1;
    cout << ans << endl;
}