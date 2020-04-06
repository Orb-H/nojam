#include <stdio.h>

int n;
int h[100001];

long long g(int s, int e)
{
    int m = (s + e) / 2;
    int d = m - 1;
    int u = m;
    long long v = h[d] < h[u] ? h[d] : h[u];
    long long r = 2 * v;
    long long t;
    while (d > s && u < e - 1)
    {
        if (h[d - 1] < h[u + 1])
        {
            u++;
            v = v < h[u] ? v : h[u];
        }
        else if (h[d - 1] > h[u + 1])
        {
            d--;
            v = v < h[d] ? v : h[d];
        }
        else
        {
            u++;
            d--;
            v = v < h[d] ? v : h[d];
        }
        t = (u - d + 1) * v;
        r = r > t ? r : t;
    }
    while (d > s)
    {
        d--;
        v = v < h[d] ? v : h[d];
        t = (u - d + 1) * v;
        r = r > t ? r : t;
    }
    while (u < e - 1)
    {
        u++;
        v = v < h[u] ? v : h[u];
        t = (u - d + 1) * v;
        r = r > t ? r : t;
    }
    return r;
}

long long f(int s, int e)
{
    if (e - s <= 1)
        return h[s];
    long long a = f(s, (s + e) / 2);
    long long b = f((s + e) / 2, e);
    if (b > a)
        a = b;
    b = g(s, e);
    if (b > a)
        a = b;
    return a;
}

int main()
{
    while (true)
    {
        scanf("%d", &n);
        if (n == 0)
            break;
        for (int i = 0; i < n; i++)
            scanf("%d", &h[i]);
        printf("%lld\n", f(0, n));
    }
}