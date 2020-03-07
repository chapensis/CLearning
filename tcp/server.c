#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <winsock2.h>

#define bzero(a, b) memset(a, 0, b)

#define PORT 1500 //端口号
#define BACKLOG 5 /*最大监听数*/

int main()
{
    // 建立socket, 返回socket句柄
    // domain：即协议域，又称为协议族（family）, AF_INET决定了要用ipv4地址（32位的）与端口号（16位的）的组合
    // type：指定socket类型。常用的socket类型有，SOCK_STREAM、SOCK_DGRAM、SOCK_RAW、SOCK_PACKET、SOCK_SEQPACKET等等
    // protocol：故名思意，就是指定协议。常用的协议有，IPPROTO_TCP、IPPTOTO_UDP、IPPROTO_SCTP、IPPROTO_TIPC等
    int sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); //  SOCK_STREAM: TCP 套接口
    if (sockfd == -1)
    {
        printf("socket failed:%d", errno);
        return -1;
    }

    struct sockaddr_in my_addr;                  /* 本方地址信息结构体，下面有具体的属性赋值 */
    my_addr.sin_family = AF_INET;                /* 该属性表示接收本机或其他机器传输 */
    my_addr.sin_port = htons(PORT);              /* 端口号 */
    my_addr.sin_addr.s_addr = htonl(INADDR_ANY); /* IP，括号内容表示本机IP */
    bzero(&(my_addr.sin_zero), 8);               /* 将其他属性置0 */
    // sockfd：即socket描述字，它是通过socket()函数创建了，唯一标识一个socket。bind()函数就是将给这个描述字绑定一个名字。
    // addr：一个const struct sockaddr *指针，指向要绑定给sockfd的协议地址。这个地址结构根据地址创建socket时的地址协议族的不同而不同，如ipv4对应的是：
    // addrlen：对应的地址长度
    int bind_result = bind(sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr));
    if (bind_result < 0)
    {
        // 绑定地址结构体和socket
        printf("bind error");
        return -1;
    }

    // 开启监听 ，第二个参数是最大监听数
    listen(sockfd, BACKLOG);
    while (1)
    {
        int sin_size = sizeof(struct sockaddr_in);
        struct sockaddr_in their_addr; /* 对方地址信息 */
        // 建立连接后的句柄, 在这里阻塞知道接收到消息，参数分别是socket句柄，接收到的地址信息以及大小
        int new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size);
        if (new_fd == -1)
        {
            printf("receive failed");
        }
        else
        {
            printf("receive success");
            // 发送内容，参数分别是连接句柄，内容，大小，其他信息（设为0即可）
            send(new_fd, "Hello World!", 12, 0);
        }
    }
    return 0;
}