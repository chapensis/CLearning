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

bool validIPv4(string IP)
{
    if (IP.empty() || IP.back() == '.' || IP.front() == '.')
        return false;
    int digit = 0;
    int dot_ind = -1;
    int dot_num = 0;
    for (int i = 0; i < IP.size(); ++i)
    {
        if (IP[i] == '.')
        {
            if (i - dot_ind == 1)
                return false;
            digit = 0;
            dot_ind = i;
            ++dot_num;
        }
        else if (IP[i] >= '0' && IP[i] <= '9')
        {
            if (i - dot_ind > 1 && digit == 0)
                return false;
            digit = 10 * digit + IP[i] - '0';
            if (digit > 255)
                return false;
        }
        else
        {
            return false;
        }
    }
    return dot_num == 3;
}
bool validHex(char c)
{
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
}
bool validIPv6(string IP)
{
    if (IP.empty() || IP.back() == ':' || IP.front() == ':')
        return false;
    string elem;
    int colon_ind = -1;
    int colon_num = 0;
    for (int i = 0; i < IP.size(); ++i)
    {
        if (IP[i] == ':')
        {
            if (elem.empty())
                return false;
            elem.clear();
            colon_ind = i;
            ++colon_num;
        }
        else if (validHex(IP[i]))
        {
            elem += IP[i];
            if (elem.size() > 4)
                return false;
        }
        else
        {
            return false;
        }
    }
    return colon_num == 7;
}
string validIPAddress(string IP)
{
    if (validIPv4(IP))
        return "IPv4";
    if (validIPv6(IP))
        return "IPv6";
    return "Neither";
}