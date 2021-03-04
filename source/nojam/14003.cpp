#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, max = 1, s, e, m;
    vector<int> a;
    vector<int> prev;
    vector<int> last;
    vector<int> res;

    cin >> n;
    a.resize(n + 1);
    prev.resize(n + 1);
    last.resize(n + 1, 0);

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    prev[1] = -1;
    last[0] = -1;
    last[1] = 1;
    for (int i = 2; i <= n; i++) {
        s = 1;
        e = max + 1;
        m = (s + e) / 2;

        while (e - s > 1) {
            if (a[i] > a[last[m]])
                s = m;
            else if (a[i] < a[last[m]])
                e = m;
            else
                break;
            m = (s + e) / 2;
        }

        if (a[i] > a[last[m]]) {
            last[m + 1] = i;
            prev[i] = last[m];
            if (m == max) max++;
        } else {
            last[m] = i;
            prev[i] = last[m - 1];
        }
    }

    m = last[max];
    while (prev[m] != -1) {
        res.push_back(m);
        m = prev[m];
    }
    res.push_back(m);

    cout << max << "\n";
    for (vector<int>::reverse_iterator it = res.rbegin(); it != res.rend(); it++) {
        cout << a[*it] << " ";
    }
}