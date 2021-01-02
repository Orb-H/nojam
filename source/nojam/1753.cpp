#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int v, e, k;
    int src, dst, dis;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    pair<int, int> tmp;

    cin >> v >> e >> k;

    vector<vector<pair<int, int>>> edge(v + 1, vector<pair<int, int>>());
    vector<int> distance(v + 1, 2147483647);
    
    for (int i = 0; i < e; i++) {
        cin >> src >> dst >> dis;
        edge[src].push_back(make_pair(dis, dst));
    }

    distance[k] = 0;
    q.push({0, k});

    while (!q.empty()) {
        tmp = q.top();
        q.pop();

        for (vector<pair<int, int>>::iterator it = edge[tmp.second].begin(); it < edge[tmp.second].end(); it++) {
            if (distance[(*it).second] > distance[tmp.second] + (*it).first) {
                distance[(*it).second] = distance[tmp.second] + (*it).first;
                q.push({distance[(*it).second], (*it).second});
            }
        }
    }

    for (vector<int>::iterator it = distance.begin() + 1; it < distance.end(); it++) {
        if (*it == 2147483647)
            cout << "INF\n";
        else
            cout << *it << "\n";
    }
}