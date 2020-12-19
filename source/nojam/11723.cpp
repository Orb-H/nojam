#include <stdio.h>

int main() {
    char input[20] = {0,};
    int n;
    int idx;
    int set = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", input);
        if (input[0] == 'a') {
            if (input[1] == 'l') {
                set = ~0;
            } else if (input[1] == 'd') {
                scanf("%d", &idx);
                set |= 1 << idx;
            }
        } else if (input[0] == 'r') {
            scanf("%d", &idx);
            set &= ~(1 << idx);
        } else if (input[0] == 'c') {
            scanf("%d", &idx);
            printf("%d\n", !!(set & (1 << idx)));
        } else if (input[0] == 't') {
            scanf("%d", &idx);
            set ^= 1 << idx;
        } else if (input[0] == 'e') {
            set = 0;
        }
    }
}