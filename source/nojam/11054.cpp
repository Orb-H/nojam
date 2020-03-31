#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    vector<int> x(n, 1);
    vector<int> y(n, 1);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (a[i] > a[j])
                x[i] = x[i] > x[j] + 1 ? x[i] : x[j] + 1;

    for (int i = n - 2; i >= 0; i--)
        for (int j = n - 1; j > i; j--)
            if (a[i] > a[j])
                y[i] = y[i] > y[j] + 1 ? y[i] : y[j] + 1;

    int m = 0;
    for (int i = 0; i < n; i++)
        if (x[i] + y[i] > m)
            m = x[i] + y[i];
    printf("%d", m - 1);
}