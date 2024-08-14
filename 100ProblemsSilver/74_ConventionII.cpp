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
    set<vector<int>> cows;
    set<vector<int>> wait;
    for (int i = 0; i < n; i++) {
        int a, t; cin >> a >> t;
        cows.insert({a, i, t});
    }

    int ans = 0;
    int time = 0;
    while (!cows.empty() || !wait.empty()) {
        while (!cows.empty()) {
            auto data = *cows.begin(); 
            int a = data[0], o = data[1], t = data[2];
            if (a <= time) {
                wait.insert({o, a, t});
                cows.erase(cows.begin());
            }
            else break;
        }
        
        if (!wait.empty()) {
            auto data = *wait.begin(); wait.erase(wait.begin());
            int a = data[1], t = data[2];
            ans = max(time - a, ans);
            time += t;
        }
        else {
            auto data = *cows.begin(); cows.erase(cows.begin());
            int a = data[0], t = data[2];
            time = a + t;
        }
    }

    cout << ans << endl;
}