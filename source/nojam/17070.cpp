#include <iostream>

using namespace std;

int main() {
    int n;
    int house[17][17] = {0,};
    int count[17][17][3] = {0,};

    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> house[i][j];

    count[1][2][0] = 1;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 3; j <= n; j++) {
            if (!house[i][j]) {
                count[i][j][0] = count[i][j - 1][0] + count[i][j - 1][1];
                count[i][j][2] = count[i - 1][j][1] + count[i - 1][j][2];
                if (!(house[i - 1][j] + house[i][j - 1]))
                    count[i][j][1] = count[i - 1][j - 1][0] + count[i - 1][j - 1][1] + count[i - 1][j - 1][2]; 
            }
        }
    }

    cout << count[n][n][0] + count[n][n][1] + count[n][n][2];
}