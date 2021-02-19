#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, s;
    int a[100001];
    int x = 0, y = 0, min = 2147483647, sum = 0;

    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    while (y <= n) {
        if (sum < s)
            sum += a[y++];
        else {
            min = y - x < min ? y - x : min;
            sum -= a[x++];
        }
    }

    if (min == 2147483647)
        cout << 0;
    else
        cout << min;
}