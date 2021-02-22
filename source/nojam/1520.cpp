#include <iostream>
#include <queue>

using namespace std;

typedef struct _pos {
    int h;
    int y;
    int x;
} pos;

typedef struct _compare {
    bool operator()(pos a, pos b) {
        return a.h < b.h;
    }
} compare;

int main() {
    int n, m;
    int board[500][500];
    int cases[500][500] = {0,};
    int visited[500][500] = {0,};
    priority_queue<pos, vector<pos>, compare> q;
    pos p;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    cases[0][0] = 1;
    q.push({board[0][0], 0, 0});

    while (!q.empty()) {
        p = q.top();
        q.pop();

        if (p.y > 0 && board[p.y][p.x] > board[p.y - 1][p.x]) {
            cases[p.y - 1][p.x] += cases[p.y][p.x];
            if (!visited[p.y - 1][p.x]) {
                q.push({board[p.y - 1][p.x], p.y - 1, p.x});
                visited[p.y - 1][p.x] = 1;
            }
        }
        if (p.y < n - 1 && board[p.y][p.x] > board[p.y + 1][p.x]) {
            cases[p.y + 1][p.x] += cases[p.y][p.x];
            if (!visited[p.y + 1][p.x]) {
                q.push({board[p.y + 1][p.x], p.y + 1, p.x});
                visited[p.y + 1][p.x] = 1;
            }
        }
        if (p.x > 0 && board[p.y][p.x] > board[p.y][p.x - 1]) {
            cases[p.y][p.x - 1] += cases[p.y][p.x];
            if (!visited[p.y][p.x - 1]) {
                q.push({board[p.y][p.x - 1], p.y, p.x - 1});
                visited[p.y][p.x - 1] = 1;
            }
        }
        if (p.x < m - 1 && board[p.y][p.x] > board[p.y][p.x + 1]) {
            cases[p.y][p.x + 1] += cases[p.y][p.x];
            if (!visited[p.y][p.x + 1]) {
                q.push({board[p.y][p.x + 1], p.y, p.x + 1});
                visited[p.y][p.x + 1] = 1;
            }
        }
    }

    cout << cases[n - 1][m - 1];
}