#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    set<string> s;
    vector<string> t;
    string input;
    int count = 0;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> input;
        s.insert(input);
    }

    for (int i = 0; i < m; i++) {
        cin >> input;
        if (s.find(input) != s.end()) {
            t.push_back(input);
        }
    }

    sort(t.begin(), t.end());

    cout << t.size() << "\n";

    for (int i = 0; i < t.size(); i++) {
        cout << t[i] << "\n";
    }
}