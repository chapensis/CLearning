#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *swapPairs(struct ListNode *head)
{
    struct ListNode *pre = NULL;
    struct ListNode *move = head;
    while (move != NULL && move->next != NULL)
    {
        if (pre != NULL)
        {
            pre->next = move->next;
        } else {
            head = move -> next;
        }
        struct ListNode *temp = move->next;
        move->next = move->next->next;
        temp->next = move;

        pre = move;
        move = move->next;
    }
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

    // listNode_1.next = &listNode_2;
    // listNode_2.next = &listNode_3;
    // listNode_3.next = &listNode_4;
    print_node(&listNode_1);

    struct ListNode *new_head = swapPairs(&listNode_1);
    print_node(new_head);

    return 0;
}