#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int> lower;
    priority_queue<int, vector<int>, greater<int>> upper;
    int n;
    int input;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> input;

        lower.push(input);
        upper.push(lower.top());
        lower.pop();

        if (upper.size() > lower.size()) {
            lower.push(upper.top());
            upper.pop();
        }

        cout << lower.top() << "\n";
    }
}