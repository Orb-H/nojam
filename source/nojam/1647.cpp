#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

typedef tuple<int, int, int> ti;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m, src, dst, dis, sum = 0, count = 0;
    vector<ti> graph;
    ti last;
    ti tmp;
    vector<int> prev;
    
    cin >> n >> m;
    graph.resize(m);
    prev.resize(n + 1);

    for (int i = 0; i < m; i++) {
        cin >> src >> dst >> dis;
        graph[i] = {dis, src, dst};
    }

    sort(graph.begin(), graph.end());

    for (int i = 1; i <= n; i++)
        prev[i] = i;

    for (int i = 0; i < m; i++) {
        if (count >= n - 1) break;
        tmp = graph[i];

        src = get<1>(tmp);
        dst = get<2>(tmp);

        while (src != prev[src])
            src = prev[src];
        while (dst != prev[dst])
            dst = prev[dst];
        
        if (src != dst) {
            sum += get<0>(tmp);
            last = tmp;

            prev[dst] = prev[get<1>(tmp)] = prev[get<2>(tmp)] = src;
            count++;
        }
    }

    cout << sum - get<0>(last);
}