#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m, src, dst;
    vector<int> a(101, 0);
    vector<int> to(101);
    queue<int> q;
    
    cin >> n >> m;

    for (int i = 0; i <= 100; i++)
        to[i] = i;
    for (int i = 0; i < n + m; i++) {
        cin >> src >> dst;
        to[src] = dst;
    }

    q.push(1);
    a[1] = 1;

    while (!q.empty()) {
        src = q.front();
        q.pop();

        for (int i = 1; i <= 6; i++) {
            if (src + i <= 100 && !a[src + i]) {
                dst = src + i;
                while (dst != to[dst])
                    dst = to[dst];
                if (!a[dst]) {
                    a[dst] = a[src] + 1;
                    q.push(dst);
                }
            }
        }
    }

    cout << a[100] - 1;
}