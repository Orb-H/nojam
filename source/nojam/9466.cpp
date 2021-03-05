#include <iostream>
#include <bitset>
#include <stack>
#include <cstring>

using namespace std;

int main() {
    int n, t, tmp, tmp2, count;
    int arr[100001];
    bitset<100001> visited;
    char res[100001] = {0,};
    stack<int> s;

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n;

        for (int j = 1; j <= n; j++)
            cin >> arr[j];

        memset(res, 0, n + 1);
        visited.reset();

        for (int j = 1; j <= n; j++) {
            if (visited.test(j))
                continue;
            
            s.push(j);
            visited.set(j);
            while (true) {
                tmp = arr[s.top()];
                if (visited.test(tmp)) {
                    if (res[tmp] == 0) {
                        tmp2 = 0;
                        while (tmp2 != tmp) {
                            tmp2 = s.top();
                            res[tmp2] = 1;
                            s.pop();
                        }
                    }
                    while (!s.empty()) {
                        tmp2 = s.top();
                        res[tmp2] = -1;
                        s.pop();
                    }
                    break;
                }
                visited.set(tmp);
                s.push(tmp);
            }
        }

        count = 0;
        for (int j = 1; j <= n; j++)
            if (res[j] == -1)
                count++;

        cout << count << "\n";
    }
}