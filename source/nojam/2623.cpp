#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m, tmp, count = 0;
    int src, dst;
    vector<int> prev;
    vector<vector<int>> graph;
    vector<int> res;
    queue<int> q;

    cin >> n >> m;

    prev.resize(n + 1, 0);
    graph.resize(n + 1);

    for (int i = 0; i < m; i++) {
        cin >> tmp >> dst;
        for (int j = 1; j < tmp; j++) {
            src = dst;
            cin >> dst;
            graph[src].push_back(dst);
            prev[dst]++;
        }
    }

    for (int i = 1; i <= n; i++)
        if (!prev[i])
            q.push(i);
    
    while (!q.empty()) {
        m = q.front();
        q.pop();
        res.push_back(m);
        count++;

        for (vector<int>::iterator it = graph[m].begin(); it < graph[m].end(); it++)
            if (!--prev[*it])
                q.push(*it);
    }

    if (count != n)
        cout << "0";
    else
        for (vector<int>::iterator it = res.begin(); it < res.end(); it++)
            cout << *it << "\n";
}