#include <iostream>
#include <map>
#include <vector>

using namespace std;

int n, m;
map<int, int> count;
map<int, int> tmp_count;
vector<int> s(9);

void print(int depth) {
    if (depth == m) {
        for (int i = 0; i < m; i++)
            cout << s[i] << " ";
        cout << "\n";
    } else {
        for (map<int, int>::iterator it = count.begin(); it != count.end(); it++) {
            if (tmp_count[it->first] < it->second) {
                tmp_count[it->first]++;
                s[depth] = it->first;
                print(depth + 1);
                tmp_count[it->first]--;
            }
        }
    }
}

int main() {
    int tmp;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (count.find(tmp) == count.end())
            count.insert({tmp, 1});
        else
            count[tmp]++;
        tmp_count.insert({tmp, 0});
    }

    print(0);
}