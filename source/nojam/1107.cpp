#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n, m, broken = (1 << 10) - 1, a[1000001] = {0,};
    vector<int> usable;
    queue<int> q;
    int input;
    int cur, pivot, min;

    scanf("%d", &n);
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        scanf("%d", &input);
        broken ^= 1 << input;
    }

    for (int i = 0; i < 10; i++) {
        if ((broken & (1 << i))) {
            usable.push_back(i);
        }
    }

    for (vector<int>::iterator it = usable.begin(); it < usable.end(); it++) {
        q.push(*it);
        a[*it] = 2;
    }

    while (!q.empty()) {
        cur = q.front() * 10;
        q.pop();

        for (vector<int>::iterator it = usable.begin(); it < usable.end(); it++) {
            if (cur + *it < 1000000 && (!a[cur + *it] || a[cur + *it] > a[cur / 10] + 1)) {
                q.push(cur + *it);
                a[cur + *it] = a[cur / 10] + 1;
            }
        }
    }

    a[100] = 1;

    cur = 0, min = 1000000, pivot = 1000000;
    while (cur < pivot + 6) {
        if (n - cur >= 0 && a[n - cur]) {
            if (a[n - cur] + cur < min) {
                min = a[n - cur] + cur;
                if (pivot == -1) {
                    pivot = cur;
                }
            }
        }
        if (n + cur < 1000000 && a[n + cur]) {
            if (a[n + cur] + cur < min) {
                min = a[n + cur] + cur;
                if (pivot == -1) {
                    pivot = cur;
                }
            }
        }
        cur++;
    }

    printf("%d\n", min - 1);
}