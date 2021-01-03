#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    priority_queue<pi, vector<pi>, greater<pi>> q;
    pi cur;
    vector<int> visited(100001, 0);

    cin >> n >> k;

    q.push(make_pair(0, n));
    visited[n] = 1;

    while (!q.empty()) {
        cur = q.top();
        q.pop();

        if (cur.second == k) {
            cout << cur.first;
            break;
        }

        for (int i = cur.second * 2; i <= 100000; i <<= 1) {
            if (!visited[i]) {
                q.push(make_pair(cur.first, i));
                visited[i] = 1;
            } else break;
        }
        if (!visited[cur.second - 1] && cur.second > 0) {
            q.push(make_pair(cur.first + 1, cur.second - 1));
            visited[cur.second - 1] = 1;
        }
        if (!visited[cur.second + 1] && cur.second < 100000) {
            q.push(make_pair(cur.first + 1, cur.second + 1));
            visited[cur.second + 1] = 1;
        }
    }
}