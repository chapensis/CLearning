#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUL '\0'
#define false 0
#define true 1
#define bool int

int is_white(int ch);
void prime(int n);
bool is_prime(int n);

void deblank(char *string)
{
    char *dest;
    char *src;
    int ch;
    /*
    ** Set source and destination pointers to beginning of the string, then
    ** move to 2nd character in string.
    */
    src = string;
    dest = string;
    /*
    ** Examine each character from the source string.
    */
    while ((ch = *src++) != NUL)
    {
        if (!is_white(ch))
        {
            /*
            ** Not white space: just store it.
            */
            *dest++ = ch;
        }
    }
    *dest = NUL;
}

int is_white(int ch)
{
    return ch == ' ' || ch == '\t' || ch == '\v' || ch == '\f' || ch == '\n' || ch == '\r';
}

void deblank2(char string[])
{
    int len = strlen(string);
    for (int i = 0; i < len; i++)
    {
        if (string[i] == ' ')
        {
            for (int j = i; j < len; j++)
            {
                string[j] = string[j + 1];
            }
            len--;
        }
    }
}

/**
 * 输出1-n之间的所有质数
 **/
void prime(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (is_prime(i))
        {
            printf("%d \n", i);
        }
    }
}

/**
 * 判断给定的数是不是质数
 **/
bool is_prime(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

void triangle(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        printf("This is a illgeal triangle!!!\n");
        return;
    }
    if (a + b <= c || a + c <= b || b + c <= a)
    {
        printf("This is a illgeal triangle!!!\n");
        return;
    }
    if (a == b && b == c)
    {
        printf("This is a equilateral triangle!!!\n");
        return;
    }
    if (a == b || b == c || a == c)
    {
        printf("This is a isosceles triangle!!!\n");
        return;
    }
}

void copy_n(char dst[], char src[], int n)
{
    int index_d = 0;
    int index_s = 0;
    while (index_d < n)
    {
        dst[index_d] = src[index_s];
        if (src[index_s] != '\0')
        {
            index_s++;
        }
        index_d++;
    }
}

void print_array(char array[], int n)
{
    int index = 0;
    while (index < n)
    {
        printf("%c ", array[index]);
        index++;
    }
    printf("\n");
}

void print_repeated_line()
{
    char str[128];
    char input[128];
    bool is_print = false;
    while (gets(input) != NULL)
    {
        if (strcmp(input, str) == 0 && is_print == false)
        {
            is_print = true;
            printf("new line: ");
            puts(input);
        }
        else
        {
            strcpy(str, input);
            is_print = false;
        }
    }
}

int main()
{
    char string[20] = " yang c h a n g ";
    printf("inital string is %s len is %d\n", string, strlen(string));
    deblank2(string);
    printf("deblank string is %s len is %d\n", string, strlen(string));

    char string2[20] = " yang c h a n g ";
    printf("inital string is %s len is %d\n", string2, strlen(string2));
    deblank(string2);
    printf("deblank string is %s len is %d\n", string2, strlen(string2));

    // prime(100);

    triangle(2, 2, -2);

    char dst[] = "123456789";
    char src[] = "7654321";
    print_array(dst, 9);
    copy_n(dst, src, 8);
    print_array(dst, 9);

    print_repeated_line();
    return 0;
}