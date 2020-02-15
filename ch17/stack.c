#include "stack.h"
#include <stdio.h>
#include <assert.h>
#include <malloc.h>
// #define STACK_SIZE 100 // 堆栈中值数量的最大限制

/**
 * 存储堆栈中值的数组和一个指向堆栈顶部元素的指针
 **/
// static STACK_TYPE stack[STACK_SIZE]; // 静态数组
static STACK_TYPE *stack;
static int stack_size = 0;
static int top_elemment = -1;

/**
 * 创建堆栈，参数指定堆栈可以保存多少个元素
 * 注意：这个函数并不用于静态数组版本的堆栈
 **/
void create_stack(int size)
{
    assert(size > 0);
    stack_size = size;
    stack = malloc(size * sizeof(STACK_TYPE));
    assert(stack != NULL);
    printf("create stack success!!! \n");
}

/**
 * 销毁堆栈，他释放独占所使用的内存
 * 注意：这个函数也不用于静态数组版本的堆栈
 **/
void destroy_stack(void)
{
    assert(stack_size > 0);
    stack_size = 0;
    free(stack);
    printf("destroy stack success!!! \n");
}

/**
 * 将一个新值压入到堆栈中，他的参数是需要被压入的值
 **/
void push(STACK_TYPE value)
{
    assert(!is_full(stack));
    assert(stack_size > 0);
    stack[++top_elemment] = value;
}

/**
 * 从堆栈中弹出一个元素
 **/
STACK_TYPE pop(void)
{
    assert(!is_empty(stack));
    return stack[top_elemment--];
}

/**
 * 返回堆栈顶部元素的值，但不对堆栈进行修改
 **/
STACK_TYPE top(void)
{
    assert(!is_empty(stack));
    return stack[top_elemment];
}

/**
 * 如果堆栈为空，返回True,否则返回false
 **/
int is_empty()
{
    return top_elemment == -1;
}

/**
 * 如果堆栈已满，返回True,否则返回false
 **/
int is_full()
{
    return top_elemment == stack_size - 1;
}

int main()
{
    int size = 100;
    create_stack(size);
    for (int i = 1; i <= size; i++)
    {
        push(i);
    }

    for (int j = 0; j < size; j++)
    {
        printf("%d ", pop());
    }
    printf("\n");
    destroy_stack();
}
