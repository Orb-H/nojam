#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string a, b;
    vector<vector<string>> dp(1001, vector<string>(1001, ""));

    cin >> a >> b;

    for (int i = 1; i <= a.length(); i++) {
        for (int j = 1; j <= b.length(); j++) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + a[i - 1];
            else
                dp[i][j] = dp[i - 1][j].length() > dp[i][j - 1].length() ? dp[i - 1][j] : dp[i][j - 1];
        }
    }

    cout << dp[a.length()][b.length()].length() << "\n" << dp[a.length()][b.length()];
}