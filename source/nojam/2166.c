#include <stdio.h>

#define abs(x) ((x) >= 0 ? (x) : -(x))

int main() {
    int n;
    long long pivot_x, pivot_y, point1_x, point1_y, point2_x, point2_y;
    double area = 0;

    scanf("%d", &n);
    scanf("%lld %lld", &pivot_x, &pivot_y);
    scanf("%lld %lld", &point2_x, &point2_y);

    for (int i = 2; i < n; i++) {
        point1_x = point2_x;
        point1_y = point2_y;
        scanf("%lld %lld", &point2_x, &point2_y);

        area += (point1_x - pivot_x) * (point2_y - pivot_y) - (point2_x - pivot_x) * (point1_y - pivot_y);
    }

    printf("%.1lf", abs(area / 2));
}