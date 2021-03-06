#include <iostream>
#include <vector>

using namespace std;

int main() {
    int tmp, min;
    vector<int> arr;
    int dp[5][5], new_dp[5][5];

    cin >> tmp;

    while (tmp) {
        arr.push_back(tmp);
        cin >> tmp;
    }

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            dp[i][j] = 1000000000;
    
    dp[0][0] = 0;

    for (vector<int>::iterator it = arr.begin(); it != arr.end(); it++) {
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                new_dp[i][j] = 1000000000;
        
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                tmp = dp[i][j] + (j == *it ? 1 : j == 0 ? 2 : (j + *it) % 2 ? 3 : 4);
                new_dp[i][*it] = tmp < new_dp[i][*it] ? tmp : new_dp[i][*it];
                tmp = dp[i][j] + (i == *it ? 1 : i == 0 ? 2 : (i + *it) % 2 ? 3 : 4);
                new_dp[*it][j] = tmp < new_dp[*it][j] ? tmp : new_dp[*it][j];
            }
        }

        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                dp[i][j] = new_dp[i][j];
    }

    min = 1000000000;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (dp[i][j] >= 0)
                min = dp[i][j] < min ? dp[i][j] : min;

    cout << min;
}