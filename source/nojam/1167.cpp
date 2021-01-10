#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int v;
    int src, dst, dis;
    int max = 0, max_loc = 1;
    vector<vector<pair<int, int>>> edge(100001, vector<pair<int, int>>());
    stack<pair<int, int>> s;
    vector<int> visited(100001);

    cin >> v;

    for (int i = 0; i < v; i++) {
        cin >> src >> dst >> dis;
        edge[src].push_back(make_pair(dst, dis));

        while(1) {
            cin >> dst;
            if (dst == -1)
                break;
            else {
                cin >> dis;
                edge[src].push_back(make_pair(dst, dis));
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        fill(visited.begin(), visited.end(), 0);
        visited[max_loc] = 1;

        s.push({max_loc, 0});

        while (!s.empty()) {
            src = s.top().first;
            dis = s.top().second;
            s.pop();

            for (int j = 0; j < edge[src].size(); j++) {
                if (!visited[edge[src][j].first]) {
                    s.push({edge[src][j].first, edge[src][j].second + dis});
                    visited[edge[src][j].first] = 1;
                    if (max < edge[src][j].second + dis) {
                        max = edge[src][j].second + dis;
                        max_loc = edge[src][j].first;
                    }
                }
            }
        }
    }

    cout << max;
}