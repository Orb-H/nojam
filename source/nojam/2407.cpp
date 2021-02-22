#include <iostream>

#define cut 1000000000000000000ULL

typedef unsigned long long ull;

using namespace std;

int main() {
    int n, m;
    ull upper[101][101] = {0,};
    ull lower[101][101] = {0,};

    cin >> n >> m;

    for (int i = 0; i <= 100; i++) {
        lower[i][0] = 1;
        lower[i][i] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            lower[i][j] = lower[i - 1][j - 1] + lower[i - 1][j];
            upper[i][j] = upper[i - 1][j - 1] + upper[i - 1][j];

            if (lower[i][j] > cut) {
                lower[i][j] -= cut;
                upper[i][j]++;
            }
        }
    }

    if (upper[n][m] > 0) {
        cout << upper[n][m];
        cout.precision(-18);
        cout << lower[n][m];
    } else
        cout << lower[n][m];
}