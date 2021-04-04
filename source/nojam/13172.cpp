#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

ull pow(ull a, int n) {
    if (n == 1) return a;

    ull res;
    res = pow(a, n / 2);
    res *= res;
    res %= 1000000007;
    if (n % 2) {
        res *= a;
        res %= 1000000007;
    }
    return res;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int m;
    vector<ull> n, s;
    ull res = 0;

    cin >> m;
    n.resize(m);
    s.resize(m);

    for (int i = 0; i < m; i++) {
        cin >> n[i] >> s[i];
        res += s[i] * pow(n[i], 1000000005);
        res %= 1000000007;
    }

    cout << res;
}