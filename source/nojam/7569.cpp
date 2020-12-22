#include <stdio.h>
#include <queue>

typedef struct {
    int a;
    int b;
    int c;
} pos;

int main() {
    int m, n, h;
    int a[100][100][100];
    std::queue<pos> q;
    pos p;
    int max;

    scanf("%d %d %d", &m, &n, &h);

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                scanf("%d", &a[i][j][k]);
                if (a[i][j][k] == 1) {
                    q.push({i, j, k});
                }
            }
        }
    }

    while (!q.empty()) {
        p = q.front();
        q.pop();

        if (p.a > 0 && (!a[p.a - 1][p.b][p.c] || (a[p.a - 1][p.b][p.c] - 1 > a[p.a][p.b][p.c]))) {
            q.push({p.a - 1, p.b, p.c});
            a[p.a - 1][p.b][p.c] = a[p.a][p.b][p.c] + 1;
        }
        if (p.a < h - 1 && (!a[p.a + 1][p.b][p.c] || (a[p.a + 1][p.b][p.c] - 1 > a[p.a][p.b][p.c]))) {
            q.push({p.a + 1, p.b, p.c});
            a[p.a + 1][p.b][p.c] = a[p.a][p.b][p.c] + 1;
        }
        if (p.b > 0 && (!a[p.a][p.b - 1][p.c] || (a[p.a][p.b - 1][p.c] - 1 > a[p.a][p.b][p.c]))) {
            q.push({p.a, p.b - 1, p.c});
            a[p.a][p.b - 1][p.c] = a[p.a][p.b][p.c] + 1;
        }
        if (p.b < n - 1 && (!a[p.a][p.b + 1][p.c] || (a[p.a][p.b + 1][p.c] - 1 > a[p.a][p.b][p.c]))) {
            q.push({p.a, p.b + 1, p.c});
            a[p.a][p.b + 1][p.c] = a[p.a][p.b][p.c] + 1;
        }
        if (p.c > 0 && (!a[p.a][p.b][p.c - 1] || (a[p.a][p.b][p.c - 1] - 1 > a[p.a][p.b][p.c]))) {
            q.push({p.a, p.b, p.c - 1});
            a[p.a][p.b][p.c - 1] = a[p.a][p.b][p.c] + 1;
        }
        if (p.c < m - 1 && (!a[p.a][p.b][p.c + 1] || (a[p.a][p.b][p.c + 1] - 1 > a[p.a][p.b][p.c]))) {
            q.push({p.a, p.b, p.c + 1});
            a[p.a][p.b][p.c + 1] = a[p.a][p.b][p.c] + 1;
        }
    }

    max = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (!a[i][j][k]) max = 2147483647;
                else if (a[i][j][k] > max) max = a[i][j][k];
            }
        }
    }

    if (max == 2147483647) printf("-1\n");
    else printf("%d\n", max - 1);
}