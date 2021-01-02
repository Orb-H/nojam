#include <iostream>

#define max(a, b) ((a) > (b) ? (a) : (b))

using namespace std;

int main() {
    int t;
    int n;
    int upper[100001] = {0,}, lower[100001] = {0,};
    int val_upper[100001] = {0,}, val_lower[100001] = {0,};

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n;

        for (int j = 0; j < n; j++)
            cin >> upper[j];
        for (int j = 0; j < n; j++)
            cin >> lower[j];
        
        val_upper[0] = upper[0];
        val_lower[0] = lower[0];
        if (n > 1) {
            val_upper[1] = upper[1] + lower[0];
            val_lower[1] = lower[1] + upper[0];
        }

        for (int j = 2; j < n; j++) {
            val_upper[j] = upper[j] + max(max(val_upper[j - 2], val_lower[j - 2]), val_lower[j - 1]);
            val_lower[j] = lower[j] + max(max(val_lower[j - 2], val_upper[j - 2]), val_upper[j - 1]);
        }

        cout << max(val_upper[n - 1], val_lower[n - 1]) << "\n";
    }
}