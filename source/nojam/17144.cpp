#include <iostream>

using namespace std;
typedef pair<int, int> pi;

pi operator+(pi a, pi b) { return make_pair(a.first + b.first, a.second + b.second); }
pi operator-(pi a, pi b) { return make_pair(a.first - b.first, a.second - b.second); }

int main() {
    int r, c, t, sum = 0;
    int map[51][51];
    int new_map[51][51];
    pi airpur_upper;
    pi airpur_lower;
    pi tmp, dir;

    cin >> r >> c >> t;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> map[i][j];
            if (map[i][j] == -1 && airpur_upper.first == 0) {
                airpur_upper.first = i;
                airpur_upper.second = j;
            }
        }
    }

    airpur_lower = {airpur_upper.first + 1, airpur_upper.second};

    for (int i = 0; i < t; i++) {
        for (int j = 0; j < r; j++)
            for (int k = 0; k < c; k++)
                new_map[j][k] = 0;
        
        for (int j = 0; j < r; j++) {
            for (int k = 0; k < c; k++) {
                if (map[j][k] > 0) {
                    if (j > 0 && map[j - 1][k] >= 0) {
                        new_map[j - 1][k] += map[j][k] / 5;
                        new_map[j][k] -= map[j][k] / 5;
                    }
                    if (j < r - 1 && map[j + 1][k] >= 0) {
                        new_map[j + 1][k] += map[j][k] / 5;
                        new_map[j][k] -= map[j][k] / 5;
                    }
                    if (k > 0 && map[j][k - 1] >= 0) {
                        new_map[j][k - 1] += map[j][k] / 5;
                        new_map[j][k] -= map[j][k] / 5;
                    }
                    if (k < c - 1 && map[j][k + 1] >= 0) {
                        new_map[j][k + 1] += map[j][k] / 5;
                        new_map[j][k] -= map[j][k] / 5;
                    }
                }
            }
        }

        for (int j = 0; j < r; j++)
            for (int k = 0; k < c; k++)
                map[j][k] += new_map[j][k];
        
        dir = {-1, 0};
        tmp = airpur_upper + dir;

        while (tmp != airpur_upper) {
            if (dir.first + tmp.first < 0) {
                dir = {0, 1};
            } else if (dir.second + tmp.second >= c) {
                dir = {1, 0};
            } else if (dir.first + tmp.first > airpur_upper.first) {
                dir = {0, -1};
            }

            map[tmp.first][tmp.second] = map[tmp.first + dir.first][tmp.second + dir.second];
            tmp = tmp + dir;
        }

        map[tmp.first - dir.first][tmp.second - dir.second] = 0;

        dir = {1, 0};
        tmp = airpur_lower + dir;

        while (tmp != airpur_lower) {
            if (dir.first + tmp.first >= r) {
                dir = {0, 1};
            } else if (dir.second + tmp.second >= c) {
                dir = {-1, 0};
            } else if (dir.first + tmp.first < airpur_lower.first) {
                dir = {0, -1};
            }

            map[tmp.first][tmp.second] = map[tmp.first + dir.first][tmp.second + dir.second];
            tmp = tmp + dir;
        }

        map[tmp.first - dir.first][tmp.second - dir.second] = 0;
    }

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (map[i][j] > 0)
                sum += map[i][j];
    
    cout << sum;
}