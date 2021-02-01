#include <iostream>

using namespace std;

int main() {
    int n, m, src, dst, dis, min;
    int start, end;
    int graph[1001][1001];
    int visited[1001] = {0,};
    int tot_dist[1001];

    for (int i = 0; i < 1001; i++) {
        tot_dist[i] = 1000000000;
        for (int j = 0; j < 1001; j++) {
            graph[i][j] = 1000000000;
        }
    }

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> src >> dst >> dis;
        graph[src][dst] = graph[src][dst] < dis ? graph[src][dst] : dis;
    }

    cin >> start >> end;

    tot_dist[start] = 0;

    while (true) {
        min = 0;
        for (int i = 1; i <= n; i++)
            if (!visited[i] && tot_dist[i] < tot_dist[min])
                min = i;
        visited[min] = 1;

        if (min == end || min == 0) break;

        for (int i = 1; i <= n; i++)
            if (tot_dist[i] > tot_dist[min] + graph[min][i])
                tot_dist[i] = tot_dist[min] + graph[min][i];
    }

    cout << tot_dist[end];
}