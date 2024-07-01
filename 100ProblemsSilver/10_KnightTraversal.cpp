#include <bits/stdc++.h>
using namespace std;

int n, m, xx, yy;

int board[401][401];
bool visited[401][401];
vector<int> x_ = {1, 1, 2, 2, -1, -1, -2, -2};
vector<int> y_ = {2, -2, 1, -1, 2, -2, 1, -1};

int main() {
  for (int i = 0; i < 401; i++) {
    for (int j = 0; j < 401; j++) {
      board[i][j] = -1;
      visited[i][j] = false;
    }
  }
  

  cin >> n >> m >> xx >> yy;
  
  board[xx][yy] = 0;
  visited[xx][yy] = true;

  queue<vector<int>> q;
  q.push({xx, yy, 0});
  while (!q.empty()) {
    vector<int> que = q.front();
    q.pop();
    int x = que[0];
    int y = que[1];
    int moves = que[2];
    for (int i = 0; i < 8; i++) {
      int _x = x + x_[i];
      int _y = y + y_[i];
      if (_x > 0 && _x <= n && _y > 0 && _y <= m && !visited[_x][_y]) {
        board[_x][_y] = moves + 1;
        visited[_x][_y] = true;
        q.push({_x, _y, moves + 1});
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
}