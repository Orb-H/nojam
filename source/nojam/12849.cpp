#include <iostream>
#include <vector>

using namespace std;

int main() {
    int d;
    unsigned dp[8] = {1,};
    unsigned tmp[8] = {0,};

    cin >> d;

    for (int i = 0; i < d; i++) {
        tmp[0] = (dp[1] + dp[2]) % 1000000007;
        tmp[1] = (dp[0] + dp[2] + dp[3]) % 1000000007;
        tmp[2] = (dp[0] + dp[1] + dp[3] + dp[4]) % 1000000007;
        tmp[3] = (dp[1] + dp[2] + dp[4] + dp[5]) % 1000000007;
        tmp[4] = (dp[2] + dp[3] + dp[5] + dp[6]) % 1000000007;
        tmp[5] = (dp[3] + dp[4] + dp[7]) % 1000000007;
        tmp[6] = (dp[4] + dp[7]) % 1000000007;
        tmp[7] = (dp[5] + dp[6]) % 1000000007;

        for (int j = 0; j < 8; j++)
            dp[j] = tmp[j];
    }

    cout << dp[0];
}