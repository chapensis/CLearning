#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *find_char(char *str, char *chars)
{
    if (str == NULL || chars == NULL)
    {
        return NULL;
    }
    for (char *ch = str; *ch != '\0'; ch++)
    {
        for (char *ch2 = chars; *ch2 != '\0'; ch2++)
        {
            if (*ch == *ch2)
            {
                return ch;
            }
        }
    }
    return NULL;
}

/**
 * 删除str中的字串substr
 **/
int del_substr(char *str, char const *substr)
{
    for (char *start = str; *start != '\0'; start++)
    {
        int flag = 1;
        char *move = start;
        for (char *submove = substr; *submove != '\0'; submove++)
        {
            if (*move == *submove)
            {
                move++;
            }
            else
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            while (*move != '\0')
            {
                *start = *move;
                move++;
                start++;
            }
            *start = '\0';
            return 1;
        }
    }
    return 0;
}

/**
 * 反转字符串
 **/
void reverse_string(char *str)
{
    char *start = str;
    char *end = start + strlen(str) - 1;
    // 直接进行地址的比较 printf("%d", start) => 打印的是地址,printf("%s", start) => 打印的是字符串
    while (start < end)
    {
        char temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

void helloworld()
{
    printf("hello world! \n");
}

int gcd(int m, int n)
{
    int r = m % n;
    if (r == 0)
    {
        return n;
    }
    else
    {
        return gcd(n, r);
    }
}

/**
 * 字符串转整数
 **/
int ascii_to_integer(char *str)
{
    int result = 0;
    for (char *ch = str; *ch != '\0'; ch++)
    {
        if (*ch < '0' || *ch > '9')
        {
            return 0;
        }
        result = result * 10 + *ch - '0';
    }
    return result;
}

int main()
{
    // char *str = "yangchang";
    // char *chars = "c";
    // char *result = find_char(str, chars);
    // printf("%s \n", result);
    // 这样定义的字符串是存放在常量区的，地址是:2293312 小地址，在数据段
    // char *str = "yangchang";
    char str[] = "yangchang";
    char substr[] = "";
    printf("before delete substr, str is %s \n", str);
    int result = del_substr(str, substr);
    printf("after delete substr, result is %d, str is %s \n", result, str);

    char str2[] = "chen";
    printf("before reverse string, str is %s \n", str2);
    reverse_string(str2);
    printf("after reverse string, str is %s \n", str2);

    helloworld();

    int gcd_result = gcd(16, 12);
    printf("result = %d \n", gcd_result);

    int ascii_to_str = ascii_to_integer("1777345");
    printf("result = %d \n", ascii_to_str);
    return 0;
}
