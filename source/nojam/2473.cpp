#include <iostream>
#include <algorithm>
#include <vector>

#define abs(x) ((x) < 0 ? -(x) : (x))

using namespace std;

typedef long long ll;

int main() {
    int n, s, e;
    vector<ll> arr;
    ll res[3], sum, tmp;

    cin >> n;

    arr.resize(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());
    
    res[0] = arr[0];
    res[1] = arr[1];
    res[2] = arr[2];
    sum = arr[0] + arr[1] + arr[2];
    
    for (int i = 0; i < n; i++) {
        s = i + 1;
        e = n - 1;

        while (s < e) {
        tmp = arr[i] + arr[s] + arr[e];
            if (abs(tmp) < abs(sum)) {
                res[0] = arr[i];
                res[1] = arr[s];
                res[2] = arr[e];
                sum = tmp;
            }

            if (tmp > 0)
                e--;
            else if (tmp < 0)
                s++;
            else
                e--, s++;
        }
    }

    cout << res[0] << " " << res[1] << " " << res[2];
}