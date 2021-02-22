#include <iostream>

using namespace std;

#define INF 1000000000000000ULL
typedef unsigned long long ull;

int main() {
    int n, e, v1, v2;
    int src, dst, dis;
    ull edge[801][801];

    cin >> n >> e;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            edge[i][j] = (i != j) * INF;
        }
    }

    for (int i = 0; i < e; i++) {
        cin >> src >> dst >> dis;
        if (edge[src][dst] > dis) {
            edge[src][dst] = dis;
            edge[dst][src] = dis;
        }
    }

    cin >> v1 >> v2;

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (edge[i][j] > edge[i][k] + edge[k][j])
                    edge[i][j] = edge[i][k] + edge[k][j];

    if (edge[1][n] >= INF) {
        cout << -1;
    } else {
        if (edge[1][v1] + edge[v2][n] < edge[1][v2] + edge[v1][n])
            cout << edge[1][v1] + edge[v1][v2] + edge[v2][n];
        else
            cout << edge[1][v2] + edge[v2][v1] + edge[v1][n];
    }
}