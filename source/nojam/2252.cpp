#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    int src, dst;
    vector<int> prev;
    vector<vector<int>> graph;
    queue<int> q;

    cin >> n >> m;

    prev.resize(n + 1, 0);
    graph.resize(n + 1);

    for (int i = 0; i < m; i++) {
        cin >> src >> dst;
        graph[src].push_back(dst);
        prev[dst]++;
    }

    for (int i = 1; i <= n; i++)
        if (!prev[i])
            q.push(i);
    
    while (!q.empty()) {
        m = q.front();
        q.pop();
        cout << m << " ";

        for (vector<int>::iterator it = graph[m].begin(); it < graph[m].end(); it++)
            if (!--prev[*it])
                q.push(*it);
    }
}