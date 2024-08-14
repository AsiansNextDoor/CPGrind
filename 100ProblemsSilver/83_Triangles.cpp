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

    map<int, vector<int>> horiz, vert;
    vector<vector<int>> posts;
    set<int> setxs, setys;
    for (int i = 0; i < n ; i++) {
        int x, y; cin >> x >> y;
        x += 1e4;
        y += 1e4;
        horiz[y].push_back(x);
        vert[x].push_back(y);
        posts.push_back({x, y});
        setxs.insert(x); setys.insert(y);
    }


    int toth = 0, totv = 0;
    map<int, vector<int>> psumh;
    map<int, vector<int>> psumv;
    map<int, vector<int>> ssumh;
    map<int, vector<int>> ssumv;
    vector<int> xs, ys;
    for (int x: setxs) xs.push_back(x);
    for (int y: setys) ys.push_back(y);
    for (int i = 0; i < xs.size(); i++) {
        int x = xs[i];
        sort(vert[x].begin(), vert[x].end());

        int dist = 0;
        psumv[x].resize(vert[x].size(), 0);
        ssumv[x].resize(vert[x].size(), 0);
        cout << 0 << " ";
        for (int i = 1; i < vert[x].size(); i++) {
            dist += i * (vert[x][i] - vert[x][i - 1]);
            psumv[x][i] = dist + psumv[x][i - 1];
            cout << dist << " ";
        }
        cout << endl;
        dist = 0;
        for (int i = vert[x].size() - 1; i >= 0; i--) {
            dist += i * (vert[x][i + 1] - vert[x][i]);
            ssumv[x][i] = dist + ssumv[x][i + 1];
        }
    }


    
    for (int i = 0; i < ys.size(); i++) {
        int y = ys[i];
        sort(horiz[y].begin(), horiz[y].end());

        int dist = 0;
        psumh[y].resize(horiz[y].size(), 0);
        ssumh[y].resize(horiz[y].size(), 0);
        for (int i = 1; i < horiz[y].size(); i++) {
            dist += i * (horiz[y][i] - horiz[y][i - 1]);
            psumh[y][i] = dist + psumh[y][i - 1];
        }
        dist = 0;
        for (int i = horiz[y].size() - 1; i >= 0; i--) {
            dist += i * (horiz[y][i + 1] - horiz[y][i]);
            ssumh[y][i] = dist + ssumh[y][i + 1];
        }
    }

    for (int i = 0; i < n; i++) {
        int x = posts[i][0], y = posts[i][1];
        int xi = lower_bound(vert[x].begin(), vert[x].end(), y) - vert[x].begin();
        cout << psumv[x][xi] + ssumv[x][xi] << endl;
    }
}