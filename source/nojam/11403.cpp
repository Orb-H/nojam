#include <stdio.h>
#include <queue>

using namespace std;

int main() {
    int n;
    int graph[100][100] = {0,};
    int avail[100][100] = {0,};
    int cur;
    queue<int> q;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        q.push(i);

        while (!q.empty()) {
            cur = q.front();
            q.pop();

            for (int j = 0; j < n; j++) {
                if (!avail[i][j] && graph[cur][j]) {
                    avail[i][j] = 1;
                    q.push(j);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            printf("%d ", avail[i][j]);
        }
        printf("%d\n", avail[i][n - 1]);
    }
}