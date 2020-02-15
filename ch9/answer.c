#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * 查找the单词出现的次数
 **/ 
int count_the(char str[])
{
    int count = 0;
    char *result = strstr(str, "the");
    while (result != NULL)
    {
        count += 1;
        str = result + 3;
        printf("%s \n", str);
        result = strstr(str, "the");
    }
    return count;
}

int main()
{
    char str[] = "chahgnnsthehayuTHE the sa ew dsa sadwqr";
    int result = count_the(str);
    printf("the num is %d \n", result);
    // 传进去的是一个副本，所以原始的str指向的位置没有变，还是可以回收啥的
    printf("the str is %s \n", str);
    return 0;
}