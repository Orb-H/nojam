#include <stdio.h>
#include <stack>

int main() {
    int n, m;
    char visited[1001] = {0,};
    char a[1001][1001] = {0,};
    int count = 0;
    int x, y;
    int cur;
    int flag;
    std::stack<int> s;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        a[x][y] = 1;
        a[y][x] = 1;
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;

        s.push(i);
        count++;

        while (!s.empty()) {
            cur = s.top();

            flag = 0;
            for (int i = 1; i <= n; i++) {
                if (!visited[i] && a[cur][i]) {
                    s.push(i);
                    visited[i] = 1;
                    flag = 1;
                    break;
                }
            }
            if (!flag) s.pop();
        }
    }

    printf("%d\n", count);
}