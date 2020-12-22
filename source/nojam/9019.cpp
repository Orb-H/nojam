#include <iostream>
#include <queue>
#include <string>

using namespace std;

int dd(int a) {
    return (2 * a) % 10000;
}

int ss(int a) {
    return (a + 9999) % 10000;
}

int ll(int a) {
    return 10 * (a % 1000) + a / 1000;
}

int rr(int a) {
    return 1000 * (a % 10) + a / 10;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t, a, b, d, s, l, r;
    queue<pair<int, string>> q;
    char visited[1250] = {0,};
    string cur;

    cin >> t;

    for (int i = 0; i < t; i++) {
        while (!q.empty()) q.pop();
        for (int i = 0; i < 1250; i++) visited[i] = 0;

        cin >> a >> b;

        q.push({a, ""});
        visited[a / 8] |= 1 << (a % 8);

        while (!q.empty()) {
            a = q.front().first;
            if (a == b) break;
            cur = q.front().second;
            q.pop();

            d = dd(a);
            s = ss(a);
            l = ll(a);
            r = rr(a);

            if (!(visited[d / 8] & (1 << (d % 8)))) {
                visited[d / 8] |= 1 << (d % 8);
                q.push({d, cur + "D"});
            }
            if (!(visited[l / 8] & (1 << (l % 8)))) {
                visited[l / 8] |= 1 << (l % 8);
                q.push({l, cur + "L"});
            }
            if (!(visited[s / 8] & (1 << (s % 8)))) {
                visited[s / 8] |= 1 << (s % 8);
                q.push({s, cur + "S"});
            }
            if (!(visited[r / 8] & (1 << (r % 8)))) {
                visited[r / 8] |= 1 << (r % 8);
                q.push({r, cur + "R"});
            }
        }

        cout << q.front().second << "\n";
    }
}