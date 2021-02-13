#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef unsigned long long ull;

int main() {
    int n, m, people, tmp, count = 0;
    int knows[51] = {0,};
    int visited[51] = {0,};
    vector<vector<int>> party;
    int graph[51][51] = {0,};
    queue<int> q;

    cin >> n >> m >> people;

    party = vector<vector<int>>(m);

    for (int i = 0; i < people; i++) {
        cin >> tmp;
        knows[tmp] = 1;
    }

    for (int i = 0; i < m; i++) {
        cin >> people;
        party[i] = vector<int>(people);

        for (int j = 0; j < people; j++) {
            cin >> party[i][j];

            if (j > 0)
                graph[party[i][j]][party[i][j - 1]] = graph[party[i][j - 1]][party[i][j]] = 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (knows[i]) {
            q.push(i);
            visited[i] = 1;
        }
    }

    while (!q.empty()) {
        tmp = q.front();
        q.pop();

        for (int i = 1; i <= n; i++) {
            if (!visited[i] && graph[tmp][i]) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        tmp = 0;

        for (vector<int>::iterator it = party[i].begin(); it != party[i].end(); it++) {
            if (visited[*it]) {
                tmp = 1;
                break;
            }
        }

        if (!tmp)
            count++;
    }

    cout << count;
}