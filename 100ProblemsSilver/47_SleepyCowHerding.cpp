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

    int n; cin >> n;
    vector<int> cows(n);
    for (int i = 0; i < n; i++) cin >> cows[i];

    sort(cows.begin(), cows.end());

    int minans = n;
    for (int i = 0; i < n; i++) {
        int ri = cows[i] + n - 1;
        auto it = upper_bound(cows.begin(), cows.end(), ri);
        int r = distance(cows.begin(), it);
        if (cows[r - 1] == ri) minans = min(n - (r - i), minans);
        else if (i > 1 || r < n - 1) minans = min(n - (r - i), minans);
    }

    
    for (int i = 0; i < n; i++) {
        int li = cows[i] - n + 1;
        auto it = lower_bound(cows.begin(), cows.end(), li);
        int l = distance(cows.begin(), it);
        if (cows[l] == li) minans = min(n - (i + 1 - l), minans);
        else if (i < n - 2 || l > 1) minans = min(n - (i + 1 - l), minans);
    }

    int maxans = 0;
    for (int i = 1; i < n; i++) maxans += cows[i] - cows[i - 1] - 1;
    int diff = min(cows[1] - cows[0] - 1, cows[n - 1] - cows[n - 2] - 1);
    maxans -= diff;

    cout << minans << endl;
    cout << maxans << endl;
}