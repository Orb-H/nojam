#include <stdio.h>
#include <queue>

using namespace std;

typedef struct {
    int y;
    int x;
} pos;

int main() {
    int n, m;
    char input[101];
    int a[101][101];
    queue<pos> q;
    pos cur;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%s", input);

        for (int j = 0; j < m; j++) {
            a[i][j] = input[j] - '0';
        }
    }

    a[0][0] = 2;
    q.push({0, 0});

    while (!q.empty()) {
        cur = q.front();
        if (cur.y == n - 1 && cur.x == m - 1) break;
        q.pop();

        if (cur.y > 0 && (a[cur.y - 1][cur.x] == 1 || a[cur.y - 1][cur.x] - 1 > a[cur.y][cur.x])) {
            a[cur.y - 1][cur.x] = a[cur.y][cur.x] + 1;
            q.push({cur.y - 1, cur.x});
        }
        if (cur.y < n - 1 && (a[cur.y + 1][cur.x] == 1 || a[cur.y + 1][cur.x] - 1 > a[cur.y][cur.x])) {
            a[cur.y + 1][cur.x] = a[cur.y][cur.x] + 1;
            q.push({cur.y + 1, cur.x});
        }
        if (cur.x > 0 && (a[cur.y][cur.x - 1] == 1 || a[cur.y][cur.x - 1] - 1 > a[cur.y][cur.x])) {
            a[cur.y][cur.x - 1] = a[cur.y][cur.x] + 1;
            q.push({cur.y, cur.x - 1});
        }
        if (cur.x < m - 1 && (a[cur.y][cur.x + 1] == 1 || a[cur.y][cur.x + 1] - 1 > a[cur.y][cur.x])) {
            a[cur.y][cur.x + 1] = a[cur.y][cur.x] + 1;
            q.push({cur.y, cur.x + 1});
        }
    }

    printf("%d\n", a[n - 1][m - 1] - 1);
}