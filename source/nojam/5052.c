#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int stat;
    struct _node* next[10];
} node;

node* create_node() {
    node* n = (node*)malloc(sizeof(node));
    n->stat = 0;
    for (int i = 0; i < 10; i++)
        n->next[i] = NULL;
    return n;
}

int add(node* n, char* s) {
    int i = 0, res = 1;
    while (s[i]) {
        if (n->next[s[i] - '0'] == NULL)
            n->next[s[i] - '0'] = create_node();
        if (n->stat == 2)
            res = 0;
        else
            n->stat = 1;
        n = n->next[s[i] - '0'];
        i++;
    }
    
    res &= (n->stat == 0);
    n->stat = 2;
    if (res)
        return 1;
    return 0;
}

int main() {
    int t, n, res;
    char input[11];
    node* root;

    scanf("%d", &t);
    
    for (int i = 0; i < t; i++) {
        scanf("%d", &n);

        root = create_node();
        res = 1;

        for (int j = 0; j < n; j++) {
            scanf("%s", input);
            res &= add(root, input);
        }

        if (res)
            printf("YES\n");
        else
            printf("NO\n");
    }
}