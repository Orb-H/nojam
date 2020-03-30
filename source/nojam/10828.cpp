#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef struct _node
{
    int x;
    struct _node *next;
} node;

typedef struct _stack
{
    node *top;
    int size;
} stack;

void push(stack *s, int x)
{
    node *n = (node *)malloc(sizeof(node));
    n->x = x;
    n->next = s->top;
    s->top = n;
    s->size++;
}

int pop(stack *s)
{
    if (s->top == NULL)
        return -1;
    int r = s->top->x;
    s->top = s->top->next;
    s->size--;
    return r;
}

int size(stack *s)
{
    return s->size;
}

int empty(stack *s)
{
    return s->size == 0;
}

int top(stack *s)
{
    if (s->top == NULL)
        return -1;
    return s->top->x;
}

int main()
{
    int n;
    char c[5];
    int x;
    stack *s = (stack *)malloc(sizeof(stack));
    s->top = NULL;
    s->size = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", c);
        if (strcmp(c, "push") == 0)
        {
            scanf("%d", &x);
            push(s, x);
        }
        else if (strcmp(c, "pop") == 0)
            printf("%d\n", pop(s));
        else if (strcmp(c, "size") == 0)
            printf("%d\n", size(s));
        else if (strcmp(c, "empty") == 0)
            printf("%d\n", empty(s));
        else if (strcmp(c, "top") == 0)
            printf("%d\n", top(s));
    }
}