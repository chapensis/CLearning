#include "stack.h"
#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#define STACK_SIZE 100 // 堆栈中值数量的最大限制

typedef struct STACK_NODE
{
    int value;
    struct STACK_NODE *next;
} STACK_NODE;

/**
 * 指向堆栈中第一个节点的指针
 **/
static STACK_NODE *stack = NULL;

/**
 * 创建堆栈，参数指定堆栈可以保存多少个元素
 * 注意：这个函数并不用于静态数组版本的堆栈
 **/
void create_stack(int stack_size)
{
    printf("create linked stack success!!! \n");
}

/**
 * 销毁堆栈，他释放独占所使用的内存
 * 注意：这个函数也不用于静态数组版本的堆栈
 **/
void destroy_stack(void)
{
    while (!is_empty())
    {
        pop();
    }
    printf("destroy linked stack success!!! \n");
}

/**
 * 将一个新值压入到堆栈中，他的参数是需要被压入的值
 **/
void push(STACK_TYPE value)
{
    STACK_NODE *new_node = malloc(sizeof(STACK_NODE));
    new_node->value = value;
    new_node->next = stack;
    stack = new_node;
}

/**
 * 从堆栈中弹出一个元素
 **/
STACK_TYPE pop(void)
{
    assert(!is_empty(stack));
    STACK_TYPE value = stack->value;
    STACK_NODE *temp = stack;
    stack = stack->next;
    free(temp);
    return value;
}

/**
 * 返回堆栈顶部元素的值，但不对堆栈进行修改
 **/
STACK_TYPE top(void)
{
    assert(!is_empty(stack));
    return stack->value;
}

/**
 * 如果堆栈为空，返回True,否则返回false
 **/
int is_empty()
{
    return stack == NULL;
}

/**
 * 如果堆栈已满，返回True,否则返回false
 **/
int is_full()
{
    return -1;
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
