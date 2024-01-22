 #include <bits/stdc++.h>
using namespace std;

/*
Debug checklist
- DELETE CODE PORTIONS ONE BY ONE AND RUN
- Check bounds
- Long long
- Sample case
- Edge cases
*/

typedef long long ll;
#define f first
#define s second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int turn(int dir, int tur) { // up down left right
    if (tur == 1) {
        if (dir == 0) dir = 2;
        if (dir == 1) dir = 3;
        if (dir == 2) dir = 1;
        if (dir == 3) dir = 0;
    }
    else if (tur == 2) {
        if (dir == 0) dir = 3;
        if (dir == 1) dir = 2;
        if (dir == 2) dir = 0;
        if (dir == 3) dir = 1;
    }
    return dir;
}

pair<int,int> walk(int r, int c, int dir) { // up down left right
    if (dir == 0) r--;
    else if (dir == 1) r++;
    else if (dir == 2) c--;
    else c++;
    return {r, c};
}

signed main() {
    int n, k; cin >> n >> k;
    int m; cin >> m;
    // turns, time;
    vector<vector<vector<vector<vector<int>>>>> grid(n+1, vector<vector<vector<vector<int>>>>(n+1, vector<vector<vector<int>>>(7, vector<vector<int>>(4, vector<int>(2, -1)))));
    vector<vector<vector<int>>> wizards(n+1, vector<vector<int>>(n+1, vector<int>(7, 0))); // straight = 0, left = 1, right = 2
    for (int i = 1; i <= m; i++) {
        int x, y; cin >> x >> y;
        string s; cin >> s;
        for (int j = 0; j < 7; j++) {
            if (s[j] == 'L') wizards[x][y][j] = 1;
            else if (s[j] == 'R') wizards[x][y][j] = 2;
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //     }
    // }

    int t = 0;
    int r = 1, c = 1, dir = 3; //up, down, left, right
    int t1, turn1, ans = 0;
    int turns = 0;
    bool found = false;
    while (true) {
        turns++;
        if (r <= 0) dir = 1;
        else if (r > n) dir = 0;
        else if (c <= 0) dir = 3;
        else if (c > n) dir = 2;
        else turns--;
        if (wizards[r][c][t%7] != 0) {
            turn(dir, wizards[r][c][t%7]);
            turns++;
        }
        if (turns >= k) {
            found = true;
            cout << t << endl;
            break;
        }
        if (grid[r][c][t%7][dir][0] == -1) {
            grid[r][c][t%7][dir][0] = t;
            grid[r][c][t%7][dir][1] = turns;
        }
        else {
            t1 = t - grid[r][c][t%7][dir][0];
            turn1 = turn - grid[r][c][t%7][dir][1];
            ans += t;
            k -= turns;
        }
        
        t++;
    }
    
    if (!found) {
        k = turn1
    }
}