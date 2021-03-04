#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, max = 1, s, e, m;
    vector<pair<int, int>> lines; // 줄의 정보(시작점 / 도착점) 저장
    int prev[500000] = {0,}; // 이전 경로의 인덱스
    vector<int> last; // 주어진 길이의 LIS의 마지막 원소의 인덱스
    bool leave[500000] = {false,}; // n번째 전깃줄을 출력할지 말지 결정

    cin >> n;
    lines.resize(n + 1);
    last.resize(n + 1, 0);

    for (int i = 1; i <= n; i++)
        cin >> lines[i].first >> lines[i].second;
    
    sort(lines.begin() + 1, lines.end());

    prev[1] = -1;
    last[0] = -1;
    last[1] = 1;
    for (int i = 2; i <= n; i++) {
        s = 1;
        e = max + 1;
        m = (s + e) / 2;

        while (e - s > 1) {
            if (lines[i].second > lines[last[m]].second)
                s = m;
            else if (lines[i].second < lines[last[m]].second)
                e = m;
            else
                break;
            m = (s + e) / 2;
        }

        if (lines[i].second > lines[last[m]].second) {
            last[m + 1] = i;
            prev[i] = last[m];
            if (m == max) max++;
        } else {
            last[m] = i;
            prev[i] = last[m - 1];
        }
    }

    m = last[max];
    while (prev[m] != -1) {
        leave[m] = true;
        m = prev[m];
    }
    leave[m] = true;

    cout << n - max << "\n";
    for (int i = 1; i <= n; i++) {
        if (!leave[i])
            cout << lines[i].first << "\n";
    }
}