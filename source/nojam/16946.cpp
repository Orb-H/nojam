#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

int main() {
    int n, m, count = 0;
    queue<pi> q;
    vector<int> v;
    pi tmp;
    char board[1001][1001];
    char visited[1001][1001] = {0,};
    int group_num[1001][1001] = {0,};
    int dist[1000001] = {0,};
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((board[i][j] - '1') && !visited[i][j]) {
                q.push({i, j});
                visited[i][j] = 1;
                group_num[i][j] = ++count;
                dist[count] = 1;

                while (!q.empty()) {
                    tmp = q.front();
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        if (tmp.first + dy[k] >= 0 && tmp.first + dy[k] < n && tmp.second + dx[k] >= 0 && tmp.second + dx[k] < m) {
                            if ((board[tmp.first + dy[k]][tmp.second + dx[k]] - '1') && !visited[tmp.first + dy[k]][tmp.second + dx[k]]) {
                                q.push({tmp.first + dy[k], tmp.second + dx[k]});
                                visited[tmp.first + dy[k]][tmp.second + dx[k]] = 1;
                                dist[count]++;
                                group_num[tmp.first + dy[k]][tmp.second + dx[k]] = count;
                            }
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] - '0') {
                count = 0;
                v.resize(0);

                for (int k = 0; k < 4; k++)
                    if (i + dy[k] >= 0 && i + dy[k] < n && j + dx[k] >= 0 && j + dx[k] < m) {
                        for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
                            if (*it == group_num[i + dy[k]][j + dx[k]]) {
                                count -= dist[group_num[i + dy[k]][j + dx[k]]];
                                break;
                            }
                        }
                        count += dist[group_num[i + dy[k]][j + dx[k]]];
                        v.push_back(group_num[i + dy[k]][j + dx[k]]);
                    }

                board[i][j] = (count + 1) % 10 + '0';
                cout << board[i][j];
            } else
                cout << "0";
        }
        cout << "\n";
    }
}