#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int n, tmp;
    int prev[1000001] = {0, };
    unsigned int count[1000001] = {0, };

    cin >> n;

    memset(count, -1, (n + 1) * sizeof(unsigned int));
    count[1] = 0;

    for (int i = 1; i < n; i++) {
        if (count[i + 1] > count[i] + 1) {
            prev[i + 1] = i;
            count[i + 1] = count[i] + 1;
        }
        if (2 * i <= 1000000) {
            if (count[2 * i] > count[i] + 1) {
                prev[2 * i] = i;
                count[2 * i] = count[i] + 1;
            }
        }
        if (3 * i <= 1000000) {
            if (count[3 * i] > count[i] + 1) {
                prev[3 * i] = i;
                count[3 * i] = count[i] + 1;
            }
        }
    }

    cout << count[n] << "\n";
    tmp = n;
    while (tmp != 1) {
        cout << tmp << " ";
        tmp = prev[tmp];
    }
    cout << 1;
}