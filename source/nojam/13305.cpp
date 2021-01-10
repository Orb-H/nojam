#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

int main() {
    int n;
    ull min;
    vector<ull> price(100001, 0);
    vector<ull> dist(100001, 0);
    ull tot = 0;

    cin >> n;

    for (int i = 0; i < n - 1; i++)
        cin >> dist[i];
    for (int i = 0; i < n; i++)
        cin >> price[i];
    
    min = price[0];

    for (int i = 0; i < n - 1; i++) {
        min = price[i] < min ? price[i] : min;
        tot += min * dist[i];
    }

    cout << tot;
}