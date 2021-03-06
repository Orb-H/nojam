#include <iostream>
#include <vector>
#include <stack>
#include <tuple>
#include <cmath>

using namespace std;

typedef long long ll;
typedef tuple<int, int, ll, ll, int> ti;

int main() {
    int t, n;
    ll min;
    vector<pair<int, int>> arr;
    stack<ti> s;
    ti tmp;

    cout.precision(12);
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n;
        arr.resize(n);
        min = 1000000000000000LL;

        for (int j = 0; j < n; j++)
            cin >> arr[j].first >> arr[j].second;
        
        s.push({0, 0, 0, 0, 0});

        while (!s.empty()) {
            tmp = s.top();
            s.pop();

            if (get<4>(tmp) >= n) {
                min = get<2>(tmp) * get<2>(tmp) + get<3>(tmp) * get<3>(tmp) < min ? get<2>(tmp) * get<2>(tmp) + get<3>(tmp) * get<3>(tmp) : min;
                continue;
            }

            if (get<0>(tmp) < n / 2) {
                s.push({get<0>(tmp) + 1, get<1>(tmp), get<2>(tmp) + arr[get<4>(tmp)].first, get<3>(tmp) + arr[get<4>(tmp)].second, get<4>(tmp) + 1});
            }
            if (get<1>(tmp) < n / 2) {
                s.push({get<0>(tmp), get<1>(tmp) + 1, get<2>(tmp) - arr[get<4>(tmp)].first, get<3>(tmp) - arr[get<4>(tmp)].second, get<4>(tmp) + 1});
            }
        }

        cout << sqrt((long double)min) << "\n";
    }
}