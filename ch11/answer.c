#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DELTA 256

int compare_interger(void const *a, void const *b)
{
    int const *pa = a;
    int const *pb = b;
    return *pa > *pb ? 1 : *pa < *pb ? -1 : 0;
}

/**
 * calloc函数 申请一个n_elements * element_size大小的空间，并且每个元素的值都设置为 \0
 **/
void *calloc(size_t n_elements, size_t element_size)
{
    char *new_memory;
    n_elements = n_elements * element_size;
    new_memory = malloc(n_elements);
    if (new_memory != NULL)
    {
        char *ptr;
        ptr = new_memory;
        while (--n_elements >= 0)
        {
            *ptr++ = '\0';
        }
    }
    return new_memory;
}

/**
 * 调用系统的排序函数
 **/
void sort()
{
    int array[] = {9, 3, 2, 1, 4, 5, 6, 8, 7, 0};
    printf("=============before sort==============\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    qsort(array, 10, sizeof(int), compare_interger);
    printf("=============after sort==============\n");

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void practice_3()
{
    char *input;
    int size = 1;
    int ch;
    do
    {
        ch = getchar();
        if (ch == '\n' || ch == EOF)
        {
            ch = '\0';
        }
        input = realloc(input, size + 1);
        if (input == NULL)
        {
            printf("out of memoey!!! \n");
            return;
        }
        input[size - 1] = (char)ch;
        input[size] = '\0';
        size++;
        printf("input is %s \n", input);
    } while (ch != '\0');
}

char *readstring()
{
    char *buffer = NULL;
    int buffer_size = 0;
    int ch;
    int len;
    char *bp;
    bp = buffer;
    len = 0;
    /*
    ** Get characters one at a time until a newline is read or EOF is
    ** reached.
    */
    do
    {
        ch = getchar();
        if (ch == '\n' || ch == EOF)
            ch = '\0';
        /*
        ** If the buffer is full, make it bigger.每次扩容 DELTA 大小
        */
        if (len >= buffer_size)
        {
            buffer_size += DELTA;
            buffer = realloc(buffer, buffer_size);
            assert(buffer != NULL);
            bp = buffer + len;
        }
        *bp++ = ch;
        len += 1;
    } while (ch != '\0');
    /*
    ** Make a copy of the string to return.
    */
    bp = malloc(len);
    assert(bp != NULL);
    strcpy(bp, buffer);
    return bp;
}

int main()
{
    practice_3();
    return 0;
}