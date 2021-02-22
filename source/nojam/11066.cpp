#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t, k, min;
    vector<int> cost(500);
    vector<vector<int>> dp_size(500, vector<int>(500, 0));
    vector<vector<int>> dp_cost(500, vector<int>(500, 0));

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> k;

        for (int j = 0; j < k; j++) {
            cin >> cost[j];
            dp_size[j][j] = cost[j];
            dp_cost[j][j] = 0;
        }

        for (int j = 1; j < k; j++) {
            for (int l = 0; l < k - j; l++) {
                dp_cost[l][l + j] = 2147483647;
                dp_size[l][l + j] = dp_size[l][l] + dp_size[l + 1][l + j];

                min = 2147483647;

                for (int m = 0; m < j; m++)
                    min = min < dp_cost[l][l + m] + dp_cost[l + m + 1][l + j] ? min : dp_cost[l][l + m] + dp_cost[l + m + 1][l + j];
                dp_cost[l][l + j] = min + dp_size[l][l + j];
            }
        }

        cout << dp_cost[0][k - 1] << "\n";
    }
}