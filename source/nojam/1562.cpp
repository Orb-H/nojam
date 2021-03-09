#include <iostream>

#define CUT 1000000000;

using namespace std;

int main() {
    int n, sum = 0;
    unsigned dp[10][1 << 10] = {0,}, new_dp[10][1 << 10];

    cin >> n;

    for (int i = 1; i < 10; i++)
        dp[i][1 << i] = 1;
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 10; j++)
            for (int k = 0; k < (1 << 10); k++)
                new_dp[j][k] = 0;
        
        for (int j = 0; j < (1 << 10); j++) {
            new_dp[1][j | 2] += dp[0][j];
            new_dp[1][j | 2] %= CUT;
            new_dp[8][j | 256] += dp[9][j];
            new_dp[8][j | 256] %= CUT;
        }

        for (int j = 1; j < 9; j++) {
            for (int k = 0; k < (1 << 10); k++) {
                new_dp[j - 1][k | (1 << (j - 1))] += dp[j][k];
                new_dp[j - 1][k | (1 << (j - 1))] %= CUT;
                new_dp[j + 1][k | (1 << (j + 1))] += dp[j][k];
                new_dp[j + 1][k | (1 << (j + 1))] %= CUT;
            }
        }

        for (int j = 0; j < 10; j++)
            for (int k = 0; k < (1 << 10); k++)
                dp[j][k] = new_dp[j][k];
    }

    for (int i = 0; i < 10; i++) {
        sum += dp[i][1023];
        sum %= CUT;
    }

    cout << sum;
}