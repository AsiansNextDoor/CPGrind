#include <bits/stdc++.h>
using namespace std;

int n;
int shortestPath = 1e9;
int numShortest;

int maze[50][50];
int visited[50][50];

void dfs(int x, int y, int stepCount) {
  if (x < 0 || y < 0 || x >= n || y >= n || maze[x][y] == 1 || visited[x][y] == 1) {
    return;
  }
  visited[x][y] = 1;
  if (x == n - 1 && y == n - 1) {
    if (stepCount == shortestPath) {
      numShortest++;
    }
    if (stepCount < shortestPath) {
      numShortest = 1;
    }
    shortestPath = min(shortestPath, stepCount);
  }
  
  dfs(x + 1, y, stepCount + 1);
  dfs(x - 1, y, stepCount + 1);
  dfs(x, y + 1, stepCount + 1);
  dfs(x, y - 1, stepCount + 1);
  visited[x][y] = 0;
  stepCount -= 1;
}

int main() {
  cin >> n;
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> maze[i][j];
    }
  }

  dfs(0, 0, 1);
  cout << numShortest << endl;
  cout << shortestPath;
  return 0;
}
