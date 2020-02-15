#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *rotateRight(struct ListNode *head, int k)
{
    if (head == NULL || k == 0)
    {
        return head;
    }
    int length = 0;
    struct ListNode *move = head;
    while (move != NULL)
    {
        length += 1;
        move = move->next;
    }
    k = k % length;
    if (k == 0)
    {
        return 0;
    }
    struct ListNode *tail = head;
    struct ListNode *new_tail = head;
    for (int i = 0; i < k; i++)
    {
        tail = tail->next;
    }
    for (int j = 0; j < (length - k - 1); j++)
    {
        new_tail = new_tail->next;
        tail = tail->next;
    }
    tail->next = head;
    head = new_tail->next;
    new_tail->next = NULL;

    return head;
}

/**
 * 打印所有node节点
 * 每次传值，内存消耗大，所以传地址最好
 **/
void print_node(struct ListNode *root)
{
    while (root != NULL)
    {
        printf("%d ", root->val);
        root = root->next;
    }
    printf("\n");
}

int main()
{
    struct ListNode listNode_1 = {1, NULL};
    struct ListNode listNode_2 = {2, NULL};
    struct ListNode listNode_3 = {3, NULL};
    struct ListNode listNode_4 = {4, NULL};

    listNode_1.next = &listNode_2;
    listNode_2.next = &listNode_3;
    listNode_3.next = &listNode_4;
    print_node(&listNode_1);

    struct ListNode *new_head = rotateRight(&listNode_1, 2);
    print_node(new_head);
    return 0;
}