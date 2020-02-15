#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int value;
    struct Node *pre;
    struct Node *next;
} Node;

/**
 * 把一个值插入到一个双链表，root是一个指向根节点的指针，
 * value是欲插入的新值
 * 返回值：如果欲插入值原先已经存在于链表，函数返回0
 * 如果内存不足导致无法插入，函数返回-1，如果插入成功，函数返回1
 **/
int ddl_insert(Node *root, int value)
{
    Node *this;
    Node *next;
    Node *new_node;
    for (this = root; (next = this->next) != NULL; this = next)
    {
        if (next->value == value)
        {
            return 0;
        }
        if (next->value > value)
        {
            break;
        }
    }
    new_node = malloc(sizeof(Node));
    if (new_node == NULL)
    {
        return -1;
    }
    new_node->value = value;

    /**
     * 把新值添加到链表中
    **/
    new_node->next = next;
    this->next = new_node;

    if (this != root)
    {
        new_node->pre = this;
    }
    else
    {
        new_node->pre = NULL;
    }

    if (next != NULL)
    { // 如果不是插入在最后
        next->pre = new_node;
    }
    else
    { // 如果插入是在最后
        root->pre = new_node;
    }

    // if (next != NULL)
    // {
    //     if (this != root)
    //     { // 并非位于链表起始位置
    //         new_node->next = next;
    //         this->next = new_node;
    //         new_node->pre = this;
    //         next->pre = new_node;
    //     }
    //     else
    //     { // 位于链表起始位置
    //         new_node->next = next;
    //         root->next = new_node;
    //         new_node->pre = NULL;
    //         next->pre = new_node;
    //     }
    // }
    // else
    // {
    //     if (this != root)
    //     { // 并非位于链表起始位置
    //         new_node->next = NULL;
    //         this->next = new_node;
    //         new_node->pre = this;
    //         root->pre = new_node;
    //     }
    //     else
    //     { // 位于链表起始位置，循环链表
    //         new_node->next = NULL;
    //         root->next = new_node;
    //         new_node->pre = NULL;
    //         root->pre = new_node;
    //     }
    // }
    return 1;
}

/**
 * 打印所有node节点
 * 每次传值，内存消耗大，所以传地址最好
 **/
void print_dll_node(Node *root)
{
    Node *tail = NULL;
    while (root != NULL)
    {
        tail = root;
        printf("%d ", root->value);
        root = root->next;
    }
    printf("\n");

    while (tail != NULL)
    {
        printf("%d ", tail->value);
        tail = tail->pre;
    }
    printf("\n");
}

int main()
{
    Node node_1 = {1, NULL, NULL};
    Node node_3 = {3, NULL, NULL};
    Node node_5 = {5, NULL, NULL};
    Node node_7 = {7, NULL, NULL};
    Node node_9 = {9, NULL, NULL};
    node_1.next = &node_3;
    node_3.pre = &node_1;
    node_3.next = &node_5;
    node_5.pre = &node_3;
    node_5.next = &node_7;
    node_7.pre = &node_5;
    node_7.next = &node_9;
    node_9.pre = &node_7;

    printf("=========before ddl_insert========== \n");
    print_dll_node(&node_1);

    int result = ddl_insert(&node_1, 4);
    printf("==========after ddl_insert========== \n");
    print_dll_node(&node_1);

    return 0;
}