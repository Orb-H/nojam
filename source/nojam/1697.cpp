#include <stdio.h>
#include <queue>

int main() {
    int n, k;
    int a[100001] = {0,};
    std::queue<int> q;
    int cur;

    scanf("%d %d", &n, &k);

    a[n] = 1;

    q.push(n);

    while (!q.empty()) {
        cur = q.front();
        q.pop();

        if (cur == k) break;

        if (cur > 0 && (!a[cur - 1] || (a[cur - 1] && (a[cur - 1] > a[cur] + 1)))) {
            a[cur - 1] = a[cur] + 1;
            q.push(cur - 1);
        }
        if (cur < 100000 && (!a[cur + 1] || (a[cur + 1] && (a[cur + 1] > a[cur] + 1)))) {
            a[cur + 1] = a[cur] + 1;
            q.push(cur + 1);
        }
        if (cur <= 50000 && (!a[cur * 2] || (a[cur * 2] && (a[cur * 2] > a[cur] * 2)))) {
            a[cur * 2] = a[cur] + 1;
            q.push(cur * 2);
        }
    }

    printf("%d\n", a[k] - 1);
}