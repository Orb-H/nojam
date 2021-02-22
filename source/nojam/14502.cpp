#include <iostream>
#include <queue>

using namespace std;

int n, m, blank = -3;
int map[8][8];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int count_blank() {
    int visited[8][8] = {0,};
    queue<pair<int, int>> q;
    pair<int, int> cur;
    int res = blank;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (map[i][j] == 2)
                q.push({i, j});

    while (!q.empty()) {
        cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            if (cur.first + dy[i] >= 0 && cur.first + dy[i] < n && cur.second + dx[i] >= 0 && cur.second + dx[i] < m) {
                if (!map[cur.first + dy[i]][cur.second + dx[i]] && !visited[cur.first + dy[i]][cur.second + dx[i]]) {
                    res--;
                    q.push({cur.first + dy[i], cur.second + dx[i]});
                    visited[cur.first + dy[i]][cur.second + dx[i]] = 1;
                }
            }
        }
    }

    return res;
}

int find(int walls, int fin) {
    int max = 0, tmp;

    if (walls == 3) {
        return count_blank();
    } else {
        for (int i = fin + 1; i < n * m; i++) {
            if (!map[i / m][i % m]) {
                map[i / m][i % m] = 1;
                tmp = find(walls + 1, i);
                if (tmp > max) max = tmp;
                map[i / m][i % m] = 0;
            }
        }
    }

    return max;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            blank += !map[i][j];
        }
    }

    cout << find(0, -1);
}