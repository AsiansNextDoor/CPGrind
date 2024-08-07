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

    int n, k; cin >> n >> k;

    vector<int> trees(n);
    for (int i = 0; i < n; i++) cin >> trees[i];
    
    int ans = 0;
    for (int b = 1; b <= 1000; b++) {
        multiset<int> berry;
        for (int t: trees) berry.insert(t);

        int baskets = 0;
        int tot = 0;
        while (!berry.empty() && baskets < k) {
            auto it = berry.end(); it--;
            int curb = *it; berry.erase(it);
            if (curb > b){
                for (int i = 0; i < curb / b; i++) {
                    baskets++;
                    if (baskets > k / 2) tot += b;
                    if (baskets == k) break;
                }
                berry.insert(curb % b);
            }
            else {
                baskets++;
                if (baskets > k / 2) tot += curb;
            }
        }
        //if (tot > ans) cout << b << endl;
        ans = max(tot, ans);
    }

    cout << ans << endl;
}