#include <iostream>
#include <string>
#include <vector>

using namespace std;

string input;
int n;
vector<int> pal_o, pal_e, longest;

int find(int start) {
    if (start >= n) return 0;
    if (start == n - 1) return 1;
    if (longest[start] != -1) return longest[start];

    int tmp = 1000000000, tmp2;

    for (int i = start; i < n - 1; i++) {
        if (pal_o[i] >= i - start) {
            tmp2 = find(start + 2 * (i - start) + 1);
            tmp = min(tmp, tmp2 + 1);
        }
        if (pal_e[i] >= i - start + 1) {
            tmp2 = find(start + 2 * (i + 1 - start));
            tmp = min(tmp, tmp2 + 1);
        }
    }

    return (longest[start] = tmp);
}

int main() {
    int j;

    cin >> input;
    n = input.length();
    pal_o.resize(n, 0);
    pal_e.resize(n, 0);
    longest.resize(n, -1);

    for (int i = 0; i < n; i++) {
        for (j = 0; j <= min(i, n - 1 - i); j++) {
            if (input[i + j] != input[i - j]) break;
            pal_o[i] = j;
        }

        if (i == n - 1) break;
        for (j = 0; j <= min(i + 1, n - 1 - i); j++) {
            if (input[i + j] != input[i + 1 - j]) break;
            pal_e[i] = j;
        }
    }

    cout << find(0);
}