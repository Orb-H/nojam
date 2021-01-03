#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

int main() {
    int n, k, min = 2147483647, cnt = 0;
    vector<int> a(100001, 2147483647);
    queue<pi> q;
    pi cur;

    scanf("%d %d", &n, &k);

    q.push(make_pair(n, 0));
    a[n] = 0;

    while (!q.empty()) {
        cur = q.front();
        q.pop();

        if (cur.first == k && cur.second <= min) {
            min = cur.second;
            cnt++;
        }

        if (cur.second > min) break;

        if (cur.first > 0 && a[cur.first - 1] >= a[cur.first] + 1) {
            a[cur.first - 1] = a[cur.first] + 1;
            q.push(make_pair(cur.first - 1, cur.second + 1));
        }
        if (cur.first < 100000 && a[cur.first + 1] >= a[cur.first] + 1) {
            a[cur.first + 1] = a[cur.first] + 1;
            q.push(make_pair(cur.first + 1, cur.second + 1));
        }
        if (cur.first <= 50000 && a[cur.first * 2] >= a[cur.first] + 1) {
            a[cur.first * 2] = a[cur.first] + 1;
            q.push(make_pair(cur.first * 2, cur.second + 1));
        }
    }

    printf("%d\n%d\n", min, cnt);
}