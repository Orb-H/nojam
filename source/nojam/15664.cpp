#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> nums;
vector<int> stack;

void dfs(int include, int depth) {
    if (depth == m) {
        for (int i = 0; i < m - 1; i++)
            printf("%d ", stack[i]);
        printf("%d\n", stack[m - 1]);
    } else {
        for (int i = 0; i < n; i++) {
            if (!(include & (1 << i))) {
                stack.push_back(nums[i]);
                dfs(include | (1 << i), depth + 1);
            }
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