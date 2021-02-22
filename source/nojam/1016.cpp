#include <iostream>

using namespace std;

typedef unsigned long long ull;

int main() {
    ull min, max, pow;
    int count = 0;
    int prime[1000001] = {1, 1, };
    int target[1000001] = {0,};

    cin >> min >> max;

    for (int i = 2; i <= 1000000; i++)
        if (!prime[i])
            for (int j = i * 2; j <= 1000000; j += i)
                prime[j] = 1;

    for (ull i = 2; i <= 1000000; i++) {
        if (!prime[i]) {
            pow = i * i;
            for (ull j = (min + pow - 1) / pow * pow; j <= max; j += pow)
                target[j - min] = 1;
        }
    }

    for (int i = 0; i <= max - min; i++)
        if (!target[i])
            count++;

    cout << count;
}