#include <iostream>
#include <queue>
#include <string>

using namespace std;

typedef struct {
    int i;
    int j;
    int broken;
} node;

int main() {
    int n, m;
    queue<node> q;
    node cur;
    string map[1001];
    int min_normal[1001][1001];
    int min_break[1001][1001];

    int di[4] = {-1, 0, 1, 0};
    int dj[4] = {0, -1, 0, 1};

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> map[i];
        for (int j = 0; j < m; j++) {
            min_normal[i][j] = 2147483647;
            min_break[i][j] = 2147483647;
        }
    }
    
    q.push({0, 0, 0});
    min_normal[0][0] = 1;
    min_break[0][0] = 1;

    while (!q.empty()) {
        cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            if (cur.i + di[i] >= 0 && cur.i + di[i] < n && cur.j + dj[i] >= 0 && cur.j + dj[i] < m) {
                if (!cur.broken) {
                    if (map[cur.i + di[i]][cur.j + dj[i]] == '0') {
                        if (min_normal[cur.i + di[i]][cur.j + dj[i]] > min_normal[cur.i][cur.j] + 1) {
                            q.push({cur.i + di[i], cur.j + dj[i], 0});
                            min_normal[cur.i + di[i]][cur.j + dj[i]] = min_normal[cur.i][cur.j] + 1;
                        }
                    } else {
                        if (min_break[cur.i + di[i]][cur.j + dj[i]] > min_normal[cur.i][cur.j] + 1) {
                            q.push({cur.i + di[i], cur.j + dj[i], 1});
                            min_break[cur.i + di[i]][cur.j + dj[i]] = min_normal[cur.i][cur.j] + 1;
                        }
                    }
                } else if (map[cur.i + di[i]][cur.j + dj[i]] == '0' && min_break[cur.i + di[i]][cur.j + dj[i]] > min_break[cur.i][cur.j] + 1) {
                    q.push({cur.i + di[i], cur.j + dj[i], 1});
                    min_break[cur.i + di[i]][cur.j + dj[i]] = min_break[cur.i][cur.j] + 1;
                }
            }
        }
    }

    if (min_break[n - 1][m - 1] == 2147483647 && min_normal[n - 1][m - 1] == 2147483647)
        cout << -1;
    else
        cout << (min_break[n - 1][m - 1] < min_normal[n - 1][m - 1] ? min_break[n - 1][m - 1] : min_normal[n - 1][m - 1]);
}