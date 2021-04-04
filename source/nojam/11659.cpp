#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m, ii, jj;
    vector<int> a;

    cin >> n >> m;
    a.resize(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }

    for (int i = 0; i < m; i++) {
        cin >> ii >> jj;
        cout << a[jj] - a[ii - 1] << "\n";
    }
}