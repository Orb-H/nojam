#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <algorithm>

#define sqr(x) ((x) * (x))

using namespace std;

typedef long double ld;

int main() {
    int n, src, dst, count = 0;
    ld sum = 0;
    vector<pair<ld, ld>> stars;
    vector<tuple<ld, int, int>> graph;
    vector<int> prev;

    cin >> n;
    stars.resize(n);
    prev.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> stars[i].first >> stars[i].second;
        prev[i] = i;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            graph.push_back({sqr(stars[i].first - stars[j].first) + sqr(stars[i].second - stars[j].second), i, j});
        }
    }

    sort(graph.begin(), graph.end());

    for (vector<tuple<ld, int, int>>::iterator it = graph.begin(); it != graph.end(); it++) {
        if (count >= n - 1) break;

        src = get<1>(*it);
        dst = get<2>(*it);

        while (src != prev[src])
            src = prev[src];
        while (dst != prev[dst])
            dst = prev[dst];
        
        if (src != dst) {
            sum += sqrt(get<0>(*it));
            count++;

            prev[dst] = prev[get<1>(*it)] = prev[get<2>(*it)] = src;
        }
    }

    cout << sum;
}