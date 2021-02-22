#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int x, y;
    vector<vector<int>> graph(100001);
    vector<bool> visited(100001, false);
    vector<int> parent(100001, 0);
    queue<int> q;

    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        x = q.front();
        q.pop();

        for (vector<int>::iterator it = graph[x].begin(); it < graph[x].end(); it++) {
            if (!visited[*it]) {
                visited[*it] = true;
                q.push(*it);
                parent[*it] = x;
            }
        }
    }

    for (int i = 2; i <= n; i++)
        cout << parent[i] << "\n";
}