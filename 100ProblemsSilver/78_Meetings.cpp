#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int INF;

signed main() {
    IOS;

    int n, l; cin >> n >> l;
    vector<int> lcows;
    vector<int> rcows;
    vector<vector<int>> w1;
    for (int i = 0; i < n; i++) {
        int w, x, d; cin >> w >> x >> d;
        if (d == 1) rcows.push_back(x);
        else lcows.push_back(x);
        w1.push_back({x, w});
    }

    sort(lcows.begin(), lcows.end());
    sort(rcows.begin(), rcows.end());
    sort(w1.begin(), w1.end());

    int totw = 0;
    deque<int> weights;
    for (int i = 0; i < n; i++) {
        totw += w1[i][1];
        weights.push_back(w1[i][1]);
    }

    map<int, int> meetings;
    for (int x: lcows) {
        meetings[x] = lower_bound(rcows.begin(), rcows.end(), x) - rcows.begin();
    }
    for (int x: rcows) {
        meetings[x] = lcows.end() - upper_bound(lcows.begin(), lcows.end(), x);
    }

    vector<vector<int>> cows;
    for (int x: lcows) cows.push_back({x, x, -1});
    for (int x: rcows) cows.push_back({l - x, x, 1});

    sort(cows.begin(), cows.end());

    int ans = 0;
    int curw = 0;
    int t;
    vector<int> left, right;
    int i = 0;
    for (i; i < n; i++) {
        auto data = cows[i];
        t = data[0];
        int x = data[1], dir = data[2];
        ans += meetings[x];
        if (dir == -1) {
            curw += weights.front(); 
            weights.pop_front();
            left.push_back(x);
        }
        else {
            curw += weights.back(); 
            weights.pop_back();
            right.push_back(x);
        }
        if (curw * 2 >= totw) break;
    }

    for (int j = i + 1; j < n; j++) {
        auto data = cows[j];
        int x = data[1], dir = data[2];
        if (dir == 1) {
            ans += upper_bound(lcows.begin(), lcows.end(), x + t * 2) - 
            upper_bound(lcows.begin(), lcows.end(), x);
        }
        else {
            ans += upper_bound(rcows.begin(), rcows.end(), x) - 
            lower_bound(rcows.begin(), rcows.end(), x - t * 2);
        }
    }


    cout << ans / 2 << endl;
}