#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define abs(a) ((a) < 0 ? -(a) : (a))

using namespace std;

typedef long long ll;
typedef tuple<ll, ll, ll, int> tl;
typedef tuple<ll, int, int> ti;

bool comparex(tl a, tl b) { return get<0>(a) < get<0>(b); }
bool comparey(tl a, tl b) { return get<1>(a) < get<1>(b); }
bool comparez(tl a, tl b) { return get<2>(a) < get<2>(b); }

int main() {
    int n, src, dst, src_, dst_, count = 0;
    ll sum = 0;
    vector<tl> planet;
    vector<ti> graph;
    vector<int> prev;

    cin >> n;
    planet.resize(n);
    graph.resize(n * 3 - 3);
    prev.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> get<0>(planet[i]) >> get<1>(planet[i]) >> get<2>(planet[i]);
        get<3>(planet[i]) = i;
        prev[i] = i;
    }

    sort(planet.begin(), planet.end(), comparex);
    for (int i = 0; i < n - 1; i++) {
        graph.push_back({min(min(abs(get<0>(planet[i]) - get<0>(planet[i + 1])), abs(get<1>(planet[i]) - get<1>(planet[i + 1]))), abs(get<2>(planet[i]) - get<2>(planet[i + 1]))), get<3>(planet[i]), get<3>(planet[i + 1])});
    }

    sort(planet.begin(), planet.end(), comparey);
    for (int i = 0; i < n - 1; i++) {
        graph.push_back({min(min(abs(get<0>(planet[i]) - get<0>(planet[i + 1])), abs(get<1>(planet[i]) - get<1>(planet[i + 1]))), abs(get<2>(planet[i]) - get<2>(planet[i + 1]))), get<3>(planet[i]), get<3>(planet[i + 1])});
    }

    sort(planet.begin(), planet.end(), comparez);
    for (int i = 0; i < n - 1; i++) {
        graph.push_back({min(min(abs(get<0>(planet[i]) - get<0>(planet[i + 1])), abs(get<1>(planet[i]) - get<1>(planet[i + 1]))), abs(get<2>(planet[i]) - get<2>(planet[i + 1]))), get<3>(planet[i]), get<3>(planet[i + 1])});
    }
    
    sort(graph.begin(), graph.end());

    for (vector<ti>::iterator it = graph.begin(); it != graph.end(); it++) {
        if (count >= n - 1) break;

        src = get<1>(*it);
        dst = get<2>(*it);

        while (src != prev[src])
            src = prev[src];
        while (dst != prev[dst])
            dst = prev[dst];
        
        if (src != dst) {
            sum += get<0>(*it);
            count++;

            prev[dst] = prev[get<1>(*it)] = prev[get<2>(*it)] = src;
        }
    }

    cout << sum;
}