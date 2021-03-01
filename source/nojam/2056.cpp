#include <iostream>
#include <vector>

#define max(a, b) ((a) > (b) ? (a) : (b))

using namespace std;

int main() {
    int n, k;
    int delay[10001];
    vector<int> prev_num[10001];
    int total[10001] = {0,};
    int res = 0;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> delay[i] >> k;
        prev_num[i] = vector<int>(k);
        for (int j = 0; j < k; j++)
            cin >> prev_num[i][j];
    }

    for (int i = 1; i <= n; i++) {
        for (vector<int>::iterator it = prev_num[i].begin(); it < prev_num[i].end(); it++)
            total[i] = max(total[i], total[*it]);
        total[i] += delay[i];
    }

    for (int i = 1; i <= n; i++)
        res = max(res, total[i]);
    cout << res;
}