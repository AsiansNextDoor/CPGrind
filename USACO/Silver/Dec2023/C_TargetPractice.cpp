#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

signed main() {
    IOS;

    int t, c; cin >> t >> c;
    vector<int> targets(2*c+1, 0);
    for (int i = 0; i < t; i++) {
        int ts; cin >> ts;
        targets[ts+c]++;
    }
    string s; cin >> s;

    vector<int> scores(c);
    vector<set<int>> hits(c);

    int pos = 0;
    int score = 0;
    set<int> hit;

    for (int i = 0; i < c; i++) {
        if (s[i] == 'L') pos--;
        else if (s[i] == 'R') pos++;
        else {
            if (targets[pos+c] && hit.find(pos) == hit.end()) {
                hit.insert(pos);
                score++;
            }
        }

        scores[i] = score;
        hits[i] = hit;
    }

    int ans = hit.size();
    vector<vector<int>> ssum(5, vector<int>(c+1, 0));
    vector<set<int>> sufhit(5);
    vector<int> overcount(5, 0);
    for (int i = c-1; i >= 0; i--) {
        if (s[i] == 'L') pos++;
        else if (s[i] == 'R') pos--;
        else {
            for (int j = -2; j <= 2; j++) {
                pos += j;
                if (pos+c < 0 || pos+c > 2*c) continue;
                if (targets[pos+c] && sufhit[j+2].find(pos) == sufhit[j+2].end()) {
                    sufhit[j+2].insert(pos);
                    ssum[i][j+2]++;
                }
                pos -= j;
            }
        }

        for (int j = 0; j <= 4; j++) {

        }
    }
}