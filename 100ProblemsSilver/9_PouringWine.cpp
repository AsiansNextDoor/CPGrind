#include <bits/stdc++.h>
using namespace std;


int main() {
  vector<vector<int>> visited;
  queue<vector<int>> q;
  int c1, c2, c3;
  int a, b, c, counts, dif;
  bool print = false;
  cin >> c1 >> c2 >> c3;

  int target = c1/2;
  
  q.push({c1,0,0,0});
  visited.push_back({c1, 0, 0});


  int counter = 0;
  vector<int>vals;

  while (!q.empty()) {
    vals = q.front();
    q.pop();

    a = vals[0];
    b = vals[1];
    c = vals[2];
    counts = vals[3];

    counter += 1;
    if (counter > 500) {
      break;
    }

    if ((a == target && b == target) || (a == target && c == target) || (b == target && c == target)){
      cout << counts << endl;
      print = true;
      break;
    }

    for (int i = 0; i < 3; i++) {
      if (i == 0) {
        if (a != 0 && b < c2) {
          if (a + b <= c2) {
            vector<int>temp = {0, b+a, c, counts+1};
            if (find(visited.begin(), visited.end(), temp) == visited.end()){
              visited.push_back({0, b+a, c, counts+1});
              q.push({0, b+a, c, counts+1});
            }
            
          }
          else {
            dif = c2 - b; 
            vector<int>temp = {a-dif, b+dif, c, counts+1};
            if (find(visited.begin(), visited.end(), temp) == visited.end()){
              visited.push_back({a-dif, b+dif, c, counts+1});//
              q.push({a-dif, b+dif, c, counts+1});
            }
            
          }
        }
        if (a != 0 && c < c3) {
          if (a + c <= c3) {
            vector<int>temp = {0, b, c+a, counts+1};
            if (find(visited.begin(), visited.end(), temp) == visited.end()){
              visited.push_back({0, b, c+a, counts+1});
              q.push({0, b, c+a, counts+1});
            }
            
          }
          else {
            dif = c3 - c;
            vector<int>temp = {a-dif, b, c+dif, counts+1};
            if (find(visited.begin(), visited.end(), temp) == visited.end()){
              visited.push_back({a-dif, b, c+dif, counts+1});
              q.push({a-dif, b, c+dif, counts+1});
            }
            
          }
        }
      }
      else if (i == 1) {
        if (b != 0){
          vector<int>temp = {a+b, 0, c, counts+1};
          if (find(visited.begin(), visited.end(), temp) == visited.end()){
            visited.push_back({a+b, 0, c, counts+1});
            q.push({a+b, 0, c, counts+1});
          }
          
        }
        if (b != 0 && c < c3) {
          if (b + c <= c3) {
            vector<int>temp = {a, 0, c+b, counts+1};
            if (find(visited.begin(), visited.end(), temp) == visited.end()){
              visited.push_back({a, 0, c+b, counts+1});
              q.push({a, 0, c+b, counts+1});
            }
            
          }
          else {
            dif = c3 - c;
            vector<int>temp = {a, b-dif, c+dif, counts+1};
            if (find(visited.begin(), visited.end(), temp) == visited.end()){
              visited.push_back({a, b-dif, c+dif, counts+1});
              q.push({a, b-dif, c+dif, counts+1});
            }
            
          }
        }
      }
      else {
        if (c != 0) {
          vector<int>temp = {a+c, b, 0, counts+1};
          if (find(visited.begin(), visited.end(), temp) == visited.end()){
            visited.push_back({a+c, b, 0, counts+1});
            q.push({a+c, b, 0, counts+1});
          }
          
        }
        if (c != 0 && b < c2) {
          if (b + c <= c2) {
            vector<int>temp = {a, b+c, 0, counts+1};
            if (find(visited.begin(), visited.end(), temp) == visited.end()){
              visited.push_back({a, b+c, 0, counts+1});
              q.push({a, b+c, 0, counts+1});
            }
            
          }
          else {
            dif = c2 - b;
            vector<int>temp = {a, b+dif, c-dif, counts+1};
            if (find(visited.begin(), visited.end(), temp) == visited.end()){
              visited.push_back({a, b+dif, c-dif, counts+1});
              q.push({a, b+dif, c-dif, counts+1});
            }
            
          }
        }
      }
    }
  }
  if (print == false) {
    cout << "NO" << endl;
  }
}