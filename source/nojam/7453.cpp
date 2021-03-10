#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, x, y, nn;
    long long count = 0, xn, yn;
    vector<int> a, b, c, d, ab, cd;

    cin >> n;
    nn = n * n;
    a.resize(n), b.resize(n), c.resize(n), d.resize(n);
    ab.resize(nn), cd.resize(nn);

    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ab[i * n + j] = a[i] + b[j];
            cd[i * n + j] = c[i] + d[j];
        }
    }

    sort(ab.begin(), ab.end());
    sort(cd.rbegin(), cd.rend());

    x = y = 0;
    xn = yn = 1;

    while (x < nn - 1 && ab[x] == ab[x + 1])
        x++, xn++;
    while (y < nn - 1 && cd[y] == cd[y + 1])
        y++, yn++;

    while (x < nn && y < nn) {
        if (ab[x] + cd[y] > 0) {
            yn = 1;
            y++;
            while (y < nn - 1 && cd[y] == cd[y + 1])
                y++, yn++;
        }
        else if (ab[x] + cd[y] < 0) {
            xn = 1;
            x++;
            while (x < nn - 1 && ab[x] == ab[x + 1])
                x++, xn++;
        }
        else {
            count += xn * yn;
            xn = yn = 1;
            x++, y++;
            while (x < nn - 1 && ab[x] == ab[x + 1])
                x++, xn++;
            while (y < nn - 1 && cd[y] == cd[y + 1])
                y++, yn++;
        }
    }

    cout << count;
}