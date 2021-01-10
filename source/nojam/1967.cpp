#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int n;
    int src, dst, dis;
    int max = 0;
    int flag;
    vector<vector<pair<int, int>>> edge(10001, vector<pair<int, int>>());
    stack<pair<int, int>> s;
    vector<int> visited(10001);

    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        cin >> src >> dst >> dis;
        edge[src].push_back(make_pair(dst, dis));
        edge[dst].push_back(make_pair(src, dis));
    }

    for (int i = 1; i <= n; i++) {
        fill(visited.begin(), visited.end(), 0);
        visited[i] = 1;

        s.push({i, 0});

        while (!s.empty()) {
            src = s.top().first;
            dis = s.top().second;
            s.pop();

            for (int j = 0; j < edge[src].size(); j++) {
                if (!visited[edge[src][j].first]) {
                    s.push({edge[src][j].first, edge[src][j].second + dis});
                    visited[edge[src][j].first] = 1;
                    max = max < edge[src][j].second + dis ? edge[src][j].second + dis : max;
                }
            }
        }
    }

    cout << max;
}