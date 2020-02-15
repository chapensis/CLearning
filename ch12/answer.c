#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

/**
 * 我最习惯的单向链表插入方式
 **/
Node *my_insert(Node *root, int value)
{
    Node *pre = NULL;
    Node *current = root;
    while (current != NULL && current->value < value)
    {
        pre = current;
        current = current->next;
    }

    Node *new_node = malloc(sizeof(Node));
    // 说明内存不足了
    if (new_node == NULL)
    {
        return 0;
    }
    new_node->value = value;
    new_node->next = current;

    // 没有前序节点，说明插入值就是第一个节点位置
    if (pre == NULL)
    {
        // 因为new_node已经是一个指针了，所以直接返回new_node即可
        return new_node;
    }
    pre->next = new_node;
    return root;
}

/**
 * 传递指针的地址实现单向链表插入
 **/
int insert_1(Node **p, int value)
{
    Node *pre = NULL;
    Node *current = *p;
    while (current != NULL && current->value < value)
    {
        pre = current;
        current = current->next;
    }

    Node *new_node = malloc(sizeof(Node));
    // 说明内存不足了
    if (new_node == NULL)
    {
        return 0;
    }
    new_node->value = value;
    new_node->next = current;

    // 没有前序节点，说明插入值就是第一个节点位置
    if (pre == NULL)
    {
        // new_node是第一个值，所以root指向新的头结点
        *p = new_node;
    }
    else
    {
        pre->next = new_node;
    }
    return 1;
}

int insert_2(Node **linkp, int value)
{
    Node *current = NULL;
    while ((current = *linkp) != NULL && current->value < value)
    {
        linkp = &current->next;
    }

    Node *new_node = malloc(sizeof(Node));
    // 说明内存不足了
    if (new_node == NULL)
    {
        return 0;
    }
    new_node->value = value;
    new_node->next = current;
    // ??? 没看懂
    *linkp = new_node;
    return 1;
}

/**
 * 打印所有node节点
 * 每次传值，内存消耗大，所以传地址最好
 **/
void print_node(Node *root)
{
    while (root != NULL)
    {
        printf("%d ", root->value);
        root = root->next;
    }
    printf("\n");
}

void test(int **cp) {
    printf("cp = %d \n", cp);
    printf("&cp = %d \n", &cp);
    printf("*cp = %d \n", *cp);
    printf("**cp = %d \n", **cp);
}

int main()
{
    Node node_1 = {1, NULL};
    Node node_3 = {3, NULL};
    Node node_5 = {5, NULL};
    Node node_7 = {7, NULL};
    Node node_9 = {9, NULL};
    node_1.next = &node_3;
    node_3.next = &node_5;
    node_5.next = &node_7;
    node_7.next = &node_9;

    // printf("=========before insert========== \n");
    // print_node(&node_1);

    // Node *new_nodes = my_insert(&node_1, 4);

    // printf("==========after insert========== \n");
    // print_node(new_nodes);

    printf("=========before insert2========== \n");
    print_node(&node_1);

    Node *p = &node_1;
    int result = insert_2(&p, 2);

    printf("==========after insert2========== \n");
    print_node(p);

    // int a = 10;
    // printf("&a = %d \n", &a);
    // int *ip = &a;
    // test(&ip);

    return 0;
}