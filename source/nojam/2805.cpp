#include <stdio.h>

int main()
{
    int n;
    long long m;
    int a[1000001];
    int s = 0, e = 0, c;
    long long v;
    scanf("%d %lld", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        e = e < a[i] ? a[i] : e;
    }
    e++;
    while (s < e - 1)
    {
        c = (s + e) / 2;
        v = 0;
        for (int i = 0; i < n; i++)
            v += a[i] > c ? a[i] - c : 0;
        if (v < m)
            e = c;
        else
            s = c;
    }
    printf("%d\n", s);
}