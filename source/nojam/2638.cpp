#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m, count, max = 0, left = 0, time = 0;
    int arr[100][100];
    int visited[100][100] = {0,};
    int sides[100][100] = {0,};
    queue<pair<int, int>> q;
    pair<int, int> cur;
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {1, 0, -1, 0};

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            left += arr[i][j];
        }
    }

    while(left) {
        time++;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                sides[i][j] = visited[i][j] = 0;

        q.push({0, 0});
        visited[0][0] = 1;
        
        while (!q.empty()) {
            cur = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                if (cur.first + dy[i] >= 0 && cur.first + dy[i] < n && cur.second + dx[i] >= 0 && cur.second + dx[i] < m) {
                    if (arr[cur.first + dy[i]][cur.second + dx[i]])
                        sides[cur.first + dy[i]][cur.second + dx[i]]++;
                    else if (!visited[cur.first + dy[i]][cur.second + dx[i]]) {
                        visited[cur.first + dy[i]][cur.second + dx[i]] = 1;
                        q.push({cur.first + dy[i], cur.second + dx[i]});
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (sides[i][j] >= 2) {
                    arr[i][j] = 0;
                    left--;
                }
            }
        }
    }

    cout << time;
}