#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, min, tmp;
    vector<int> left(500);
    vector<int> right(500);
    vector<vector<int>> dp_cost(500, vector<int>(500, 0));

    cin >> n;

    for (int j = 0; j < n; j++)
        cin >> left[j] >> right[j];

    for (int j = 1; j < n; j++) {
        for (int k = 0; k < n - j; k++) {
            dp_cost[k][k + j] = 2147483647;

            for (int l = 0; l < j; l++) {
                tmp = dp_cost[k][k + l] + dp_cost[k + l + 1][k + j] + left[k] * right[k + j] * right[k + l];
                dp_cost[k][k + j] = tmp < dp_cost[k][k + j] ? tmp : dp_cost[k][k + j];
            }
        }
    }

    cout << dp_cost[0][n - 1];
}