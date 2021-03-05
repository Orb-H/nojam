#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main() {
    int v, e, src, dst, dis, sum = 0;
    vector<tuple<int, int, int>> graph;
    vector<int> prev;

    cin >> v >> e;

    graph.resize(e);
    prev.resize(v + 1, -1);

    for (int i = 0; i < e; i++) {
        cin >> src >> dst >> dis;
        graph[i] = {dis, src, dst};
    }

    for (int i = 1; i <= v; i++)
        prev[i] = i;

    sort(graph.begin(), graph.end());

    for (int i = 0; i < e; i++) {
        src = get<1>(graph[i]);
        dst = get<2>(graph[i]);

        while (src != prev[src]) src = prev[src];
        while (dst != prev[dst]) dst = prev[dst];
        
        if (src != dst) {
            sum += get<0>(graph[i]);
            prev[dst] = src;
            prev[get<1>(graph[i])] = src;
            prev[get<2>(graph[i])] = src;
        }
    }

    cout << sum;
}