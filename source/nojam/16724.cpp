#include <iostream>
#include <stack>

using namespace std;

typedef pair<int, int> pii;

int main() {
    int n, m, count = 0;
    char visited[1000][1000], checked[1000][1000], board[1000][1000];
    stack<pii> s;
    pii tmp;
    bool flag = true;
    
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                checked[i][j] = 1;
                s.push({i, j});
                flag = true;
                while (flag) {
                    tmp = s.top();
                    switch (board[tmp.first][tmp.second]) {
                        case 'U':
                            if (visited[tmp.first - 1][tmp.second]) flag = false;
                            else if (checked[tmp.first - 1][tmp.second]) {
                                count++;
                                flag = false;
                            } else {
                                checked[tmp.first - 1][tmp.second] = 1;
                                s.push({tmp.first - 1, tmp.second});
                            }
                            break;
                        case 'D':
                            if (visited[tmp.first + 1][tmp.second]) flag = false;
                            else if (checked[tmp.first + 1][tmp.second]) {
                                count++;
                                flag = false;
                            } else {
                                checked[tmp.first + 1][tmp.second] = 1;
                                s.push({tmp.first + 1, tmp.second});
                            }
                            break;
                        case 'L':
                            if (visited[tmp.first][tmp.second - 1]) flag = false;
                            else if (checked[tmp.first][tmp.second - 1]) {
                                count++;
                                flag = false;
                            } else {
                                checked[tmp.first][tmp.second - 1] = 1;
                                s.push({tmp.first, tmp.second - 1});
                            }
                            break;
                        case 'R':
                            if (visited[tmp.first][tmp.second + 1]) flag = false;
                            else if (checked[tmp.first][tmp.second + 1]) {
                                count++;
                                flag = false;
                            } else {
                                checked[tmp.first][tmp.second + 1] = 1;
                                s.push({tmp.first, tmp.second + 1});
                            }
                            break;
                    }
                }

                while (!s.empty()) {
                    tmp = s.top();
                    s.pop();
                    visited[tmp.first][tmp.second] = 1;
                }
            }
        }
    }

    cout << count;
}