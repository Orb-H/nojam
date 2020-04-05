#include <stdio.h>
#include <stdlib.h>

int *a;

int *power(int n, long long b)
{
    int *r = (int *)malloc(sizeof(int) * n * n);
    if (b == 1)
    {
        for (int i = 0; i < n * n; i++)
            r[i] = a[i] % 1000;
        return r;
    }
    int *h = power(n, b / 2);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            r[n * i + j] = 0;
            for (int k = 0; k < n; k++)
                r[n * i + j] += h[n * i + k] * h[n * k + j];
            r[n * i + j] %= 1000;
        }
    if (b % 2)
    {
        for (int i = 0; i < n * n; i++)
            h[i] = r[i];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                r[n * i + j] = 0;
                for (int k = 0; k < n; k++)
                    r[n * i + j] += h[n * i + k] * a[n * k + j];
                r[n * i + j] %= 1000;
            }
    }
    return r;
}

int main()
{
    int n;
    long long b;
    scanf("%d %lld", &n, &b);
    a = (int *)malloc(sizeof(int) * n * n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i * n + j]);
    int *r = power(n, b);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", r[n * i + j]);
        printf("\n");
    }
}