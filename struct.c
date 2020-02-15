#include<stdio.h>
// 当前结构体占16个字节
struct weapon {
    int price; // 整形占四字节
    int atk;   // 整形占四字节
    struct weapon next; // 指针占8字节，64位系统 如果不是指针则报错error: field 'next' has incomplete type
};

int main() {
    printf("hello world");
    return 0;
}