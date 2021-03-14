#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;
typedef pair<int, int> pii;

int main() {
    int n, k, tmp, s, e, m;
    ull sum = 0;
    vector<pii> mv;
    vector<int> c, prev;

    cin >> n >> k;
    mv.resize(n);
    c.resize(k);
    prev.resize(k + 1);

    for (int i = 0; i < n; i++)
        cin >> mv[i].second >> mv[i].first;
    for (int i = 0; i <= k; i++)
        prev[i] = i;

    for (int i = 0; i < k; i++)
        cin >> c[i];

    sort(mv.rbegin(), mv.rend());
    sort(c.begin(), c.end());

    for (vector<pii>::iterator it = mv.begin(); it != mv.end(); it++) {
        s = 0;
        e = k;
        m = (s + e) / 2;

        while ((e - s) > 1) {
            if (c[m] > (*it).second)
                e = m;
            else
                s = m;
            m = (s + e) / 2;
        }

        if (c[m] >= (*it).second)
            tmp = m;
        else
            tmp = m + 1;
        m = tmp;
        
        while (tmp != prev[tmp])
            tmp = prev[tmp];

        if (tmp != k) {
            sum += (*it).first;
            prev[tmp] = prev[m] = prev[tmp + 1];
        }
    }

    cout << sum;
}