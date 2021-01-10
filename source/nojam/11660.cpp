#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    int x1, y1, x2, y2;
    vector<vector<ull>> v(1025, vector<ull>(1025, 0));

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> v[i][j];
            v[i][j] = v[i][j] + v[i][j - 1] + v[i - 1][j] - v[i - 1][j - 1];
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << v[x2][y2] - v[x2][y1 - 1] - v[x1 - 1][y2] + v[x1 - 1][y1 - 1] << "\n";
    }
}