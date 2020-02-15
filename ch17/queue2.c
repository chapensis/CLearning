#include "queue.h"
#include <stdio.h>
#include <assert.h>

typedef struct QUEUE_NODE
{
    int value;
    struct QUEUE_NODE *next;
} QUEUE_NODE;

static QUEUE_NODE *front = NULL;
static QUEUE_NODE *rear = NULL;

/**
 * 创建一个队列，参数指定队列可以存储的元素的最大数量
 * 注意：这个函数只适用于使用动态分配数组的队列
 **/
void create_queue(int size)
{
    printf("create linked queue success!!! \n");
}

/**
 * 销毁一个队列，注意：这个函数只适用于使用动态分配数组的队列
 **/
void destroy_queue(void)
{
    while (front != NULL)
    {
        delete ();
    }
    printf("destroy linked queue success!!! \n");
}

/**
 * 向队列中添加一个新元素，参数就是需要添加的元素
 **/
void insert(QUEUE_TYPE value)
{
    assert(!is_full());
    QUEUE_NODE *new_node = malloc(sizeof(QUEUE_NODE));
    new_node->value = value;
    new_node->next = NULL;

    if (rear != NULL)
    {
        rear->next = new_node;
    }
    rear = new_node;
    if (front == NULL)
    {
        front = new_node;
    }
}

/**
 * 从队列中移除一个元素并将其丢弃
 **/
QUEUE_TYPE delete ()
{
    assert(!is_empty());
    QUEUE_NODE *temp = front;
    if (front == rear)
    {
        rear = NULL;
    }
    front = front->next;
    int value = temp->value;
    free(temp);
    return value;
}

/**
 * 返回队列中的第一个元素，但不修改队列本身
 **/
QUEUE_TYPE first(void)
{
    assert(!is_empty());
    return front->value;
}

/**
 * 如果队列为空，返回True,否则返回False
 * 空一格不用的效果就是：差一个就是空了
 **/
int is_empty(void)
{
    return front == NULL;
}

/**
 * 如果队列已满，返回True,否则返回False
 * 空一格不用的效果就是：差二个就是满了
 **/
int is_full(void)
{
    return 0;
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
        printf("%d ", delete ());
    }
    printf("\n");
    destroy_queue();
}
