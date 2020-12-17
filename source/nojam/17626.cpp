#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n;
    int sqrt_n;
    scanf("%d", &n);
    sqrt_n = (int)sqrt(n);

    char* res = (char*)calloc(sizeof(char), (n + 1));

    res[0] = 1;
    res[1] = 2;
    res[2] = 3;
    res[3] = 4;

    for (int i = 2; i <= sqrt_n; i++) {
        for (int j = 0; j <= n - i * i; j++) {
            if (res[j] > 0 && res[j] < 5) {
                if (j + i * i <= n && (!res[j + i * i] || res[j + i * i] > res[j])) {
                    res[j + i * i] = res[j] + 1;
                }
            }
        }
    }

    printf("%d\n", res[n] - 1);
}