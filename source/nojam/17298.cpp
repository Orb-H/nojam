#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int n;
    vector<int> v(1000000);
    vector<int> nge(1000000);
    stack<int> s;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && s.top() <= v[i])
            s.pop();
        if (s.empty())
            nge[i] = -1;
        else
            nge[i] = s.top();
        s.push(v[i]);
    }

    for (int i = 0; i < n; i++)
        cout << nge[i] << " ";
}