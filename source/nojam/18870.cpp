#include <stdio.h>
#include <algorithm>
#include <map>

int main() {
    int n;
    int a[1000001];
    int b[1000001];
    std::map<int, int> m;
    int j = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }

    std::sort(&b[0], &b[n]);

    m.insert(std::make_pair(b[0], j));
    j++;

    for (int i = 1; i < n; i++) {
        if (b[i] != b[i - 1]) {
            m.insert(std::make_pair(b[i], j++));
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", m[a[i]]);
    }
}