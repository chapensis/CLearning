#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QUEUE_SIZE 8

void answer_1()
{
    // 定义一个指针，指针需要单独的地址
    // 定义一个数组，数组的地址就是元素首地址
    // a + 4
    // 1、如果a是一个元素，则元素值 + 4
    // 2、如果a是指向整型的指针，则指针移动 4个整型的距离，即往后移动4个元素
    // 3、如果a是指向指针的指针，则移动8 * 4个字节的距离，即4个指针的宽度
    int ints[20] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 190, 200};
    int *ip = ints + 3;
    printf("ints = %d \n", ints);               // 预估：10   实际：数组首地址 2293184
    printf("ints[4] = %d \n", ints[4]);         // 预估：40   实际：True  ints[4] = *(ints + 4)
    printf("ints + 4 = %d \n", ints + 4);       // 预估：40   实际：数组首地址 + 4 * 4(int 占四个字节)
    printf("*ints + 4 = %d \n", *ints + 4);     // 预估：14   实际：True
    printf("*(ints + 4) = %d \n", *(ints + 4)); // 预估：50   实际：True
    printf("ints[-2] = %d \n", ints[-2]);       // 预估：未知数   实际：未知数 2293196
    printf("&ints = %d \n", &ints);             // 预估：数组首地址 2293184   实际：True
    printf("&ints[4] = %d \n", &ints[4]);       // 预估：数组首地址 + 4 * 4   实际：True
    printf("&ints + 4 = %d \n", &ints + 4);     // 预估：数组首地址 + 4   实际：数组首地址 + 4 * 数组总字节长度（难度很大）
    printf("&ints[-2] = %d \n", &ints[-2]);     // 预估：数组首地址 - 8   实际：True
    printf("ip = %d \n", ip);                   // 预估：40   实际：数组首地址 + 4 * 3
    printf("ip[4] = %d \n", ip[4]);             // 预估：80   实际：True
    printf("ip + 4 = %d \n", ip + 4);           // 预估：80   实际：2293212,数组首地址 + 4 * （3 + 4）
    printf("*ip + 4 = %d \n", *ip + 4);         // 预估：44   实际：True
    printf("*(ip +4) = %d \n", *(ip + 4));      // 预估：80   实际：True
    printf("ip[-2] = %d \n", ip[-2]);           // 预估：20   实际：True
    printf("&ip = %d \n", &ip);                 // 预估：指针地址2293176   实际：True
    printf("&ip[4] = %d \n", &ip[4]);           // 预估：数组首地址 + 16   实际：2293212,数组首地址 + 4 * （3 + 4）
    printf("&ip + 4 = %d \n", &ip + 4);         // 预估：指针地址 + 4   实际：指针地址 + 4 * 8
    printf("&ip[-2] = %d \n", &ip[-2]);         // 预估：指针地址 - 8   实际：2293188 数值首地址 + 3 *4 - 2 * 4
}

/**
 * 判断给定字符串是不是回文
 */
void answer_4(char buffer[])
{
    char *start = buffer;
    char *end = start + strlen(buffer) - 1;
    while (start < end)
    {
        if (*start != *end)
        {
            break;
        }
        start++;
        end--;
    }

    if (start < end)
    {
        printf("Not palidrome!!! \n");
    }
    else
    {
        printf("Is palidrome!!! \n");
    }
}

void answer_10()
{
    int array[4][2] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    printf("array = %d \n", array);               // 预估：二维数组首地址2293248   实际：True
    printf("array + 2 = %d \n", array + 2);       // 预估：二维数组第三行地址（二维数组首地址 + 16）   实际：True
    printf("array[3] = %d \n", array[3]);         // 预估：二维数组第四行地址（二维数组首地址 + 24）   实际：True
    printf("array[2] - 1 = %d \n", array[2] - 1); // 预估：二维数组第二行地址（二维数组首地址 + 12）   实际：True
    printf("&array[1][2] = %d \n", &array[1][2]); // 预估：二维数组首地址 + 12   实际：二维数组首地址 + 16
    printf("&array[2][0] = %d \n", &array[2][0]); // 预估：二维数组首地址 + 16   实际：True
}

/**
 * 八皇后问题
 **/
void eight_queue(int queue[QUEUE_SIZE][QUEUE_SIZE], int line)
{
    static int count = 0;
    if (line == QUEUE_SIZE)
    {
        printf("Yes %d: \n", ++count);
        for (int i = 0; i < QUEUE_SIZE; i++)
        {
            for (int j = 0; j < QUEUE_SIZE; j++)
            {
                printf("%d ", queue[i][j]);
            }
            printf("\n");
        }
        return;
    }

    for (int j = 0; j < QUEUE_SIZE; j++)
    {
        int flag = 1;
        for (int i = 0; i < line; i++)
        {
            if (queue[i][j] == 1 ||
                (j - (line - i) >= 0 && queue[i][j - (line - i)] == 1) ||
                (j + (line - i) < QUEUE_SIZE && queue[i][j + (line - i)] == 1))
            {
                // 说明j这个位置不能放皇后
                flag = 0;
                break;
            }
        }
        // 说明目前j这个位置能放
        if (flag == 1)
        {
            queue[line][j] = 1;
            eight_queue(queue, line + 1);
            // 核心代码: 清空刚才放的，继续查看下一种情况,这就是递归 + 回溯啊！！！！！
            queue[line][j] = 0;
        }
    }
}

void practice_8()
{
    int queue[QUEUE_SIZE][QUEUE_SIZE];
    for (int i = 0; i < QUEUE_SIZE; i++)
    {
        for (int j = 0; j < QUEUE_SIZE; j++)
        {
            queue[i][j] = 0;
        }
    }
    eight_queue(queue, 0);
}

int main()
{
    // answer_1();
    // answer_4("yangagnay");
    // answer_10();
    // practice_8();
    char ch[] = "yangchang";
    printf("%d \n", &ch);
    char *ch2 = "chenjieying";
    printf("%d \n", &ch2);
    char *result = strchr(ch, 'c');
    printf("%s \n", result);
    return 0;
}