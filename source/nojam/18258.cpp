#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef struct _node
{
    int x;
    struct _node *next;
} node;

typedef struct _queue
{
    node *head;
    node *tail;
    int size;
} queue;

void push(queue *q, int x)
{
    node *n = (node *)malloc(sizeof(node));
    n->x = x;
    n->next = NULL;
    if (q->tail != NULL)
        q->tail->next = n;
    else
        q->head = n;
    q->tail = n;
    q->size++;
}

int pop(queue *q)
{
    if (q->head == NULL)
        return -1;
    int r = q->head->x;
    q->head = q->head->next;
    q->size--;
    if (q->size == 0)
        q->tail = NULL;
    return r;
}

int size(queue *q)
{
    return q->size;
}

int empty(queue *q)
{
    return q->size == 0;
}

int front(queue *q)
{
    if (q->head == NULL)
        return -1;
    return q->head->x;
}

int back(queue *q)
{
    if (q->tail == NULL)
        return -1;
    return q->tail->x;
}

int main()
{
    int n;
    char c[5];
    int x;
    queue *q = (queue *)malloc(sizeof(queue));
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", c);
        if (strcmp(c, "push") == 0)
        {
            scanf("%d", &x);
            push(q, x);
        }
        else if (strcmp(c, "pop") == 0)
            printf("%d\n", pop(q));
        else if (strcmp(c, "size") == 0)
            printf("%d\n", size(q));
        else if (strcmp(c, "empty") == 0)
            printf("%d\n", empty(q));
        else if (strcmp(c, "front") == 0)
            printf("%d\n", front(q));
        else if (strcmp(c, "back") == 0)
            printf("%d\n", back(q));
    }
}