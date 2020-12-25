#include <stdio.h>
#include <queue>

#define abs(x) ((x) > 0 ? (x) : -(x))

using namespace std;

typedef struct {
    int y;
    int x;
} pos;

int main() {
    int t, n, visited[101];
    queue<pos> q;
    vector<pos> v;
    pos tmp;
    pos end;

    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        scanf("%d", &n);

        while (!q.empty()) q.pop();
        while (!v.empty()) v.pop_back();

        for (int j = 0; j < n + 2; j++) {
            scanf("%d %d", &tmp.x, &tmp.y);
            v.push_back(tmp);
            visited[j] = 0;
        }

        end = v[n + 1];

        q.push(v[0]);
        visited[0] = 1;

        while (!q.empty()) {
            tmp = q.front();
            q.pop();

            if (tmp.x == end.x && tmp.y == end.y) break;

            for (int j = 0; j < n + 2; j++) {
                if (!visited[j] && (abs(tmp.x - v[j].x) + abs(tmp.y - v[j].y)) <= 1000) {
                    q.push(v[j]);
                    visited[j] = 1;
                }
            }
        }

        if (visited[n + 1]) printf("happy\n");
        else printf("sad\n");
    }
}