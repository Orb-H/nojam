#include <iostream>
#include <queue>

using namespace std;

typedef unsigned long long ull;

typedef struct {
    ull value;
    int dist;
} node;

int main() {
    ull a, b;
    queue<node> q;
    node cur;
    int flag = 0;

    cin >> a >> b;

    q.push({a, 1});

    while (!q.empty()) {
        cur = q.front();
        q.pop();

        if (cur.value == b) {
            flag = 1;
            break;
        }

        if (cur.value * 2 <= b)
            q.push({cur.value * 2, cur.dist + 1});
        if (cur.value * 10 + 1 <= b)
            q.push({cur.value * 10 + 1, cur.dist + 1});
    }

    if (flag)
        cout << cur.dist << '\n';
    else
        cout << "-1\n";
}