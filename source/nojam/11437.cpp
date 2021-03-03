#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m, tmp, src, dst;
    vector<int> parent, rank;
    vector<bool> visited;
    vector<vector<int>> graph;
    queue<int> q;

    cin >> n;

    parent.resize(n + 1);
    rank.resize(n + 1);
    graph.resize(n + 1);
    visited.resize(n + 1, false);

    for (int i = 0; i < n - 1; i++) {
        cin >> src >> dst;
        graph[src].push_back(dst);
        graph[dst].push_back(src);
    }
    
    q.push(1);
    visited[1] = true;
    parent[1] = 0;
    rank[1] = 0;

    while (!q.empty()) {
        tmp = q.front();
        q.pop();

        for (vector<int>::iterator it = graph[tmp].begin(); it < graph[tmp].end(); it++) {
            if (!visited[*it]) {
                q.push(*it);
                visited[*it] = true;
                parent[*it] = tmp;
                rank[*it] = rank[tmp] + 1;
            }
        }
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> src >> dst;

        while (rank[src] > rank[dst])
            src = parent[src];
        while (rank[src] < rank[dst])
            dst = parent[dst];
        
        while (src != dst) {
            src = parent[src];
            dst = parent[dst];
        }

        cout << src << "\n";
    }
}