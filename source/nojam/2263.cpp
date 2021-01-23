#include <iostream>
#include <vector>

using namespace std;

vector<int> infix(100000);
vector<int> postfix(100000);
vector<pair<int, int>> tree(100001);

void compare(int s_i, int s_p, int n) { // Both inclusive
    int pivot;

    for (int i = 0; i < n; i++) {
        if (infix[s_i + i] == postfix[s_p + n - 1]) {
            pivot = i;
            break;
        }
    }

    if (pivot > 0) {
        compare(s_i, s_p, pivot);
        tree[postfix[s_p + n - 1]].first = postfix[s_p + pivot - 1];
    }
    if (n - pivot > 1) {
        compare(s_i + pivot + 1, s_p + pivot, n - pivot - 1);
        tree[postfix[s_p + n - 1]].second = postfix[s_p + n - 2];
    }
}

void print_pre(int n) {
    cout << n << " ";
    
    if (tree[n].first)
        print_pre(tree[n].first);
    if (tree[n].second)
        print_pre(tree[n].second);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> infix[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> postfix[i];
    }

    tree[0].first = postfix[n - 1];
    compare(0, 0, n);

    print_pre(tree[0].first);
}