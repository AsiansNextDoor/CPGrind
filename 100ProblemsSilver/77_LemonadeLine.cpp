#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int INF;

signed main() {
    IOS;

    int n; cin >> n;
    vector<int> line(n);
    for (int i = 0; i < n; i++) cin >> line[i];

    sort(line.begin(), line.end());

    deque<int> dq;
    for (int i = 0; i < n; i++) dq.push_back(line[i]);

    int cows = 0;
    while (!dq.empty()) {
        int cow = dq.front();
        if (cow < cows) dq.pop_front();
        else {
            dq.pop_back();
            cows++;
        }
    }

    cout << cows << endl;
}