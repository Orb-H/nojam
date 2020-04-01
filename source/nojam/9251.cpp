#include <stdio.h>
#include <string.h>

int main()
{
    char a[1000], b[1000];
    int c[1001][1001] = {0};
    scanf("%s", a);
    scanf("%s", b);
    int m = strlen(a), n = strlen(b);

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i - 1] == b[j - 1])
                c[i][j] = c[i - 1][j - 1] + 1;
            else
                c[i][j] = c[i - 1][j] > c[i][j - 1] ? c[i - 1][j] : c[i][j - 1];
        }
    }

    printf("%d", c[m][n]);
}