#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int func()
{
    static int counter = 1;
    return ++counter;
}

void answer_7()
{
    int a = 20;
    // 先计算 11 <= a 是true,即结果是1，然后再计算 1<= 10也是true,即结果是1
    if (11 <= a <= 10)
    {
        printf("in range \n");
    }
    else
    {
        printf("out of range \n");
    }
}

void answer_8()
{
    int a = 2;
    int b = 3;
    int c = 4;
    int d = 5;
    // int e = a = b = c = d;
    // printf("%d \n", a);
    // printf("%d \n", b);
    // printf("%d \n", c);
    // printf("%d \n", d);
    // printf("%d \n", e);

    // 中途的赋值，会改变其他地方的值
    // int e = d + (c = a + b) + c;

    // 判断符会有1
    int e = (a != b != c);
    printf("%d \n", e);

    // 单个=符号，其实就是先赋值，然后判断a的值
    if (a = 0)
    {
        printf("yes \n");
    }
    else
    {
        printf("no \n");
    }
}

void practice_1()
{
    int ch;
    while ((ch = getchar()) != EOF)
    {
        if (ch >= 'a' && ch <= 'z')
        {
            printf("char is %c \n", ch);
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            printf("lower char is %c \n", ch + 32);
        }
        // 其他的字符，例如：回车，就会被忽略
    }
}

int encrypt(int ch, int base)
{
    ch -= base;
    ch += 13;
    ch %= 26;
    return ch + base;
}

int encrypt2(int ch, int max)
{
    if (ch + 13 > max)
    {
        return ch - 13;
    }
    else
    {
        return ch + 13;
    }
}

/*
** 第二个练习
*/
void practice_2()
{
    int ch;
    while ((ch = getchar()) != EOF)
    {
        int result1 = ch;
        int result2 = ch;
        if (ch >= 'A' && ch <= 'Z')
        {
            result1 = encrypt(ch, 'A');
            result2 = encrypt2(ch, 'Z');
        }
        else if (ch >= 'a' && ch <= 'z')
        {
            result1 = encrypt(ch, 'a');
            result2 = encrypt2(ch, 'z');
        }
        putchar(result1);
        putchar(result2);
    }
}

int main()
{
    int answer;
    // 先按照顺序计算函数的结果，再计算表达式的值
    answer = func() - func() * func();
    printf("answer %d \n", answer);

    answer_7();
    answer_8();
    // printf("%d \n", 'A');
    // printf("%d \n", 'a');
    // practice_1();
    practice_2();
    return 0;
}