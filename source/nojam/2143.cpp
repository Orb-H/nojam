#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    int n, m, nn, mm, x, y, tmp;
    ll t, count = 0, xn, yn;
    vector<ll> a, b, sum_a, sum_b;

    cin >> t >> n;
    a.resize(n);
    sum_a.resize((nn = n * (n + 1) / 2));
    cin >> a[0];
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    cin >> m;
    b.resize(m);
    sum_b.resize((mm = m * (m + 1) / 2));
    cin >> b[0];
    for (int i = 1; i < m; i++) {
        cin >> b[i];
        b[i] += b[i - 1];
    }

    tmp = 0;
    for (int i = 0; i < n; i++) {
        sum_a[tmp++] = a[i];
        for (int j = i + 1; j < n; j++)
            sum_a[tmp++] = a[j] - a[i];
    }

    tmp = 0;
    for (int i = 0; i < m; i++) {
        sum_b[tmp++] = b[i];
        for (int j = i + 1; j < m; j++)
            sum_b[tmp++] = b[j] - b[i];
    }

    sort(sum_a.begin(), sum_a.end());
    sort(sum_b.rbegin(), sum_b.rend());

    x = y = 0;
    xn = yn = 1;
    while (x < nn - 1 && sum_a[x] == sum_a[x + 1])
        x++, xn++;
    while (y < mm - 1 && sum_b[y] == sum_b[y + 1])
        y++, yn++;
    while (x < nn && y < mm) {
        if (sum_a[x] + sum_b[y] > t) {
            yn = 1;
            y++;
            while (y < mm - 1 && sum_b[y] == sum_b[y + 1])
                y++, yn++;
        } else if (sum_a[x] + sum_b[y] < t) {
            xn = 1;
            x++;
            while (x < nn - 1 && sum_a[x] == sum_a[x + 1])
                x++, xn++;
        } else {
            count += xn * yn;
            xn = yn = 1;
            x++, y++;
            while (x < nn - 1 && sum_a[x] == sum_a[x + 1])
                x++, xn++;
            while (y < mm - 1 && sum_b[y] == sum_b[y + 1])
                y++, yn++;
        }
    }

    cout << count;
}