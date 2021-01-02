#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    int src, dst, dis;

    cin >> n >> m;
    
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, 2147483647));

    for (int i = 0; i < m; i++) {
        cin >> src >> dst >> dis;
        if (dist[src][dst] > dis)
            dist[src][dst] = dis;
    }

    for (int i = 1; i <= n; i++)
        dist[i][i] = 0;

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (dist[i][k] < 2147483647 && dist[k][j] < 2147483647 && dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == 2147483647)
                cout << "0 ";
            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}