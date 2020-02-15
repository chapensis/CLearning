#include "queue.h"
#include <stdio.h>
#include <assert.h>

#define QUEUE_SIZE 100              // 队列中元素的最大数量
#define ARRAY_SIZE (QUEUE_SIZE + 1) // 数组的长度

static QUEUE_TYPE queue[ARRAY_SIZE];
static int front = 1;
static int rear = 0;

/**
 * 创建一个队列，参数指定队列可以存储的元素的最大数量
 * 注意：这个函数只适用于使用动态分配数组的队列
 **/
void create_queue(int size)
{
    printf("create array queue success!!! \n");
}

/**
 * 销毁一个队列，注意：这个函数只适用于使用动态分配数组的队列
 **/
void destroy_queue(void)
{
    printf("destroy array queue success!!! \n");
}

/**
 * 向队列中添加一个新元素，参数就是需要添加的元素
 **/
void insert(QUEUE_TYPE value)
{
    assert(!is_full());
    rear = (rear + 1) % ARRAY_SIZE;
    queue[rear] = value;
}

/**
 * 从队列中移除一个元素并将其丢弃
 **/
QUEUE_TYPE delete()
{
    assert(!is_empty());
    QUEUE_TYPE temp = queue[front];
    front = (front + 1) % ARRAY_SIZE;
    return temp;
}

/**
 * 返回队列中的第一个元素，但不修改队列本身
 **/
QUEUE_TYPE first(void)
{
    assert(!is_empty());
    return queue[front];
}

/**
 * 如果队列为空，返回True,否则返回False
 * 空一格不用的效果就是：差一个就是空了
 **/
int is_empty(void)
{
    return (rear + 1) % ARRAY_SIZE == front;
}

/**
 * 如果队列已满，返回True,否则返回False
 * 空一格不用的效果就是：差二个就是满了
 **/
int is_full(void)
{
    return (rear + 2) % ARRAY_SIZE == front;
}

int main()
{
    int size = 100;
    create_queue(size);
    for (int i = 1; i <= size; i++)
    {
        insert(i);
    }

    for (int j = 0; j < size; j++)
    {
        printf("%d ", delete());
    }
    printf("\n");
    destroy_queue();
}
