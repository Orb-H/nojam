#include <iostream>

using namespace std;

int main() {
    int n, m, r, max = 0;
    int src, dst, dis;
    int item[101];
    unsigned int dist[101][101];
    int score[101] = {0,};

    cin >> n >> m >> r;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dist[i][j] = (i != j) * 2147483647;
    
    for (int i = 1; i <= n; i++)
        cin >> item[i];

    for (int i = 0; i < r; i++) {
        cin >> src >> dst >> dis;
        dist[src][dst] = dis;
        dist[dst][src] = dis;
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            if (dist[i][j] <= m)
                score[i] += item[j];
        max = score[i] > max ? score[i] : max;
    }

    cout << max;
}