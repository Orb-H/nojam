#include <iostream>
#include <cstring>

using namespace std;

int n;
int cost[16][16];
int dp[16][1 << 16];

int find(int src, int visited) {
    if (dp[src][visited] != -1) return dp[src][visited];
    if (visited == (1 << n) - 1) return (dp[src][visited] = !cost[src][0] ? 1000000000 : cost[src][0]);

    int tmp, min = 1000000000;
    
    for (int i = 0; i < n; i++) {
        if (cost[src][i] && !(visited & (1 << i))) {
            tmp = find(i, visited | (1 << i)) + cost[src][i];
            min = tmp < min ? tmp : min;
        }
    }

    return (dp[src][visited] = min);
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];
    
    memset(dp, -1, n * (1 << 16) * sizeof(int));

    cout << find(0, 1);
}