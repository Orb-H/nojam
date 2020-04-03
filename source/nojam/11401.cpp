#include <stdio.h>

long long modpower(int a, int b, long long c)
{
    if (b == 1)
        return a % c;
    long long d = modpower(a, b / 2, c);
    return ((d * d) % c * (b % 2 ? a : 1)) % c;
}

int inverse(int a, int p)
{
    return modpower(a, p - 2, p);
}

int main()
{
    int n, k;
    long long r = 1;
    long long s = 1;
    scanf("%d %d", &n, &k);
    if (k >= n / 2)
        k = n - k;
    for (int i = 0; i < k; i++)
    {
        r *= (n - i);
        r %= 1000000007;
    }
    for (int i = k; i > 1; i--)
    {
        s *= i;
        s %= 1000000007;
    }
    r *= inverse(s, 1000000007);
    r %= 1000000007;
    printf("%d\n", r);
}