#include <iostream>
#include <vector>
#include <tuple>

#define INF 1073741823
#define ti3 tuple<int, int, int>

using namespace std;

int main() {
    int tc;
    int n, m, w;
    int src, dst, dis;

    cin >> tc;

    for (int i = 0; i < tc; i++) {
        cin >> n >> m >> w;

        vector<ti3> path;
        vector<int> dist(n + 1, INF);
        int flag = 1;

        for (int j = 0; j < m; j++) {
            cin >> src >> dst >> dis;
            path.push_back({src, dst, dis});
            path.push_back({dst, src, dis});
        }

        for (int j = 0; j < w; j++) {
            cin >> src >> dst >> dis;
            path.push_back({src, dst, -dis});
        }

        dist[1] = 0;

        for (int j = 0; j < n - 1; j++) {
            for (vector<ti3>::iterator it = path.begin(); it < path.end(); it++) {
                if (dist[get<0>(*it)] + get<2>(*it) < dist[get<1>(*it)]) {
                    dist[get<1>(*it)] = dist[get<0>(*it)] + get<2>(*it);
                }
            }
        }

        for (vector<ti3>::iterator it = path.begin(); it < path.end(); it++) {
            if (dist[get<0>(*it)] + get<2>(*it) < dist[get<1>(*it)]) {
                flag = 0;
                cout << "YES\n";
                break;
            }
        }

        if (flag)
            cout << "NO\n";
    }
}