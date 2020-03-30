#include <stdio.h>

int n;
int c = 0;
int a[15] = {0};

void find(int d)
{
    if (d >= n)
    {
        c++;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        int p = 1;
        //U
        for (int j = d; j >= 0; j--)
        {
            if (a[j] == i)
            {
                p = 0;
                break;
            }
        }
        //LU
        if (p)
        {
            for (int j = d - 1; j >= 0; j--)
            {
                if (a[j] == i - (d - j))
                {
                    p = 0;
                    break;
                }
            }
        }
        //RU
        if (p)
        {
            for (int j = d - 1; j >= 0; j--)
            {
                if (a[j] == i + (d - j))
                {
                    p = 0;
                    break;
                }
            }
        }
        if (p)
        {
            a[d] = i;
            find(d + 1);
        }
        a[d] = 0;
    }
}

int main()
{
    scanf("%d", &n);
    find(0);
    printf("%d", c);
}