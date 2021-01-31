#include <iostream>
#include <set>
#include <vector>

using namespace std;

int n, m;
set<int> nums;
vector<int> s(9);

void print(int depth) {
    if (depth == m) {
        for (int i = 1; i <= m; i++)
            cout << s[i] << " ";
        cout << "\n";
    } else {
        for (set<int>::iterator it = nums.begin(); it != nums.end(); it++) {
            if (s[depth] <= *it) {
                s[depth + 1] = *it;
                print(depth + 1);
            }
        }
    }
}

int main() {
    int tmp;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> tmp;
        nums.insert(tmp);
    }

    print(0);
}