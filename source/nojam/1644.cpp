#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, s, e, sum = 2, count = 0;
    vector<int> prime;
    bool not_prime[4000001] = {true, true,};

    cin >> n;

    for (int i = 2; i <= n; i++) {
        if (!not_prime[i]) {
            prime.push_back(i);
            for (int j = 2; j <= n / i; j++)
                if (i * j <= n)
                    not_prime[i * j] = true;
        }
    }

    s = e = 0;
    while (e < prime.size()) {
        if (n > sum)
            sum += prime[++e];
        else if (n < sum)
            sum -= prime[s++];
        else {
            count++;
            sum -= prime[s++];
            sum += prime[++e];
        }
    }

    cout << count;
}