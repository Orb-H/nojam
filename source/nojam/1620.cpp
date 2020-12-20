#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool compare(pair<string, int> p1, pair<string, int> p2) {
    return p1.first.compare(p2.first) < 0;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    int start, mid, end;
    int cmp;
    char input[21];
    string names[100001];
    vector<pair<string, int>> a;

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> names[i];
        a.push_back(std::make_pair(names[i], i));
    }

    std::sort(a.begin(), a.end(), compare);

    for (int i = 0; i < m; i++) {
        cin >> input;
        
        if (input[0] <= 64) {
            cout << names[atoi(input)] << "\n";
        } else {
            start = 0;
            end = n;
            mid = (start + end) / 2;

            while ((end - start) > 1) {
                cmp = -a[mid].first.compare(input);
                if (cmp < 0) {
                    end = mid;
                    mid = (start + end) / 2;
                } else if (cmp > 0) {
                    start = mid + 1;
                    mid = (start + end) / 2;
                } else {
                    break;
                }
            }
            
            cout << a[mid].second << "\n";
        }
    }
}