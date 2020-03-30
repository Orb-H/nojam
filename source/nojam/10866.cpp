#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef struct _node
{
    int x;
    struct _node *prev;
    struct _node *next;
} node;

typedef struct _deque
{
    node *head;
    node *tail;
    int size;
} deque;

void push_front(deque *q, int x)
{
    node *n = (node *)malloc(sizeof(node));
    n->x = x;
    n->prev = NULL;
    n->next = q->head;
    if (q->head != NULL)
        q->head->prev = n;
    else
        q->tail = n;
    q->head = n;
    q->size++;
}

void push_back(deque *q, int x)
{
    node *n = (node *)malloc(sizeof(node));
    n->x = x;
    n->prev = q->tail;
    n->next = NULL;
    if (q->tail != NULL)
        q->tail->next = n;
    else
        q->head = n;
    q->tail = n;
    q->size++;
}

int pop_front(deque *q)
{
    if (q->head == NULL)
        return -1;
    int r = q->head->x;
    q->head = q->head->next;
    if (q->head != NULL)
        q->head->prev = NULL;
    else
        q->tail = NULL;
    q->size--;
    return r;
}

int pop_back(deque *q)
{
    if (q->tail == NULL)
        return -1;
    int r = q->tail->x;
    q->tail = q->tail->prev;
    if (q->tail != NULL)
        q->tail->next = NULL;
    else
        q->head = NULL;
    q->size--;
    return r;
}

int size(deque *q)
{
    return q->size;
}

int empty(deque *q)
{
    return q->size == 0;
}

int front(deque *q)
{
    if (q->head == NULL)
        return -1;
    return q->head->x;
}

int back(deque *q)
{
    if (q->tail == NULL)
        return -1;
    return q->tail->x;
}

int main()
{
    int n;
    char c[10];
    int x;
    deque *q = (deque *)malloc(sizeof(deque));
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", c);
        if (strcmp(c, "push_front") == 0)
        {
            scanf("%d", &x);
            push_front(q, x);
        }
        if (strcmp(c, "push_back") == 0)
        {
            scanf("%d", &x);
            push_back(q, x);
        }
        else if (strcmp(c, "pop_front") == 0)
            printf("%d\n", pop_front(q));
        else if (strcmp(c, "pop_back") == 0)
            printf("%d\n", pop_back(q));
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