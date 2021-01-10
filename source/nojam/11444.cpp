#include <iostream>

using namespace std;

typedef unsigned long long ull;
typedef struct {
    ull a00, a01, a10, a11;
} matrix;

matrix I = {1, 1, 1, 0};

matrix multiply(matrix a, matrix b) {
    matrix res = {
        (a.a00 * b.a00 + a.a01 * b.a10) % 1000000007,
        (a.a00 * b.a01 + a.a01 * b.a11) % 1000000007,
        (a.a10 * b.a00 + a.a11 * b.a10) % 1000000007,
        (a.a10 * b.a01 + a.a11 * b.a11) % 1000000007
    };
    return res;
}

matrix fibonacci(ull n) {
    if (n == 1)
        return I;
    else if (n % 2 == 0) {
        matrix sqrt = fibonacci(n / 2);
        return multiply(sqrt, sqrt);
    } else {
        matrix sqrt = fibonacci(n / 2);
        return multiply(multiply(sqrt, sqrt), I);
    }
}

int main() {
    ull n;

    cin >> n;

    cout << fibonacci(n).a10;
}