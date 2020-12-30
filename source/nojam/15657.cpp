#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> nums;
vector<int> stack;

void dfs(int last_idx, int depth) {
    if (depth == m) {
        for (int i = 0; i < m - 1; i++)
            printf("%d ", stack[i]);
        printf("%d\n", stack[m - 1]);
    } else {
        for (int i = last_idx; i < n; i++) {
            stack.push_back(nums[i]);
            dfs(i, depth + 1);
        }
    }

    stack.pop_back();
}

int main() {
    int t;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        nums.push_back(t);
    }

    sort(nums.begin(), nums.end());

    dfs(0, 0);
}