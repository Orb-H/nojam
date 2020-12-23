#include <stdio.h>
#include <queue>

using namespace std;

typedef struct {
    int y;
    int x;
} pos;

int main() {
    int n;
    char a[101][101];
    char c, d;
    int count = 0, count2 = 0;
    queue<pos> q;
    pos cur;
    
    scanf("%d", &n);

    for (int i = 0; i < n; i++) scanf("%s", a[i]);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != 'X' && a[i][j] != 'Y') {
                c = a[i][j];
                if (a[i][j] == 'B') a[i][j] = 'Y';
                else a[i][j] = 'X';
                d = a[i][j];
                q.push({i, j});
                count++;

                while (!q.empty()) {
                    cur = q.front();
                    q.pop();

                    if (cur.y > 0 && a[cur.y - 1][cur.x] == c) {
                        a[cur.y - 1][cur.x] = d;
                        q.push({cur.y - 1, cur.x});
                    }
                    if (cur.y < n - 1 && a[cur.y + 1][cur.x] == c) {
                        a[cur.y + 1][cur.x] = d;
                        q.push({cur.y + 1, cur.x});
                    }
                    if (cur.x > 0 && a[cur.y][cur.x - 1] == c) {
                        a[cur.y][cur.x - 1] = d;
                        q.push({cur.y, cur.x - 1});
                    }
                    if (cur.x < n - 1 && a[cur.y][cur.x + 1] == c) {
                        a[cur.y][cur.x + 1] = d;
                        q.push({cur.y, cur.x + 1});
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != 'Z') {
                c = a[i][j];
                a[i][j] = 'Z';
                d = a[i][j];
                q.push({i, j});
                count2++;

                while (!q.empty()) {
                    cur = q.front();
                    q.pop();

                    if (cur.y > 0 && a[cur.y - 1][cur.x] == c) {
                        a[cur.y - 1][cur.x] = d;
                        q.push({cur.y - 1, cur.x});
                    }
                    if (cur.y < n - 1 && a[cur.y + 1][cur.x] == c) {
                        a[cur.y + 1][cur.x] = d;
                        q.push({cur.y + 1, cur.x});
                    }
                    if (cur.x > 0 && a[cur.y][cur.x - 1] == c) {
                        a[cur.y][cur.x - 1] = d;
                        q.push({cur.y, cur.x - 1});
                    }
                    if (cur.x < n - 1 && a[cur.y][cur.x + 1] == c) {
                        a[cur.y][cur.x + 1] = d;
                        q.push({cur.y, cur.x + 1});
                    }
                }
            }
        }
    }

    printf("%d %d", count, count2);
}