#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> maze(n);
        vector<pair<int, int>> cord;
        for (int i = 0; i < n; i++) {
            cin >> maze[i];
            for (int j = 0; j < n; j++) {
                if (maze[i][j] == '*') {
                    cord.push_back({i, j});
                }
            }
        }
        if (cord[0].y == cord[1].y) {
            maze[cord[0].x][(cord[0].y + 1) % n] = '*';
            maze[cord[1].x][(cord[1].y + 1) % n] = '*';
        } else if (cord[0].x == cord[1].x) {
            maze[(cord[0].x + 1) % n][cord[0].y] = '*';
            maze[(cord[1].x + 1) % n][cord[1].y] = '*';
        } else {
            maze[cord[0].x][cord[1].y] = '*';
            maze[cord[1].x][cord[0].y] = '*';
        }
        for (int i = 0; i < n; i++) {
            cout << maze[i] << "\n";
        }
    }
    return 0;
}
