#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    int t;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &t);
        a[i] = t;
    }
    scanf("%d", &m);
    vector<int> b(m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &t);
        b[i] = t;
    }
    sort(a.begin(), a.end());

    vector<int> c(m);
    for (int i = 0; i < m; i++)
    {
        int fs = -1, fe = -1;
        int s = 0, e = n, x = (s + e) / 2;
        while (1)
        {
            if (a[x] == b[i] && (x == 0 || a[x - 1] < b[i]))
            {
                fs = x;
                break;
            }
            else
            {
                if (e - s == 1)
                    break;
                if (a[x] < b[i])
                    s = x;
                else
                    e = x;
                x = (s + e) / 2;
            }
        }
        if (fs == -1)
            continue;
        s = 0, e = n, x = (s + e) / 2;
        while (1)
        {
            if (a[x] == b[i] && (x == n - 1 || a[x + 1] > b[i]))
            {
                fe = x;
                break;
            }
            else
            {
                if (e - s == 1)
                    break;
                if (a[x] > b[i])
                    e = x;
                else
                    s = x;
                x = (s + e) / 2;
            }
        }
        if (fe == -1)
            continue;
        c[i] = fe - fs + 1;
    }
    for (int i = 0; i < m; i++)
        printf("%d ", c[i]);
}