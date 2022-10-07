#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int *elem;
    unsigned size;
    int top;
};
typedef struct stack stk;
int isFull(stk *s)
{
    return s->top == s->size - 1;
}

int isEmpty(stk *s)
{
    return s->top == -1;
}

stk *initStack(unsigned size)
{
    stk *s = (stk *)malloc(sizeof(stk));
    s->size = size;
    s->top = -1;
    s->elem = (int *)malloc(s->size * sizeof(int));
    return s;
}

int pop(stk *s)
{
    if (isEmpty(s))
        return -1;
    s->top--;
    return s->elem[s->top + 1];
}

void push(stk *s, int val)
{
    if (isFull(s))
        return;
    s->top++;
    s->elem[s->top] = val;
}

int peek(stk *s)
{
    return s->elem[s->top];
}

int count(stk *s)
{
    return s->top + 1;
}

void printStack(stk *s)
{
    if (isEmpty(s))
    {
        printf("\nStack Empty");
    }
    else
    {
        printf("\n");
        for (int i = s->top; i >= 0; i--)
        {
            printf("%d ", s->elem[i]);
        }
    }
}

void deleteStack(stk *s)
{
    free(s);
}

int main()
{
    int n = 10;
    stk *s = initStack(n);

    deleteStack(s);
}