#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

int INF;

signed main() {
    IOS;

    int n; cin >> n;
    vector<int> cows(n);
    map<int, int> nums;
    for (int i = 0; i < n; i++) {
        int num, cow; cin >> num >> cow;
        cows[i] = cow;
        nums[cow] = num;
    }

    sort(cows.begin(), cows.end());

    int ans = 0;
    int i = 0, j = n - 1;
    while (i <= j) {
        int l = cows[i], r = cows[j];
        if (nums[l] < nums[r]) {
            nums[r] -= nums[l];
            i++;
        }
        else if (nums[l] > nums[r]) {
            nums[l] -= nums[r];
            j--;
        }
        else {
            i++;
            j--;
        }

        ans = max(l + r, ans);
    }

    cout << ans << endl;
}