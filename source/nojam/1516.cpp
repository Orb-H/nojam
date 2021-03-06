#include <iostream>
#include <vector>
#include <queue>

#define max(a, b) ((a) > (b) ? (a) : (b))

using namespace std;

int main() {
    int n, tmp;
    vector<vector<int>> graph;
    vector<int> prev;
    vector<int> time;
    vector<int> before_time;
    queue<int> q;

    cin >> n;
    graph.resize(n + 1);
    prev.resize(n + 1, 0);
    time.resize(n + 1, 0);
    before_time.resize(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> time[i];

        while (true) {
            cin >> tmp;
            if (tmp == -1) break;

            graph[tmp].push_back(i);
            prev[i]++;
        }
    }

    for (int i = 1; i <= n; i++)
        if (!prev[i])
            q.push(i);

    while (!q.empty()) {
        tmp = q.front();
        q.pop();

        for (vector<int>::iterator it = graph[tmp].begin(); it != graph[tmp].end(); it++) {
            before_time[*it] = max(before_time[*it], before_time[tmp] + time[tmp]);
            if (!--prev[*it])
                q.push(*it);
        }
    }

    for (int i = 1; i <= n; i++)
        cout << before_time[i] + time[i] << "\n";
}