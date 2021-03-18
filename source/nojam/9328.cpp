#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

typedef pair<int, int> pii;

int main() {
    int key, t, h, w, count;
    bool flag;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    char board[101][101], visited[101][101];
    vector<pii> doors[26];
    queue<pii> q;
    pii tmp;
    string keys;

    cin >> t;

    for (int i = 0; i < t; i++) {
        count = 0;
        key = 0;
        memset(visited, 0, 101 * 101 * sizeof(char));
        
        for (int j = 0; j < 26; j++)
            doors[j].clear();

        cin >> h >> w;
        for (int j = 0; j < h; j++) {
            for (int k = 0 ; k < w; k++) {
                cin >> board[j][k];
                if (board[j][k] >= 'A' && board[j][k] <= 'Z')
                    doors[board[j][k] - 'A'].push_back({j, k});
            }
        }

        cin >> keys;
        if (keys[0] != '0')
            for (string::iterator it = keys.begin(); it != keys.end(); it++)
                key |= 1 << (*it - 'a');
        
        for (int j = 0; j < 26; j++)
            if (key & (1 << j))
                for (vector<pii>::iterator it = doors[j].begin(); it != doors[j].end(); it++)
                    board[(*it).first][(*it).second] = '.';
        
        for (int j = 0; j < w; j++) {
            if (board[0][j] == '.' || (board[0][j] >= 'a' && board[0][j] <= 'z') || board[0][j] == '$')  {
                q.push({0, j});
                visited[0][j] = 1;
            }
            if (board[h - 1][j] == '.' || (board[h - 1][j] >= 'a' && board[h - 1][j] <= 'z') || board[h - 1][j] == '$') {
                q.push({h - 1, j});
                visited[h - 1][j] = 1;
            }
        }

        for (int j = 1; j < h - 1; j++) {
            if (board[j][0] == '.' || (board[j][0] >= 'a' && board[j][0] <= 'z') || board[j][0] == '$') {
                q.push({j, 0});
                visited[j][0] = 1;
            }
            if (board[j][w - 1] == '.' || (board[j][w - 1] >= 'a' && board[j][w - 1] <= 'z') || board[j][w - 1] == '$') {
                q.push({j, w - 1});
                visited[j][w - 1] = 1;
            }
        }

        while (!q.empty()) {
            tmp = q.front();
            q.pop();

            if (board[tmp.first][tmp.second] >= 'a' && board[tmp.first][tmp.second] <= 'z') {
                if (!(key & (1 << (board[tmp.first][tmp.second] - 'a')))) {
                    key |= 1 << (board[tmp.first][tmp.second] - 'a');
                    for (vector<pii>::iterator it = doors[board[tmp.first][tmp.second] - 'a'].begin(); it != doors[board[tmp.first][tmp.second] - 'a'].end(); it++) {
                        flag = false;
                        board[(*it).first][(*it).second] = '.';
                        for (int j = 0; j < 4; j++)
                            if (((*it).first + dy[j] >= 0 && (*it).first + dy[j] < h && (*it).second + dx[j] >= 0 && (*it).second + dx[j] < w && visited[(*it).first + dy[j]][(*it).second + dx[j]]) || (*it).first + dy[j] == 0 || (*it).first + dy[j] == h - 1 || (*it).second + dx[j] == 0 || (*it).second + dx[j] == w - 1)
                                flag = true;
                        if (!visited[(*it).first][(*it).second] && flag) {
                            q.push({(*it).first, (*it).second});
                            visited[(*it).first][(*it).second] = 1;
                        }
                    }
                }
            } else if (board[tmp.first][tmp.second] == '$')
                count++;

            for (int j = 0; j < 4; j++) {
                if (tmp.first + dy[j] >= 0 && tmp.first + dy[j] < h && tmp.second + dx[j] >= 0 && tmp.second + dx[j] < w) {
                    if (!visited[tmp.first + dy[j]][tmp.second + dx[j]] && (board[tmp.first + dy[j]][tmp.second + dx[j]] == '.' || (board[tmp.first + dy[j]][tmp.second + dx[j]] >= 'a' && board[tmp.first + dy[j]][tmp.second + dx[j]] <= 'z') || board[tmp.first + dy[j]][tmp.second + dx[j]] == '$')) {
                        q.push({tmp.first + dy[j], tmp.second + dx[j]});
                        visited[tmp.first + dy[j]][tmp.second + dx[j]] = 1;
                    }
                }
            }
        }

        cout << count << "\n";
    }
}