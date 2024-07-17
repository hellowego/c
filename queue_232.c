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

MyQueue *myQueueCreate()
{
    MyQueue *ret = malloc(sizeof(MyQueue));
    ret->inStack = stackCreate(100);
    ret->outStack = stackCreate(100);
    return ret;
}

void in2out(MyQueue *obj)
{
    while (!stackEmpty(obj->inStack))
    {
        stackPush(obj->outStack, stackTop(obj->inStack));
        stackPop(obj->inStack);
    }
}

void myQueuePush(MyQueue *obj, int x)
{
    stackPush(obj->inStack, x);
}

int myQueuePop(MyQueue *obj)
{
    if (stackEmpty(obj->outStack))
    {
        in2out(obj);
    }
    int x = stackTop(obj->outStack);
    stackPop(obj->outStack);
    return x;
}

int myQueuePeek(MyQueue *obj)
{
    if (stackEmpty(obj->outStack))
    {
        in2out(obj);
    }
    return stackTop(obj->outStack);
}

bool myQueueEmpty(MyQueue *obj)
{
    return stackEmpty(obj->inStack) && stackEmpty(obj->outStack);
}

void myQueueFree(MyQueue *obj)
{
    stackFree(obj->inStack);
    stackFree(obj->outStack);
}

int main()
{
    MyQueue *obj = myQueueCreate();
    myQueuePush(obj, 1);
    myQueuePush(obj, 2);
    myQueuePush(obj, 3);
    myQueuePush(obj, 4);
    myQueuePush(obj, 5);
    int v1 = myQueuePop(obj);
    int v2 = myQueuePeek(obj);

    printf("hello world");
    return 0;
}