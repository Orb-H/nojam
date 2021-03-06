#include <iostream>
#include <vector>
#include <algorithm>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

using namespace std;

int n;
int board[10][10];
vector<vector<pair<int, int>>> avail;
int ne[20] = {0,};

int find(int depth) {
    if (depth >= 2 * n - 1) return 0;

    int res = 0, tmp, x, y;

    res = find(depth + 2);

    for (vector<pair<int, int>>::iterator it = avail[depth].begin(); it < avail[depth].end(); it++) {
        x = (*it).second;
        y = (*it).first;
        if (!ne[n - y + x]) {
            ne[n - y + x] = 1;

            tmp = find(depth + 2) + 1;
            res = max(tmp, res);

            ne[n - y + x] = 0;
        }
    }

    return res;
}

int main() {
    cin >> n;

    avail.resize(2 * n - 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j])
                avail[i + j].push_back({i, j});
        }
    }
    
    cout << find(0) + find(1);
}