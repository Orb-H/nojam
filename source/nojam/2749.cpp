#include <stdio.h>
#include <stdlib.h>

long long *a;

long long *power(long long n)
{
    long long *r = (long long *)malloc(sizeof(long long) * 4);
    if (n == 1)
    {
        for (int i = 0; i < 4; i++)
            r[i] = a[i];
        return r;
    }
    long long *h = power(n / 2);
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            r[2 * i + j] = (h[2 * i] * h[j] + h[2 * i + 1] * h[2 + j]) % 1000000;
    if (n % 2)
    {
        for (int i = 0; i < 4; i++)
            h[i] = r[i];
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                r[2 * i + j] = (h[2 * i] * a[j] + h[2 * i + 1] * a[2 + j]) % 1000000;
    }
    return r;
}

int main()
{
    long long n;
    scanf("%lld", &n);
    a = (long long *)malloc(sizeof(long long) * 4);
    a[0] = a[1] = a[2] = 1;
    a[3] = 0;
    long long *r = power(n);
    printf("%d", r[1]);
}