#include <iostream>

using namespace std;

typedef struct _node {
    char left;
    char right;
} node;

node tree[26];

void prefix(char n) {
    cout << n;
    if (tree[n - 'A'].left != '.')
        prefix(tree[n - 'A'].left);
    if (tree[n - 'A'].right != '.')
        prefix(tree[n - 'A'].right);
}

void infix(char n) {
    if (tree[n - 'A'].left != '.')
        infix(tree[n - 'A'].left);
    cout << n;
    if (tree[n - 'A'].right != '.')
        infix(tree[n - 'A'].right);
}

void postfix(char n) {
    if (tree[n - 'A'].left != '.')
        postfix(tree[n - 'A'].left);
    if (tree[n - 'A'].right != '.')
        postfix(tree[n - 'A'].right);
    cout << n;
}

int main() {
    int n;
    char tmp, tmp_l, tmp_r;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        cin >> tmp >> tmp_l >> tmp_r;
        tree[tmp - 'A'].left = tmp_l;
        tree[tmp - 'A'].right = tmp_r;
    }

    prefix('A');
    cout << "\n";

    infix('A');
    cout << "\n";

    postfix('A');
}