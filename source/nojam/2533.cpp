#include <iostream>
#include <vector>

#define min(a, b) ((a) < (b) ? (a) : (b))

using namespace std;

typedef pair<int, int> pii;

vector<vector<int>> graph;

pii find(int prev, int cur) {
    if (graph[cur].size() == 1 && prev >= 1) return {1, 0};
    pii sum = {0, 0}, tmp;
    
    for (vector<int>::iterator it = graph[cur].begin(); it != graph[cur].end(); it++) {
        if (*it != prev) {
            tmp = find(cur, *it);
            sum.first += min(tmp.first, tmp.second);
            sum.second += tmp.first;
        }
    }

    sum.first++;

    return sum;
}

int main() {
    int n, src, dst;
    pii tmp;
    
    cin >> n;
    graph.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {
        cin >> src >> dst;
        graph[src].push_back(dst);
        graph[dst].push_back(src);
    }

    tmp = find(-1, 1);

    cout << min(tmp.first, tmp.second);
}