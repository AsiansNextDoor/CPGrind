#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

signed main() {
    IOS;

    ll t; cin >> t;
    while (t--) {
        int n, q, c; cin >> n >> q >> c; //cows, pairs, max score
        vector<int> scores(n+1, -1);
        for (int i = 1; i <= n; i++) cin >> scores[i];
        vector<int> left0(n+1, -1);
        for (int i = 1; i <= n; i++) {
            left0[i] = left0[i-1];
            if (scores[i] == 0) left0[i] = i;
        }
        for (int i = 1; i <= n; i++) if (scores[i] == 0) scores[i] = 1;
        vector<pair<int,int>> pairs(q);
        for (int i = 0; i < q; i++) cin >> pairs[i].f >> pairs[i].s;

        sort(pairs.begin(), pairs.end());

        vector<int> pmax(n+1, 0);
        for (int i = 1; i <= n; i++){
            pmax[i] = max(pmax[i-1], scores[i]);
        }

        bool valid = true;
        vector<pair<int,int>> temppairs;
        int prevh = -1;
        for (int i = 0; i < q; i++) {
            int a = pairs[i].f, h = pairs[i].s;
            if (h == prevh) continue;
            if (a < prevh) {
                valid = false;
                break;
            }
            prevh = h;
            temppairs.push_back({a, h});
        }

        auto allpairs = pairs;
        pairs = temppairs;

        if (!valid) {
            cout << -1 << endl;
            continue;
        }

        q = pairs.size();
        int prem = -1;
        for (int i = 0; i < q; i++) {
            int a = pairs[i].f, h = pairs[i].s;
            pmax[a] = max(pmax[a], prem);
            pmax[h-1] = max(pmax[h-1], prem);
            pmax[h] = max(pmax[h], prem);

            if (pmax[a] < pmax[h-1]) {
                //cout << a << " " << h << endl;
                if (left0[a] == -1) {
                    valid = false;
                    break;
                }
                scores[left0[a]] = pmax[h-1];
            }
            if (scores[h] <= pmax[h-1]) {
                //cout << a << " h " << h << endl;
                if (left0[h] != h) {
                    valid = false;
                    break;
                }
                scores[h] = pmax[h-1] + 1;
            }
            prem = scores[h];
        }
        if (!valid) {
            cout << -1 << endl;
            continue;
        }

        for (int i = 1; i <= n; i++) pmax[i] = max(pmax[i-1], scores[i]);
        for (int i = 1; i <= n; i++) {
            if (pmax[i] > c) {
                valid = false;
                break;
            }
        }
        if (!valid) {
            cout << -1 << endl;
            continue;
        }
        //for (int i = 1; i <= n; i++) cout << pmax[i] << " ";
        //cout << endl;
        for (int i = 0; i < allpairs.size(); i++) {
            int a = allpairs[i].f, h = allpairs[i].s;
            if (pmax[a] < pmax[h-1] || pmax[a] >= pmax[h]) {
                cout << a << " " << h << endl;
                valid = false;
                break;
            }
        }
        if (!valid) {
            cout << -1 << endl;
            continue;
        }
        
        for (int i = 1; i <= n; i++) {
            if (i == 1) cout << scores[i];
            else cout << " " << scores[i];
        }
        cout << endl;
        
    }
}