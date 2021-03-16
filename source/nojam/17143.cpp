#include <iostream>
#include <cstring>

using namespace std;

typedef struct {
    int s;
    int d;
    int z;
} shark;

int main() {
    int r, c, m, pos = 0, x, y, count = 0;
    shark s[101][101] = {0,}, s_new[101][101], tmp;

    cin >> r >> c >> m;
    for (int i = 0; i < m; i++) {
        cin >> y >> x >> tmp.s >> tmp.d >> tmp.z;
        if (s[y][x].z < tmp.z)
            s[y][x] = tmp;
    }
    
    for (int i = 1; i <= c; i++) {
        memset(s_new, 0, 101 * 101 * sizeof(shark));

        for (int j = 1; j <= r; j++) {
            if (s[j][i].z) {
                count += s[j][i].z;
                s[j][i].s = s[j][i].d = s[j][i].z = 0;
                break;
            }
        }

        for (int j = 1; j <= 100; j++) {
            for (int k = 1; k <= 100; k++) {
                if (s[j][k].z) {
                    switch (s[j][k].d) {
                        case 1:
                            y = ((2 * r - 2) - (j - 1) + s[j][k].s) % (2 * r - 2);
                            if (y < r - 1)
                                s[j][k].d = 2;
                            y = r - 1 - abs(r - 1 - y) + 1;
                            if (s_new[y][k].z < s[j][k].z)
                                s_new[y][k] = s[j][k];
                            break;
                        case 2:
                            y = ((j - 1) + s[j][k].s) % (2 * r - 2);
                            if (y >= r - 1)
                                s[j][k].d = 1;
                            y = r - 1 - abs(r - 1 - y) + 1;
                            if (s_new[y][k].z < s[j][k].z)
                                s_new[y][k] = s[j][k];
                            break;
                        case 3:
                            x = ((k - 1) + s[j][k].s) % (2 * c - 2);
                            if (x >= c - 1)
                                s[j][k].d = 4;
                            x = c - 1 - abs(c - 1 - x) + 1;
                            if (s_new[j][x].z < s[j][k].z)
                                s_new[j][x] = s[j][k];
                            break;
                        case 4:
                            x = ((2 * c - 2) - (k - 1) + s[j][k].s) % (2 * c - 2);
                            if (x < c - 1)
                                s[j][k].d = 3;
                            x = c - 1 - abs(c - 1 - x) + 1;
                            if (s_new[j][x].z < s[j][k].z)
                                s_new[j][x] = s[j][k];
                            break;
                    }
                }
            }
        }

        for (int j = 1; j <= 100; j++)
            for (int k = 1; k <= 100; k++)
                s[j][k] = s_new[j][k];
    }

    cout << count;
}