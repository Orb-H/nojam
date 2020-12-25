#include <stdio.h>
#include <queue>

using namespace std;

int main() {
    int n, m;
    int a[101][101];
    int v[101];
    int visited[101];
    int x, y, min, min_pos;
    int cur;
    queue<int> q;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        a[x][y] = 1;
        a[y][x] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) visited[j] = 0;

        q.push(i);
        visited[i] = 1;
        v[i] = 0;

        while (!q.empty()) {
            cur = q.front();
            q.pop();

            for (int j = 1; j <= n; j++) {
                if (!visited[j] && a[cur][j]) {
                    q.push(j);
                    visited[j] = visited[cur] + 1;
                    v[i] += visited[j] - 1;
                }
            }
        }
    }

    min = 2147483647;
    min_pos = 0;

    for (int i = 1; i <= n; i++) {
        if (min > v[i]) {
            min = v[i];
            min_pos = i;
        }
    }

    printf("%d\n", min_pos);
}