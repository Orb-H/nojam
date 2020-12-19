#include <stdio.h>

int heap[100001] = {0,};

void add_num(int num) {
    int loc = ++heap[0], t;
    heap[heap[0]] = num;

    while (loc > 1) {
        if (heap[loc] > heap[loc / 2]) {
            t = heap[loc];
            heap[loc] = heap[loc / 2];
            heap[loc / 2] = t;
        } else {
            break;
        }

        loc /= 2;
    }
}

int del_num() {
    int loc = 1, res = heap[1], t;
    int max;

    heap[1] = heap[heap[0]];
    heap[heap[0]--] = 0;
    while (loc <= heap[0] / 2) {
        max = heap[loc * 2 + 1] > 0 ? (heap[loc * 2] < heap[loc * 2 + 1] ? loc * 2 + 1 : loc * 2) : loc * 2;

        if (heap[max] > heap[loc]) {
            t = heap[max];
            heap[max] = heap[loc];
            heap[loc] = t;
            loc = max;
        } else {
            break;
        }
    }

    heap[0] = heap[0] < 0 ? 0 : heap[0];
    return res;
}

int main() {
    int n;
    int q;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &q);

        if (!q) {
            printf("%d\n", del_num());
        } else {
            add_num(q);
        }
    }
}