#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
    int y;
    int x;
} pos;

bool compare(pos a, pos b) {
    return a.y != b.y ? a.y < b.y : a.x < b.x;
}

int main() {
    int n, flag, time;
    int map[21][21];
    int dist[21][21] = {0,};
    pos shark, cur;
    int size = 2, eat = 0;
    queue<pos> q;
    vector<pos> v;
    time = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 9) { 
                shark = {i, j};
                map[i][j] = 0;
            }
        }
    }

    while (1) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dist[i][j] = 0;
        flag = 0;
        while (!q.empty())
            q.pop();
    
        q.push(shark);
        dist[shark.y][shark.x] = 1;

        while (!q.empty()) {
            while (!q.empty()) {
                cur = q.front();
                q.pop();

                if (map[cur.y][cur.x] != 0 && map[cur.y][cur.x] < size) {
                    shark = {cur.y, cur.x};
                    if (++eat >= size) {
                        eat = 0;
                        size++;
                    }
                    flag = 1;
                    map[cur.y][cur.x] = 0;
                    time += dist[cur.y][cur.x] - 1;
                    break;
                }

                if (cur.y > 0 && !dist[cur.y - 1][cur.x] && map[cur.y - 1][cur.x] <= size) {
                    dist[cur.y - 1][cur.x] = dist[cur.y][cur.x] + 1;
                    v.push_back({cur.y - 1, cur.x});
                }
                if (cur.x > 0 && !dist[cur.y][cur.x - 1] && map[cur.y][cur.x - 1] <= size) {
                    dist[cur.y][cur.x - 1] = dist[cur.y][cur.x] + 1;
                    v.push_back({cur.y, cur.x - 1});
                }
                if (cur.x < n - 1 && !dist[cur.y][cur.x + 1] && map[cur.y][cur.x + 1] <= size) {
                    dist[cur.y][cur.x + 1] = dist[cur.y][cur.x] + 1;
                    v.push_back({cur.y, cur.x + 1});
                }
                if (cur.y < n - 1 && !dist[cur.y + 1][cur.x] && map[cur.y + 1][cur.x] <= size) {
                    dist[cur.y + 1][cur.x] = dist[cur.y][cur.x] + 1;
                    v.push_back({cur.y + 1, cur.x});
                }
            }

            sort(v.begin(), v.end(), compare);

            for (vector<pos>::iterator it = v.begin(); it < v.end(); it++) {
                q.push(*it);
            }

            while (!v.empty())
                v.pop_back();

            if (flag)
                break;
        }

        if (!flag)
            break;
    }

    printf("%d\n", time);
}