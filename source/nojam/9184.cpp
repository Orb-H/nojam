#include <iostream>
#include <vector>

using namespace std;

vector<vector<vector<int>>> v(21, vector<vector<int>>(21, vector<int>(21, -1)));

int w(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    if (a > 20 || b > 20 || c > 20)
        return w(20, 20, 20);
    if (v[a][b][c] != -1)
        return v[a][b][c];
    else if (a < b && b < c) {
        v[a][b][c - 1] = w(a, b, c - 1);
        v[a][b - 1][c - 1] = w(a, b - 1, c - 1);
        v[a][b - 1][c] = w(a, b - 1, c);
        return v[a][b][c - 1] + v[a][b - 1][c - 1] - v[a][b - 1][c];
    }
    else {
        v[a - 1][b][c] = w(a - 1, b, c);
        v[a - 1][b - 1][c] = w(a - 1, b - 1, c);
        v[a - 1][b][c - 1] = w(a - 1, b, c - 1);
        v[a - 1][b - 1][c - 1] = w(a - 1, b - 1, c - 1);
        return v[a - 1][b][c] + v[a - 1][b - 1][c] + v[a - 1][b][c - 1] - v[a - 1][b - 1][c - 1];
    }
}

int main() {
    int a, b, c;

    while(1) {
        cin >> a >> b >> c;

        if(!(a + 1) && !(b + 1) && !(c + 1))
            break;
        
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << "\n";
    }
}