#include <iostream>

using namespace std;

typedef unsigned long long ull;
typedef struct {
    ull e[8][8];
} matrix;

matrix a;

matrix multiply(int n) {
    if (n == 1) return a;

    matrix half = multiply(n / 2), res;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            res.e[i][j] = 0;
            for (int k = 0; k < 8; k++)
                res.e[i][j] += half.e[i][k] * half.e[k][j];
            res.e[i][j] %= 1000000007;
        }
    }

    if (n % 2) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                half.e[i][j] = res.e[i][j];
                res.e[i][j] = 0;
            }
        }

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                for (int k = 0; k < 8; k++)
                    res.e[i][j] += half.e[i][k] * a.e[k][j];
                res.e[i][j] %= 1000000007;
            }
        }
    }

    return res;
}

int main() {
    int d;

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            a.e[i][j] = 0;
    a.e[0][1] = a.e[0][2] = a.e[1][0] = a.e[1][2] = a.e[1][3] = a.e[2][0] = a.e[2][1] = a.e[2][3] = a.e[2][4] = a.e[3][1] = a.e[3][2] = a.e[3][4] = a.e[3][5] = a.e[4][2] = a.e[4][3] = a.e[4][5] = a.e[4][6] = a.e[5][3] = a.e[5][4] = a.e[5][7] = a.e[6][4] = a.e[6][7] = a.e[7][5] = a.e[7][6] = 1;

    cin >> d;
    cout << multiply(d).e[0][0];
}