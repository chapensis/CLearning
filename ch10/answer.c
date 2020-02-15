#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 一个结构体占用内存 24字节
struct NODE
{
    int a;
    struct NODE *b;
    struct NODE *c;
};

void answer_7()
{
    struct NODE nodes[5] =
        {
            {5, nodes + 3, NULL},
            {15, nodes + 4, nodes + 3},
            {22, NULL, nodes + 4},
            {12, nodes + 1, nodes},
            {18, nodes + 2, nodes + 1},
        };
    struct NODE *np = nodes + 2;            // 第三个元素
    struct NODE **npp = &nodes[1].b;        // 第五个元素的地址
    printf("&nodes = %d \n", &nodes);       // 预估：数组首地址2293152   实际： True
    printf("nodes = %d \n", nodes);         // 预估：数组首地址   实际： True
    printf("&nodes[0] = %d \n", &nodes[0]); // 预估：数组首地址   实际： True
    // printf("nodes.a = %d \n", nodes.a);                 // 预估：错误   实际：
    printf("nodes[3].a = %d \n", nodes[3].a);           // 预估：12   实际：True
    printf("nodes[3].c = %d \n", nodes[3].c);           // 预估：数组首地址   实际：True
    printf("nodes[3].c -> a = %d \n", nodes[3].c->a);   // 预估：5   实际：True
    printf("*nodes = %d \n", *nodes);                   // 预估：数组首地址   实际：数组首地址 - 48 ????
    printf("(*nodes).a = %d \n", (*nodes).a);           // 预估：5   实际：True
    printf("nodes -> a = %d \n", nodes->a);             // 预估：5   实际：True
    printf("nodes[3].b -> b = %d \n", nodes[3].b->b);   // 预估：数组首地址 + 96   实际：True
    printf("*nodes[3].b -> b = %d \n", *nodes[3].b->b); // 预估：18   实际：数组首地址 - 48 ????
    printf("&nodes = %d \n", &nodes);                   // 预估：数组首地址   实际：True
    printf("&nodes[3].a = %d \n", &nodes[3].a);         // 预估：数组首地址 + 72   实际：True
    printf("&nodes[3].c = %d \n", &nodes[3].c);         // 预估：数组首地址   实际：数组首地址 + 88 ???
    printf("&nodes[3].c -> a = %d \n", &nodes[3].c->a); // 预估：数组首地址   实际：True
    printf("&nodes -> a = %d \n", &nodes->a);           // 预估：数组首地址   实际：True
    printf("np = %d \n", np);                           // 预估：数组首地址 + 48   实际：True
    printf("*np = %d \n", *np);                         // 预估：数组首地址 + 48   实际：True
    printf("np -> a = %d \n", np->a);                   // 预估：22   实际：True
    printf("np -> c -> c -> a = %d \n", np->c->c->a);   // 预估：15   实际：True
    printf("npp = %d \n", npp);                         // 预估：第五个元素   实际：数组首地址 + 32 ???
    // printf("npp -> a = %d \n", npp->a);                 // 预估：18   实际：
    printf("*npp = %d \n", *npp); // 预估：数组首地址 + 96   实际：True
    // printf("*npp -> a = %d \n", *npp->a);               // 预估：10   实际：
    printf("(*npp) -> a = %d \n", (*npp)->a);           // 预估：18   实际：True
    printf("&np = %d \n", &np);                         // 预估：指针地址   实际：True
    printf("&np -> a = %d \n", &np->a);                 // 预估：数组首地址 + 48   实际：True
    printf("&np -> c -> c -> a = %d \n", &np->c->c->a); // 预估：数组首地址 + 24   实际：True
}

int main()
{
    answer_7();

    printf("====================================== \n");
    // 结构体的地址、结构体的首元素地址是相同的，结构体的是单独的
    struct NODE node = {5, NULL, NULL};
    struct NODE *p = &node;
    printf("node = %d \n", node);
    printf("&node.a = %d \n", &(node.a));
    printf("&node = %d \n", &node);

    printf("====================================== \n");
    // 整型指针、整数地址是相同的  整型指针的地址是单独的
    int a = 10;
    int *ip = &a;
    printf("&a = %d \n", &a);
    printf("a = %d \n", a);
    printf("ip = %d \n", ip);
    printf("&ip = %d \n", &ip);
    printf("*ip = %d \n", *ip);

    printf("====================================== \n");
    // 数组、数组地址、数组首元素地址  是相同的
    int array[] = {1, 2, 3, 4, 5};
    printf("&array = %d \n", &array);
    printf("array = %d \n", array);
    printf("&array[0] = %d \n", &array[0]);

    return 0;
}