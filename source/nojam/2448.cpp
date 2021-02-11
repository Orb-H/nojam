#include <iostream>
#include <cstring>

using namespace std;

char res[3100][6200];

void draw(int n, int r, int c) {
    if (n == 3) {
        res[r][c + 2] = res[r + 1][c + 1] = res[r + 1][c + 3] = res[r + 2][c] = res[r + 2][c + 1] = res[r + 2][c + 2] = res[r + 2][c + 3] = res[r + 2][c + 4] = '*';
    } else {
        draw(n / 2, r, c + n / 2);
        draw(n / 2, r + n / 2, c);
        draw(n / 2, r + n / 2, c + n);
    }
}

int main() {
    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2 * n; j++)
            res[i][j] = ' ';
    
    draw(n, 0, 0);
    
    for (int i = 0; i < n; i++) {
        cout << res[i] << "\n";
    }
}