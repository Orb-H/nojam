#include <iostream>
#include <vector>
#include <tuple>

#define min(a, b) ((a) < (b) ? (a) : (b))

using namespace std;

typedef tuple<int, int, int> ti;
typedef unsigned int ui;

int main() {
    int n;
    ui dp[3][3] = {0,}, tmp[3][3] = {0,}; // [i][j] : 현재 집을 i로 칠하되 a[0]가 j로 칠해진 경우
    vector<ti> val;

    cin >> n;
    val.resize(n);
    
    for (int i = 0; i < n; i++)
        cin >> get<0>(val[i]) >> get<1>(val[i]) >> get<2>(val[i]);
    
    dp[0][0] = get<0>(val[0]);
    dp[1][1] = get<1>(val[0]);
    dp[2][2] = get<2>(val[0]);
    dp[0][1] = dp[0][2] = dp[1][0] = dp[1][2] = dp[2][0] = dp[2][1] = 2147483647;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            tmp[0][j] = min(dp[1][j], dp[2][j]) + get<0>(val[i]);
            tmp[1][j] = min(dp[0][j], dp[2][j]) + get<1>(val[i]);
            tmp[2][j] = min(dp[0][j], dp[1][j]) + get<2>(val[i]);
        }

        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                dp[j][k] = tmp[j][k];
    }

    cout << min(min(min(dp[0][1], dp[0][2]), min(dp[1][0], dp[1][2])), min(dp[2][0], dp[2][1]));
}