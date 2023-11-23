#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<string> spotty(N);
    vector<string> plain(N);

    for (int i = 0; i < N; ++i) {
        cin >> spotty[i];
    }

    for (int i = 0; i < N; ++i) {
        cin >> plain[i];
    }

    int count = 0;

    for (int pos1 = 0; pos1 < M - 2; ++pos1) {
        for (int pos2 = pos1 + 1; pos2 < M - 1; ++pos2) {
            for (int pos3 = pos2 + 1; pos3 < M; ++pos3) {
                set<string> spottySet;

                for (int i = 0; i < N; ++i) {
                    string pattern = "";
                    pattern += spotty[i][pos1];
                    pattern += spotty[i][pos2];
                    pattern += spotty[i][pos3];
                    spottySet.insert(pattern);
                }

                bool canExplain = true;

                for (int i = 0; i < N; ++i) {
                    string pattern = "";
                    pattern += plain[i][pos1];
                    pattern += plain[i][pos2];
                    pattern += plain[i][pos3];

                    if (spottySet.count(pattern) > 0) {
                        canExplain = false;
                        break;
                    }
                }

                if (canExplain) {
                    count++;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}
