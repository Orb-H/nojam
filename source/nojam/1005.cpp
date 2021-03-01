#include <iostream>
#include <queue>
#include <cstring>

#define max(a, b) ((a) > (b) ? (a) : (b))

using namespace std;

int main() {
    int t;
    int n, k, w;
    int d[1001], prev[1001], time[1001];
    queue<int> q;
    char graph[1001][1001];
    int src, dst;
    
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n >> k;

        for (int j = 1; j <= n; j++)
            cin >> d[j];
        
        memset(graph, 0, 1001 * 1001 * sizeof(char));
        memset(time, 0, (n + 1) * sizeof(int));
        memset(prev, 0, (n + 1) * sizeof(int));

        for (int j = 0; j < k; j++) {
            cin >> src >> dst;
            graph[src][dst] = 1;
            prev[dst]++;
        }

        cin >> w;

        for (int j = 1; j <= n; j++) {
            if (!prev[j]) {
                time[j] = d[j];
                q.push(j);
            }
        }

        while (!q.empty()) {
            k = q.front();
            q.pop();

            for (int j = 1; j <= n; j++) {
                if (graph[k][j]) {
                    time[j] = max(time[j], time[k] + d[j]);
                    graph[k][j] = 0;

                    if (!--prev[j])
                        q.push(j);
                }
            }
        }

        cout << time[w] << "\n";
    }
}