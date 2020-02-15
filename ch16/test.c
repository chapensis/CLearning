#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TRUE 1
#define FALSE 0

/**
 * 使用随机数在牌桌上洗“牌”，第2个参数指定牌的数字，当这个函数第1次调用时，
 * 调用srand函数初始化随机数发生器
 **/
void shuffle(int *deck, int n_cards)
{
    static int first_time = TRUE;

    /**
     * 如果尚未进行初始化，用当前的当前时间作为随机数发生器
     **/
    if (first_time)
    {
        first_time = FALSE;
        srand((unsigned int)time(NULL));
    }

    for (int i = 0; i < n_cards; i++)
    {
        int where = rand() % n_cards;
        int temp = deck[where];
        deck[where] = deck[i];
        deck[i] = temp;
    }

    // for (int i = n_cards - 1; i > 0; i--)
    // {
    //     int where = rand() % i;
    //     int temp = deck[where];
    //     deck[where] = deck[i];
    //     deck[i] = temp;
    // }
}

/**
 * 打印数组
 **/
void print_array(int *array, int num)
{
    for (int i = 0; i < num; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int n_cards = 56;
    int deck[n_cards];
    for (int i = 0; i < n_cards; i++)
    {
        deck[i] = i;
    }
    print_array(deck, n_cards);

    shuffle(deck, n_cards);

    print_array(deck, n_cards);

    div_t result = div(10, 3);
    printf("quot = %d \n", result.quot); // 商
    printf("rem = %d \n", result.rem);   // 余数

    int atoi_result = atoi("123");
    printf("atoi_result = %d \n", atoi_result);
    printf("INT_MAX = %d \n", INT_MAX);
    printf("INT_MIN = %d \n", INT_MIN);

    clock_t clock_result = clock();
    printf("CLOCKS_PER_SEC = %d \n", CLOCKS_PER_SEC);
    printf("clock_result = %d \n", clock_result);

    time_t time_result = time(NULL);
    printf("time_result = %d \n", time_result);
    return 0;
}