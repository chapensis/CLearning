#include<stdio.h>
#include<malloc.h>
// 当前结构体占16个字节
struct weapon {
    int price; // 整形占四字节
    int atk;   // 整形占四字节
    struct weapon *next; // 指针占8字节，64位系统 如果不是指针则报错error: field 'next' has incomplete type
};

/**
 * 测试静态链表
 **/
void test_static_link() {
    printf("========test static link=========\n");
    // 一次性定义了三个结构体,一旦定义，则内存已经分配好
    struct weapon a,b,c, *head;
    a.price = 100;
    a.atk = 100;
    b.price = 200;
    b.atk = 200;
    c.price = 300;
    c.atk = 300;

    head = &a;
    a.next = &b;
    b.next = &c;
    c.next = NULL;

    struct weapon *p;
    p = head;
    while (p != NULL)
    {
        printf("current weapon price is %d, atk is %d \n", p->price, p->atk);
        p = p->next;
        // p++; 由于结构体并不一定顺序排列，所以p++并不一定就是下一个weapon地址
    }
    printf("address a: %d\n", &a);
    printf("address b: %d\n", &b);
    printf("address c: %d\n", &c);
}

/**
 * 动态创建链表方法
 **/
struct weapon *create() {
    struct weapon *head;
    struct weapon *new_weapon, *tail;
    int n = 0;
    new_weapon = tail = (struct weapon*)malloc(sizeof(struct weapon));
    scanf("%d,%d", &new_weapon->price, &new_weapon->atk);
    head = NULL;
    while (new_weapon -> price != 0) {
        n++;
        if (n == 1) {
            head = new_weapon;
        } else {
            tail->next = new_weapon;
        }
        tail = new_weapon;
        new_weapon = (struct weapon*)malloc(sizeof(struct weapon));
        scanf("%d,%d", &new_weapon->price, &new_weapon->atk);
    }
    // 必须手动初始化为null
    tail->next = NULL;
    return head;
};


/**
 * 测试动态链表
 **/ 
void test_dynamic_link() {
    printf("========test dynamic link=========\n");
    struct weapon *p;
    p = create();
    while (p != NULL) {
        printf("current weapon price is %d, atk is %d \n", p->price, p->atk);
        p = p->next;
    }
}

int main() {
    test_static_link();
    test_dynamic_link();
    return 0;
}