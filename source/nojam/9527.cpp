#include <iostream>

#define max(a, b) ((a) > (b) ? (a) : (b))

using namespace std;

typedef long long ll;

int main() {
    ll a, b;
    ll std = 1, count = 0;

    cin >> a >> b;
    b++;

    while (std <= b) {
        std <<= 1;
        count += ((b / std) - (a / std)) * std / 2;
        count += max(0, b % std - std / 2);
        count -= max(0, a % std - std / 2);
    }

    cout << count;
}