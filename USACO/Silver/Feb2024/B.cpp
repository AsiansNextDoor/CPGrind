#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N, X1;
        cin >> N >> X1;

        vector<vector<int>> targets(N, vector<int>(3));
        for (int i = 0; i < N; ++i) {
            cin >> targets[i][0] >> targets[i][1] >> targets[i][2];
        }

        vector<int> slopes(4 * N);
        for (int i = 0; i < 4 * N; ++i) {
            cin >> slopes[i];
        }

        vector<vector<int>> py(N);
        for (int i = 0; i < N; ++i) {
            for (int j = 1; j <= 4; ++j) {
                int y = targets[i][0] + (targets[i][1] - targets[i][0]) * j / 5;
                py[i].push_back(y);
            }
            sort(py[i].begin(), py[i].end());
        }

        ll min_dist = LLONG_MAX;
        for (int i = 0; i < 4 * N; ++i) {
            int target_idx = i / 4;
            int y_idx = i % 4;
            int y = py[target_idx][y_idx];
            ll dist = abs(y) + abs(X1);
            for (int j = 0; j < 4 * N; ++j) {
                if (j == i) continue;
                int other_target_idx = j / 4;
                int other_y_idx = j % 4;
                int other_y = py[other_target_idx][other_y_idx];
                if ((y - other_y) * slopes[j] >= 0) {
                    dist = -1;
                    break;
                }
                dist = min(dist, abs(y - other_y) + abs(X1));
            }
            if (dist != -1) {
                min_dist = min(min_dist, dist);
            }
        }

        if (min_dist == LLONG_MAX) {
            cout << -1 << endl;
        } else {
            cout << min_dist << endl;
        }
    }

    return 0;
}
