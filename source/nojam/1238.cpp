#include <iostream>

using namespace std;
typedef unsigned long long ull;
#define INF 1000000000000000ULL;

int main() {
    int n, m, x;
    int src, dst, dis;
    ull dist[1001][1001] = {0,};
    ull max = 0;

    cin >> n >> m >> x;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dist[i][j] = (i != j) * INF;

    for (int i = 0; i < m; i++) {
        cin >> src >> dst >> dis;
        dist[src][dst] = dis;
    }
    
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
    
    for (int i = 1; i <= n; i++)
        if (dist[i][x] + dist[x][i] > max)
            max = dist[i][x] + dist[x][i];

    cout << max;
}