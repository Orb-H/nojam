#include <stdio.h>
#include <vector>

#define max(a, b) ((a) > (b) ? (a) : (b))

using namespace std;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> w(n), v(n);
    vector<int> d(k + 1, 0);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &w[i], &v[i]);
    for (int i = 0; i < n; i++)
        for (int j = k; j >= 0; j--)
            if (j >= w[i])
                d[j] = max(d[j], d[j - w[i]] + v[i]);
    printf("%d", d[k]);
}