#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int m, n, max, cury, curx;
    int a[1001][1001];
    queue<pair<int, int>> q;
    vector<pair<int, int>> v;

    scanf("%d %d", &m, &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j] == 1) {
                v.push_back(make_pair(i, j));
            }
        }
    }
    
    for (int i = 0; i < v.size(); i++) {
        q.push(v[i]);
    }

    while (!q.empty()) {
        cury = q.front().first;
        curx = q.front().second;
        q.pop();

        if (curx > 0 && (!a[cury][curx - 1] || (a[cury][curx - 1] - 1 > a[cury][curx]))) {
            q.push(make_pair(cury, curx - 1));
            a[cury][curx - 1] = a[cury][curx] + 1;
        }
        if (curx < m - 1 && (!a[cury][curx + 1] || (a[cury][curx + 1] - 1 > a[cury][curx]))) {
            q.push(make_pair(cury, curx + 1));
            a[cury][curx + 1] = a[cury][curx] + 1;
        }
        if (cury > 0 && (!a[cury - 1][curx] || (a[cury - 1][curx] - 1 > a[cury][curx]))) {
            q.push(make_pair(cury - 1, curx));
            a[cury - 1][curx] = a[cury][curx] + 1;
        }
        if (cury < n - 1 && (!a[cury + 1][curx] || (a[cury + 1][curx] - 1 > a[cury][curx]))) {
            q.push(make_pair(cury + 1, curx));
            a[cury + 1][curx] = a[cury][curx] + 1;
        }
    }
    
    max = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] > max) max = a[i][j];
            else if (!a[i][j]) max = 2147483647;
        }
    }

    if (max == 2147483647) printf("-1\n");
    else printf("%d", max - 1);
}