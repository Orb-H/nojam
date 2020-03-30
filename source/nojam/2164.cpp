#include <stdio.h>
#include <queue>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    queue<int> q = queue<int>();
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }

    for (int i = 1; i < n; i++)
    {
        q.pop();
        q.push(q.front());
        q.pop();
    }

    printf("%d", q.front());
}