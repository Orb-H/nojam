#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define min(a, b) ((a) < (b) ? (a) : (b))

int main() {
    int n, m;
    int memory[100];
    int cost[100];
    int dp[10001];

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> memory[i];
    for (int i = 0; i < n; i++)
        cin >> cost[i];

    for (int i = 0; i < n; i++)
        for (int j = 10000; j >= cost[i]; j--)
            dp[j] = max(dp[j], dp[j - cost[i]] + memory[i]);
    
    for (int i = 0; i < 10001; i++) {
        if (dp[i] >= m) {
            cout << i;
            break;
        }
    }
}