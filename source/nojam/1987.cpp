#include <iostream>
#include <stack>
#include <tuple>

using namespace std;

typedef tuple<int, int, int, int> ti;

int main() {
    int r, c, max = 1;
    char board[20][20];
    stack<ti> s;
    ti tmp;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    cin >> r >> c;

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> board[i][j];
    
    s.push({0, 0, 1 << (board[0][0] - 'A'), 1});

    while (!s.empty()) {
        tmp = s.top();
        s.pop();

        for (int i = 0; i < 4; i++) {
            if (get<0>(tmp) + dy[i] >= 0 && get<0>(tmp) + dy[i] < r && get<1>(tmp) + dx[i] >= 0 && get<1>(tmp) + dx[i] < c) {
                if (!(get<2>(tmp) & (1 << (board[get<0>(tmp) + dy[i]][get<1>(tmp) + dx[i]] - 'A')))) {
                    max = get<3>(tmp) + 1 > max ? get<3>(tmp) + 1 : max;
                    s.push({get<0>(tmp) + dy[i], get<1>(tmp) + dx[i], get<2>(tmp) | (1 << (board[get<0>(tmp) + dy[i]][get<1>(tmp) + dx[i]] - 'A')), get<3>(tmp) + 1});
                }
            }
        }
    }

    cout << max;
}