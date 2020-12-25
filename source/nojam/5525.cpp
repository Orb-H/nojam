#include <stdio.h>

int main() {
    int n, m, count = 0;
    char input[1000001];
    int val[1000001] = {0,};

    scanf("%d", &n);
    scanf("%d", &m);
    scanf("%s", input);

    val[0] = input[0] == 'I';
    val[1] = (input[0] == 'I' && input[1] == 'O') || input[1] == 'I';

    for (int i = 2; i < m; i++) {
        if (input[i] == 'O') val[i] = -val[i - 1] * (input[i - 1] == 'I');
        if (input[i] == 'I') val[i] = -val[i - 1] * (input[i - 1] == 'O') + 1;
    }

    for (int i = 0; i < m; i++) {
        if (val[i] > 2 * n) count++;
    }

    printf("%d", count);
}