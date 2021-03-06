#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k, v, w, tmp1, tmp2, sum = 0;
    vector<int> friend_cost;
    vector<int> prev;

    cin >> n >> m >> k;
    friend_cost.resize(n + 1, 0);
    prev.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> friend_cost[i];
        prev[i] = i;
    }

    for (int i = 0; i < m; i++) {
        cin >> v >> w;
        tmp1 = v;
        tmp2 = w;

        while (tmp1 != prev[tmp1])
            tmp1 = prev[tmp1];
        while (tmp2 != prev[tmp2])
            tmp2 = prev[tmp2];
        
        if (tmp1 != tmp2) {
            if (friend_cost[tmp1] < friend_cost[tmp2])
                prev[tmp2] = prev[v] = prev[w] = tmp1;
            else
                prev[tmp1] = prev[v] = prev[w] = tmp2;
        }
    }

    for (int i = 1; i <= n; i++)
        if (prev[i] == i)
            sum += friend_cost[i];
    
    if (sum > k)
        cout << "Oh no";
    else
        cout << sum;
}