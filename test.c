#include <stdio.h>
#include <string.h>
int a = 15; // 静态内存
void changArray(int arr[])
{
    static int b = 10; // 静态内存，因为有static关键字
    arr[0] = 1;
}

void test_1()
{
    int arr[3] = {0, 1, 2};
    printf("What is your name???\n");
    printf("%d\n", arr[0]);
    changArray(arr);
    printf("%d\n", arr[0]);
    char str1[7] = {'i', 'l', 'o', 'v', 'e', 'u', '\0'};
    printf("str1: %s\n", str1);
    printf("str1 length is %d \n", strlen(str1));

    char str2[] = {'u', 'l', 'o', 'v', 'e', 'm', '2', '\0'};
    printf("str2: %s\n", str2);
    printf("str2 length is %d \n", strlen(str2));

    strcat(str1, str2);
    printf("str1: %s\n", str1);
    printf("str1 length is %d \n", strlen(str1));

    //使用第一种方式初始化方式声明并初始化二维数组arr1,二位数组必须指定数组大小，但是可以不指定行数，但必须指定列数
    int arr1[][2] = {{10}, {30, 40}}; // 因为我不瞎，有多少行我能看出来，但是我他么不知道你有多少列，是否大于2啊
    //使用第二种方式初始化方式声明并初始化二维数组arr2
    int arr2[2][2];
    arr2[0][0] = 10;
    arr2[0][1] = 20;
    arr2[1][0] = 30;
    arr2[1][1] = 40;
    char name[20];
    scanf("%s", name);
    printf("Hello,%s,nice to meet you!\n", name);
}

void test_2()
{
    puts("hello world");
    puts("yangchang");
    printf("%d \n", __INT_MAX__);
    printf("%d \n", 1 << 16);
    printf("%d \n", 0173);
    printf("%d \n", 0x173);
    int my;
    printf("%d \n", my);
}

int main()
{
    int a = 1;
    int b = 2;
    // sizeof并不会对表达式求值
    int c = sizeof(a = b + 1 + 1 + 1 + 1);
    printf("sizeof c is %d \n", c);
    printf("%d \n", a);
    return 0;
}