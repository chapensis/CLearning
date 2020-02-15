#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test_string() {
   char *string = "yangchang";
   char ch;
   // 下列表达式等于 1、ch = *string
   //               2、string++
   while ((ch = *string++) != '\0')
   {
       printf("%c ", ch);
   }
   puts("");
}

int main() {
    // char ch = 'a';
    // char *c;
    // c = &ch;
    // printf("char is %c \n", *c);
    // test_string();
    char str[] = {'y','a','n','g','\0'};
    *str = 'l';
    printf("%s \n", str);
    return 0;
}