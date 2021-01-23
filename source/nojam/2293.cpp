#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    vector<int> value(100);
    vector<int> cases(10001);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }

    value.resize(n);
    sort(value.begin(), value.end());

    cases[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k - value[i]; j++) {
            cases[j + value[i]] += cases[j];
        }
    }

    cout << cases[k];
}