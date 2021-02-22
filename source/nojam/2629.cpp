#include <iostream>

using namespace std;

int main() {
    int n, m;
    int weights[30];
    int marbles[7];
    int dp[70001] = {0, };

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> weights[i];

    cin >> m;

    for (int i = 0; i < m; i++)
        cin >> marbles[i];
    
    dp[15000] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 70001; j++) {
            if (dp[j] && dp[j] < i + 2) {
                if (j - weights[i] >= 0 && !dp[j - weights[i]])
                    dp[j - weights[i]] = i + 2;
                if (j + weights[i] <= 70000 && !dp[j + weights[i]])
                    dp[j + weights[i]] = i + 2;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        if (dp[marbles[i] + 15000])
            cout << "Y ";
        else
            cout << "N ";
    }
}