#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void answer4() {
    int quantity;
    int price;
    char department[20]; // 必须定义长度
    scanf("%d %d %s", &quantity, &price, &department); // 对于数组，地址可传可不传
    printf("quantity = %d, price = %d, department = %s \n", quantity, price, department);
}

void practice2() {
    printf("start to input...\n");
    char input[1000];
    int num = 0;
    while (gets(input) != NULL) {
        printf("Line:%d %s \n", num, input);
        num++;
        int len = strlen( input );
    }
}

void practice3() {
    printf("start to input...\n");
    char input[1000];
    int num = 0;
    while (gets(input) != NULL) {
        printf("Line:%d %s \n", num, input);
        num++;
        int len = strlen( input );
        char checknum = -1;
        for(int i=0 ;i<len; i++) {
            checknum += input[i];
        }
        printf("%d \n", checknum);
    }
}

void practice4() {
    printf("start to input...\n");
    char input[1000];
    char max_str[1000];
    int max_len = 0;
    int num = 0;
    while (gets(input) != NULL) {
        printf("Line:%d %s %d\n", num, input, strlen(input));
        num++;
        int len = strlen( input );
        if (len > max_len) {
            max_len = len;
            strcpy(max_str, input);
        }
    }
    printf("max length = %d, max str = %s \n", max_len, max_str);
}

int main() {
    // answer4();
    // practice2();
    // practice3();
    practice4();
    return 0;
}