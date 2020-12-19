#include <stdio.h>

#define abs(x) (((x) > 0) ? (x) : -(x))

int heap[100001] = {0,};

void add_num(int num) {
    int loc = ++heap[0], t;
    heap[heap[0]] = num;
    int a, b;

    while (loc > 1) {
        a = abs(heap[loc]);
        b = abs(heap[loc / 2]);
        if (a < b || ((a == b) && (heap[loc] < heap[loc / 2]))) {
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
    int min;
    int a, b;

    heap[1] = heap[heap[0]];
    heap[heap[0]--] = 0;
    while (loc <= heap[0] / 2) {
        a = abs(heap[loc * 2]);
        b = abs(heap[loc * 2 + 1]);
        min = (heap[loc * 2 + 1] != 0) ? (a > b ? loc * 2 + 1 : (((a == b) && (heap[loc * 2] > heap[loc * 2 + 1])) ? loc * 2 + 1 : loc * 2)) : loc * 2;

        a = abs(heap[min]);
        b = abs(heap[loc]);
        if (a < b || ((a == b) && (heap[min] < heap[loc]))) {
            t = heap[min];
            heap[min] = heap[loc];
            heap[loc] = t;
            loc = min;
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