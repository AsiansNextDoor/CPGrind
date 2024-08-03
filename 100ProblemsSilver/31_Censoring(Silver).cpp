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
    
    string s, t; cin >> s >> t;

    stack<vector<int>> sub;
    vector<vector<int>> del;
    int sd = 1e7, ed = -1;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (sub.empty()) sub.push({0, i});

        int j = sub.top()[0], si = sub.top()[1];
        if (c == t[j]) {
            sub.pop();
            if (j + 1 == t.size()) {
                sd = min(si, sd);
                ed = i;
                if (sub.empty()) del.push_back({sd, ed});
            }
            else {
                sub.push({j + 1, si});
            }
        }
        else if (c == t[0]) sub.push({1, i});
        else {
            sub = stack<vector<int>>();
            if (sd != 1e7) {
                del.push_back({sd, ed});
                sd = 1e7;
                ed = -1;
            }
        }
    }

    for (auto data: del) {
        s[data[0]] = '1';
        s[data[1]] = '0';
    }
    
    bool print = true;    
    for (char c: s) {
        if (c == '1') print = false;
        if (print) cout << c;
        if (c == '0') print = true;
    }
}