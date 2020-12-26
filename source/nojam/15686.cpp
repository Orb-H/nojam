#include <stdio.h>
#include <vector>

#define abs(x) ((x) > 0 ? (x) : -(x))

using namespace std;

typedef struct {
    int y;
    int x;
} pos;

int n, m, tmp;
int min_val = 2147483647;
vector<pos> house;
vector<pos> chicken;

void dfs(int include, int depth, int start) {
    if (depth == m) {
        int sum = 0;
        int min_dist;

        for (int i = 0; i < house.size(); i++) {
            min_dist = 2147483647;
            for (int j = 0; j < chicken.size(); j++) {
                if (include & (1 << j)) {
                    tmp = abs(house[i].y - chicken[j].y) + abs(house[i].x - chicken[j].x);
                    min_dist = min_dist < tmp ? min_dist : tmp;
                }
            }
            sum += min_dist;
        }

        min_val = min_val < sum ? min_val : sum;
    } else {
        if (chicken.size() - start < m - depth)
            return;
        
        for (int i = start; i < chicken.size(); i++)
            dfs(include | (1 << i), depth + 1, i + 1);
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &tmp);
            if (tmp == 1)
                house.push_back({i, j});
            else if (tmp == 2)
                chicken.push_back({i, j});
        }
    }

    dfs(0, 0, 0);
    printf("%d", min_val);
}