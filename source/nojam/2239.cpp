#include <iostream>

using namespace std;

char map[81] = {0,};

bool find(int loc) {
    if (loc >= 81) return true;
    if (map[loc] - '0') return find(loc + 1);

    int avail = -1;

    int tmp = loc / 9 * 9;
    for (int i = 0; i < 9; i++)
        avail &= ~(1 << (map[tmp + i] - '0'));
    
    tmp = loc % 9;
    for (int i = 0; i < 9; i++)
        avail &= ~(1 << (map[9 * i + tmp] - '0'));
    
    tmp = loc / 27 * 27 + (loc % 9) / 3 * 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            avail &= ~(1 << (map[tmp + 9 * i + j] - '0'));
    
    for (int i = 1; i <= 9; i++) {
        if (avail & (1 << i)) {
            map[loc] = i + '0';
            if (find(loc + 1))
                return true;
            map[loc] = '0';
        }
    }
    return false;
}

int main() {
    for (int i = 0; i < 81; i++)
        cin >> map[i];

    find(0);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            cout << map[9 * i + j];
        cout << "\n";
    }
}