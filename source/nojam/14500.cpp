#include <stdio.h>

int main() {
    int n, m;
    int a[504][504];
    int max = 0, tmp;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // I 2
    // Z 2
    // S 2
    // L 4
    // J 4
    // O 1
    // T 4

    // ㅇ
    // ㅁ
    // ㅁ
    // ㅁ
    for (int i = 0; i < n - 3; i++) {
        for (int j = 0; j < m; j++) {
            tmp = a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i + 3][j];
            if (tmp > max) max = tmp;
        }
    }

    // ㅇㅁㅁㅁ
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 3; j++) {
            tmp = a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i][j + 3];
            if (tmp > max) max = tmp;
        }
    }

    // ㅇㅁ
    // 　ㅁㅁ
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 2; j++) {
            tmp = a[i][j] + a[i][j + 1] + a[i + 1][j + 1] + a[i + 1][j + 2];
            if (tmp > max) max = tmp;
        }
    }

    // 　ㅇ
    // ㅁㅁ
    // ㅁ
    for (int i = 0; i < n - 2; i++) {
        for (int j = 1; j < m; j++) {
            tmp = a[i][j] + a[i + 1][j] + a[i + 1][j - 1] + a[i + 2][j - 1];
            if (tmp > max) max = tmp;
        }
    }

    // ㅇ
    // ㅁㅁ
    // 　ㅁ
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 1; j++) {
            tmp = a[i][j] + a[i + 1][j] + a[i + 1][j + 1] + a[i + 2][j + 1];
            if (tmp > max) max = tmp;
        }
    }

    // 　ㅁㅁ
    // ㅇㅁ
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m - 2; j++) {
            tmp = a[i][j] + a[i][j + 1] + a[i - 1][j + 1] + a[i - 1][j + 2];
            if (tmp > max) max = tmp;
        }
    }

    // ㅇ
    // ㅁ
    // ㅁㅁ
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 1; j++) {
            tmp = a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i + 2][j + 1];
            if (tmp > max) max = tmp;
        }
    }

    // ㅇㅁㅁ
    // ㅁ
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 2; j++) {
            tmp = a[i][j] + a[i + 1][j] + a[i][j + 1] + a[i][j + 2];
            if (tmp > max) max = tmp;
        }
    }

    // ㅇㅁ
    // 　ㅁ
    // 　ㅁ
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 1; j++) {
            tmp = a[i][j] + a[i][j + 1] + a[i + 1][j + 1] + a[i + 2][j + 1];
            if (tmp > max) max = tmp;
        }
    }

    // 　　ㅁ
    // ㅇㅁㅁ
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m - 2; j++) {
            tmp = a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i - 1][j + 2];
            if (tmp > max) max = tmp;
        }
    }

    // ㅇ
    // ㅁㅁㅁ
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 2; j++) {
            tmp = a[i][j] + a[i + 1][j] + a[i + 1][j + 1] + a[i + 1][j + 2];
            if (tmp > max) max = tmp;
        }
    }

    // ㅇㅁ
    // ㅁ
    // ㅁ
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 1; j++) {
            tmp = a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i][j + 1];
            if (tmp > max) max = tmp;
        }
    }

    // ㅇㅁㅁ
    // 　　ㅁ
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 2; j++) {
            tmp = a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i + 1][j + 2];
            if (tmp > max) max = tmp;
        }
    }

    // 　ㅇ
    // 　ㅁ
    // ㅁㅁ
    for (int i = 0; i < n - 2; i++) {
        for (int j = 1; j < m; j++) {
            tmp = a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i + 2][j - 1];
            if (tmp > max) max = tmp;
        }
    }

    // ㅇㅁ
    // ㅁㅁ
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            tmp = a[i][j] + a[i + 1][j] + a[i + 1][j + 1] + a[i][j + 1];
            if (tmp > max) max = tmp;
        }
    }

    // ㅇ
    // ㅁㅁ
    // ㅁ
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 1; j++) {
            tmp = a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i + 1][j + 1];
            if (tmp > max) max = tmp;
        }
    }

    // ㅇㅁㅁ
    // 　ㅁ
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 2; j++) {
            tmp = a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i + 1][j + 1];
            if (tmp > max) max = tmp;
        }
    }

    // 　ㅁ
    // ㅇㅁ
    // 　ㅁ
    for (int i = 0; i < n - 2; i++) {
        for (int j = 1; j < m; j++) {
            tmp = a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i + 1][j - 1];
            if (tmp > max) max = tmp;
        }
    }

    // 　ㅁ
    // ㅇㅁㅁ
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m - 2; j++) {
            tmp = a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i - 1][j + 1];
            if (tmp > max) max = tmp;
        }
    }

    printf("%d", max);
}