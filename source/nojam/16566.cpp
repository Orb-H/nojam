#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m, k, input, tmp, s, e, mid;
    int cards[4000000], prev[4000001];
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        cin >> cards[i];
        prev[i] = i;
    }
    prev[m] = m;

    sort(&cards[0], &cards[m]);

    for (int i = 0; i < k; i++) {
        cin >> input;
        s = 0;
        e = m;
        mid = (s + e) / 2;

        while ((e - s) > 1) {
            if (cards[mid] > input)
                e = mid;
            else
                s = mid;
            mid = (s + e) / 2;
        }

        if (cards[mid] <= input)
            tmp = mid + 1;
        else
            tmp = mid;

        while (tmp != prev[tmp])
            tmp = prev[tmp];
        
        cout << cards[tmp] << "\n";
        prev[tmp] = prev[input] = prev[tmp + 1];
    }
}