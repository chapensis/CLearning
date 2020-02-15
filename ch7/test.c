#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test_2() {
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int b[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
    printf("%d \n", a);
    printf("%d \n", *b + 1);
    printf("====== test matrix ====== \n");
    printf("%d \n", matrix); // 毫无疑问，输出的是matrix的首地址
    printf("%d \n", *matrix); // 有点疑问，输出的是matrix的第一个数组的首地址
    printf("%d \n", **matrix); // 有点疑问，输出的是matrix的第一个数组的第一个元素
    
    printf("%d \n", matrix + 1); // 有点疑问，输出的是matrix的第二个数组的首地址
    printf("%d \n", *matrix + 1); // 有点疑问，输出的是matrix的第一个数组的第二个元素的地址
}

int lookup_keyword(char *desired_word, char *keyword_table[], int size) {
    char **kwp;
    for(kwp = keyword_table; kwp < keyword_table + size; kwp++) {
        if(strcmp(desired_word, *kwp) == 0) {
            // kwp = 2293264,  keyword_table = 2293248, result = 2
            printf("kwp = %d,  keyword_table = %d, result = %d \n", kwp, keyword_table, kwp - keyword_table);
            // 指针相加、相减不是地址数值的加减，而是得到数值差值除以指针变量长度的值（一个地址是8个字节）
            return kwp - keyword_table;
        }
    }
    return -1;
}

void test_3() {
    char *keyword[] = {
        "yangchang",
        "chen",
        "liyang"
    };
    printf("%d \n", keyword);
    // 指针的地址是顺序排列的
    printf("%d \n", &keyword[0]);
    printf("%d \n", &keyword[1]);
    printf("%d \n", &keyword[2]);

    // 字符串的地址和指针地址是分开排列的
    printf("%d \n", &keyword[0][0]);
    printf("%d \n", &keyword[1][0]);
    printf("%d \n", &keyword[2][0]);
    int result = lookup_keyword("liyang", keyword, 3);
    printf("result = %d \n", result);
}

int main()
{
    test_3();
    return 0;
}