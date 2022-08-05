// Problem Link: https://codeforces.com/contest/1669/problem/G

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void moveDown(vector<string> &maze, int x, int y) {
    int i = x + 1;
    while (i < maze.size() && maze[i][y] == '.') {
        i++;
    }
    maze[x][y] = '.';
    maze[i - 1][y] = '*';
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> maze(n);
    for (int i = 0; i < n; i++) {
        cin >> maze[i];
    }
    for (int j = 0; j < m; j++) {
        for (int i = n - 1; i >= 0; i--) {
            if (maze[i][j] == '*') {
                moveDown(maze, i, j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << maze[i] << "\n";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}