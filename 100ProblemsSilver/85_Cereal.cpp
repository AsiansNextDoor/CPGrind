#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int INF;

signed main() {
    IOS;

    freopen("cereal.in", "r", stdin);
    freopen("cereal.out", "w", stdout);

    int n, m; cin >> n >> m;
    vector<vector<int>> cows(n, vector<int>(2));
    for (int i = 0; i < n; i++) cin >> cows[i][0] >> cows[i][1];

    vector<int> visited(m + 1, 0);
    vector<vector<int>> box(n, vector<int>(2, -1)); // cereal box, choice number

    int cow = 0;
    map<int, set<vector<int>>> skip; // cereal box -> cow numbers
    for (int i = 0; i < n; i++) {
        int f = cows[i][0], s = cows[i][1];
        if (!visited[f]) {
            box[i][0] = f;
            box[i][1] = 0; 
            cow++;
            visited[f]++;
        }
        else if (!visited[s]) {
            skip[f].insert({i, 0});
            box[i][0] = s;
            box[i][1] = 1;
            cow++;
            visited[s]++;
        }
        else {
            skip[f].insert({i, 0});
            skip[s].insert({i, 1});
        }

    }
    cout << cow << endl;
    for (int i = 0; i < n - 1; i++) {
        queue<int> check;
        check.push(box[i][0]);
        cow--;
        while (!check.empty()) {
            int bnum = check.front(); check.pop();
            if (skip[bnum].empty()) break;

            auto data = *skip[bnum].begin(); skip[bnum].erase(skip[bnum].begin());
            int cur = data[0], schoice = data[1];
            int cbox = box[cur][0], choice = box[cur][1];

            if (choice == -1 && schoice == 0) { // remove second choice since first choice fulfilled
                skip[cows[cur][1]].erase(skip[cows[cur][1]].find({cur, 1}));
            }
            else if (choice == 1) check.push(cbox);

            box[cur][0] = bnum;
            box[cur][1] = schoice;
            if (choice == -1) cow++;
        }

        cout << cow << endl;
    }
}