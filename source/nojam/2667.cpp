#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
    int y;
    int x;
} pos;

int main() {
    int n;
    int a[26][26];
    char input[26];
    queue<pos> q;
    vector<int> v;
    pos cur;
    int count;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", input);

        for (int j = 0; j < n; j++) {
            a[i][j] = input[j] - '0';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j]) {
                a[i][j] = 0;
                q.push({i, j});
                count = 0;

                while (!q.empty()) {
                    cur = q.front();
                    q.pop();
                    count++;

                    if (cur.y > 0 && a[cur.y - 1][cur.x]) {
                        q.push({cur.y - 1, cur.x});
                        a[cur.y - 1][cur.x] = 0;
                    }
                    if (cur.y < n - 1 && a[cur.y + 1][cur.x]) {
                        q.push({cur.y + 1, cur.x});
                        a[cur.y + 1][cur.x] = 0;
                    }
                    if (cur.x > 0 && a[cur.y][cur.x - 1]) {
                        q.push({cur.y, cur.x - 1});
                        a[cur.y][cur.x - 1] = 0;
                    }
                    if (cur.x < n - 1 && a[cur.y][cur.x + 1]) {
                        q.push({cur.y, cur.x + 1});
                        a[cur.y][cur.x + 1] = 0;
                    }
                }

                v.push_back(count);
            }
        }
    }

    sort(v.begin(), v.end());

    printf("%ld\n", v.size());
    for (vector<int>::iterator it = v.begin(); it < v.end(); it++) {
        printf("%d\n", *it);
    }
}