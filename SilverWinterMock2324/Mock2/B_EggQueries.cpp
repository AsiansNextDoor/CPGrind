/*
Description:
Farmer John's farm can be represented as an n x m grid. There are cows in some cells of this grid. Some cells can have more than one cow as well.

The special feature of Farmer John's cows is that they grow from eggs. Every year, a cow egg falls out of the sky and drops into some cell (x, y). The cow closest to the egg will parent this baby cow. Within a year, this cow egg grows into a full-grown cow (i.e., it can parent an egg that falls in the future).

Farmer John has recorded where the cow eggs have fallen for q consecutive years. He is unsure who the parent of each cow egg was.

Your task is to determine the squared distance between the nearest cow and the egg that fell for each of the q years.

Distance is measured in unit fields of the matrix and is given by the formula:

distance((x1, y1), (x2, y2)) = (x1 - x2)^2 + (y1 - y2)^2

Input:
The first line of input contains 2 integers n, m (1 ≤ n, m ≤ 500) – the number of rows and the number of columns in Farmer John's farm grid.

The next n lines contain m characters each. Each character is either an 'x' or '.'. The character 'x' represents a cell with at least one cow and a '.' represents an empty cell.

The next line contains a single integer q (1 ≤ q ≤ 10^5) – the number of years Farmer John recorded data for.

The next q lines contain 2 integers each (xi, yi) – the cell (xi, yi) where the new cow egg fell.

In test cases worth 32%, it will hold that q ≤ 500.

Output:
Output q numbers, the required squared distance from the task, each in its line.

Examples:
Input 1
3 3
x..
...
...
3
1 3
1 1
3 2
Output 1
4
0
5

Input 2
5 5
..x..
....x
.....
.....
.....
4
3 1
5 3
4 5
3 5
Output 2
8
8
4
1

Sample Explanation:
In the first sample, the cow closest to the first egg (1, 3) is at (1, 1). By the next year, there is now a cow at (1, 3). The second egg coincides with (1, 1) and has a distance of 0. The third egg is equidistant to all 3 cows.

*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;
#define f first
#define s second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

signed main() {
    IOS;
    int n, m; cin >> n >> m;
    vector<vector<int>> grid(n+1, vector<int>(m+1, 1e6)); //1 indexed


    for (int i = 1; i <= n; i++) {
        string row; cin >> row;
        for (int j = 1; j <= m; j++) {
            if (row[j-1] != 'x') continue;
            for (int col = 1; col <= m; col++) {
                int dist = abs(col - j);
                grid[i][col] = min(dist * dist , grid[i][col]);
            }
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
 
    //cout << "q" << endl;
    int q; cin >> q; //cout << q << endl;
    while (q--) {
        //cout << "check1" << endl;
        int r, c; cin >> r >> c;

        int ans = 1e6;
        for (int i = 1; i <= n; i++) {
            int dist = abs(i - r);
            ans = min(grid[i][c] + (dist * dist), ans);
        }

        cout << ans << endl;

        for (int i = 1; i <= m; i++) {
            int dist = abs(c - i);
            grid[r][i] = min(dist * dist , grid[r][i]);
        }
    }
}