#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    int *stk;
    int stkSize;
    int stkCapacity;
    /* data */
} Stack;

Stack *stackCreate(int capacity)
{
    int size_s = sizeof(Stack);
    Stack *ret = malloc(size_s);
    ret->stk = malloc(sizeof(int) * capacity);
    ret->stkSize = 0;
    ret->stkCapacity = capacity;
    return ret;
}
void stackPush(Stack *obj, int x)
{
    obj->stk[obj->stkSize++] = x;
}
void stackPop(Stack *obj)
{
    obj->stkSize--;
}
int stackTop(Stack *obj)
{
    return obj->stk[obj->stkSize - 1];
}
bool stackEmpty(Stack *obj)
{
    return obj->stkSize == 0;
}
void stackFree(Stack *obj)
{
    free(obj->stk);
}

typedef struct
{
    Stack *inStack;
    Stack *outStack;
} MyQueue;

MyQuene *myQueneCreate()
{
    MyQueue *ret = malloc(sizeof(MyQueue));
    ret->inStack = stackCreate(100);
    ret->outStack = stackCreate(100);
    return ret;
}

int main()
{
    printf("hello world");
    return 0;
}