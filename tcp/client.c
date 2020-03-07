#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <winsock2.h>

#define bzero(a, b) memset(a, 0, b)

#define DEST_PORT 1500      //目标地址端口号
#define DEST_IP "127.0.0.1" /*目标地址IP，这里设为本机*/
#define MAX_DATA 100        //接收到的数据最大程度

int main()
{
    struct sockaddr_in dest_addr; /*目标地址信息*/
    char buf[MAX_DATA];           // 储存接收数据

    int sockfd = socket(AF_INET, SOCK_STREAM, 0); /*socket句柄, 建立socket*/
    if (sockfd == -1)
    {
        printf("socket failed:%d", errno);
    }

    // 参数意义见上面服务器端
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(DEST_PORT);
    dest_addr.sin_addr.s_addr = inet_addr(DEST_IP);
    bzero(&(dest_addr.sin_zero), 8);

    // 连接方法，传入句柄，目标地址和大小
    int connect_result = connect(sockfd, (struct sockaddr *)&dest_addr, sizeof(struct sockaddr));
    if (connect_result == -1)
    {
        // 失败时可以打印errno
        printf("connect failed:%d", errno);
    }
    else
    {
        printf("connect success");
        // 将接收数据打入buf，参数分别是句柄，储存处，最大长度，其他信息（设为0即可）。
        recv(sockfd, buf, MAX_DATA, 0);
        printf("Received:%s", buf);
    }
    // 关闭socket
    close(sockfd);
    return 0;
}