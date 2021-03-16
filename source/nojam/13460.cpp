#include <iostream>
#include <queue>
#include <set>

using namespace std;

typedef pair<int, int> pii;
typedef struct {
    pii red, blue;
    int count;
} node;

int main() {
    int flag; // 1 << 0: 빨강 빠짐 1 << 1 : 파랑 빠짐
    bool printed = false;
    int n, m;
    char board[10][10];
    pii red, blue;
    queue<node> q;
    set<pair<pii, pii>> s;
    node tmp;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'R') {
                red = {i, j};
                board[i][j] = '.';
            } else if (board[i][j] == 'B') {
                blue = {i, j};
                board[i][j] = '.';
            }
        }
    }

    q.push({red, blue, 0});
    s.insert({red, blue});

    while (!q.empty()) {
        tmp = q.front();
        q.pop();
        if (tmp.count >= 10) continue;

        // U
        flag = 0;
        red = tmp.red;
        blue = tmp.blue;
        while (board[blue.first][blue.second] == '.' && red != blue)
            blue.first--;
        if (board[blue.first][blue.second] == 'O')
            flag |= 2;
        else
            blue.first++;
        if (!flag) {
            while (board[red.first][red.second] == '.' && red != blue)
                red.first--;
            if (board[red.first][red.second] == 'O')
                flag |= 1;
            else
                red.first++;
            while (board[blue.first][blue.second] == '.' && red != blue)
                blue.first--;
            if (board[blue.first][blue.second] == 'O')
                flag |= 2;
            else
                blue.first++;
        }
        if (flag == 0) {
            if (s.find({red, blue}) == s.end()) {
                q.push({red, blue, tmp.count + 1});
                s.insert({red, blue});
            }
        } else if (flag == 1) {
            cout << tmp.count + 1;
            printed = true;
            break;
        }
        // D
        flag = 0;
        red = tmp.red;
        blue = tmp.blue;
        while (board[blue.first][blue.second] == '.' && red != blue)
            blue.first++;
        if (board[blue.first][blue.second] == 'O')
            flag |= 2;
        else
            blue.first--;
        if (!flag) {
            while (board[red.first][red.second] == '.' && red != blue)
                red.first++;
            if (board[red.first][red.second] == 'O')
                flag |= 1;
            else
                red.first--;
            while (board[blue.first][blue.second] == '.' && red != blue)
                blue.first++;
            if (board[blue.first][blue.second] == 'O')
                flag |= 2;
            else
                blue.first--;
        }
        if (flag == 0) {
            if (s.find({red, blue}) == s.end()) {
                q.push({red, blue, tmp.count + 1});
                s.insert({red, blue});
            }
        } else if (flag == 1) {
            cout << tmp.count + 1;
            printed = true;
            break;
        }
        // L
        flag = 0;
        red = tmp.red;
        blue = tmp.blue;
        while (board[blue.first][blue.second] == '.' && red != blue)
            blue.second--;
        if (board[blue.first][blue.second] == 'O')
            flag |= 2;
        else
            blue.second++;
        if (!flag) {
            while (board[red.first][red.second] == '.' && red != blue)
                red.second--;
            if (board[red.first][red.second] == 'O')
                flag |= 1;
            else
                red.second++;
            while (board[blue.first][blue.second] == '.' && red != blue)
                blue.second--;
            if (board[blue.first][blue.second] == 'O')
                flag |= 2;
            else
                blue.second++;
        }
        if (flag == 0) {
            if (s.find({red, blue}) == s.end()) {
                q.push({red, blue, tmp.count + 1});
                s.insert({red, blue});
            }
        } else if (flag == 1) {
            cout << tmp.count + 1;
            printed = true;
            break;
        }
        // R
        flag = 0;
        red = tmp.red;
        blue = tmp.blue;
        while (board[blue.first][blue.second] == '.' && red != blue)
            blue.second++;
        if (board[blue.first][blue.second] == 'O')
            flag |= 2;
        else
            blue.second--;
        if (!flag) {
            while (board[red.first][red.second] == '.' && red != blue)
                red.second++;
            if (board[red.first][red.second] == 'O')
                flag |= 1;
            else
                red.second--;
            while (board[blue.first][blue.second] == '.' && red != blue)
                blue.second++;
            if (board[blue.first][blue.second] == 'O')
                flag |= 2;
            else
                blue.second--;
        }
        if (flag == 0) {
            if (s.find({red, blue}) == s.end()) {
                q.push({red, blue, tmp.count + 1});
                s.insert({red, blue});
            }
        } else if (flag == 1) {
            cout << tmp.count + 1;
            printed = true;
            break;
        }
    }

    if (!printed)
        cout << "-1";
}