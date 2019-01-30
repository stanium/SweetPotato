//
// Created by sine on 19-1-29.
//

#include <net/if.h>
#include "sys/socket.h"
#include "netdb.h"
#include "unistd.h"
#include "stdio.h"
#include "memory.h"
#include "arpa/inet.h"
#include "net/if.h"
#include "sys/ioctl.h"
#include "sys/types.h"
#include "pthread.h"
#include "sys/select.h"

/**
 *
 * @param eth
 * @param ip为数组
 * @return
 */
int get_local_ip(const char *eth,char *ip){
    int fd;
    struct sockaddr_in sin;
    struct ifreq ifr;
    fd=socket(AF_INET,SOCK_STREAM,0);
    if(fd<0){
        printf("%s :create socket fail\n",__FUNCTION__);
        return -1;
    }

    //strcpy(ifr.ifr_ifrn.ifrn_name,eth);
    stpcpy(ifr.ifr_name,eth);
    if(ioctl(fd,SIOCGIFADDR,&ifr)<0)
    {
        printf("ioctl err\n");
        close(fd);
        return -1;
    }

    memcpy(&sin,&ifr.ifr_addr,sizeof(sin));
    snprintf(ip,16,"%s",inet_ntoa(sin.sin_addr));
    close(fd);
    return 0;
}
int server_TCP(){
    int fd=socket(AF_INET,SOCK_STREAM,0);
    if(fd<0){
        printf("create socket fail\n");
        return -1;
    }
    struct sockaddr_in addr;
    struct in_addr inAddr;
    memset(&addr,0,sizeof(addr));
    addr.sin_port=htons(8080);
    addr.sin_family=AF_INET;
    //addr.sin_addr.s_addr=htonl(INADDR_ANY);
    //
    // c4   01  a8  c0      <--addr.sin_addr.s_addr
    //  |    |   |   |
    // 196   1  168 192     <--192.168.1.196
    addr.sin_addr.s_addr=inet_addr("192.168.1.196");
    printf("s_addr=%x\n",addr.sin_addr.s_addr);


    /*
    char hostname[25];
    //获取主机名称
    gethostname(hostname, sizeof(hostname));
    printf("host name :%s\n",hostname);
    //通过主机名称获取ip地址
    struct hostent *htent;
    htent=gethostbyname(hostname);
    printf("%s\n",htent.)
     */
    if(bind(fd,(struct sockaddr *)&addr, sizeof(addr))<0)
    {
        printf("bind fail\n");
        return -1;
    }

    if(listen(fd,10)<0)
    {
        printf("listen fail\n");
        return -1;
    }
    //htons()==>16位主机字节序转为网络字节序
    //htonl()==>32位主机字节序转为网络字节序
    //ntohs()==>16位网络字节序转为主机字节序
    //ntohl()==>32位网络字节序转为主机字节序
    fd_set readmask;
    struct timeval t;
    int ret;
    char buf[1024];
    while (1){
        FD_ZERO(&readmask);/*将readmask清零，使readmask不含任何fd*/
        FD_SET(fd,&readmask);/*将fd加入大readmask集中*/

        t.tv_sec=5;
        t.tv_usec=50*1000;
        ret=select(fd,&readmask,NULL,NULL,&t);
        if(ret==0){
            break;
        }

        /**1、recv先等待发送缓冲的数据传送完毕，如果在发送缓冲的数据时出现错误，recv返回SOCKET_ERROR
         * 2、如果发送缓冲没有数据或发送完毕，recv先检查接收缓冲区，如果接收缓冲没有数据或者在接收，那么recv一直等待，
         *   直到数据收完。收完后，recv把接收缓冲的数据复制到buf，如果数据大于buf，就分多次接收。每次返回复制数据的字节数。
         *   如果复制出差，返回SOCKET_ERROR,如果等待接收数据时网络断了，返回0*/
        ret=recv(fd,buf, sizeof(buf),0);
        if(ret<0){

        } else if(ret==0){

        }

    }

}

void *handle(void *arg){
    int fd=(int *)arg;
    while (1){

    }

}
int server_TCP2(){
    int fd=0;
    fd=socket(AF_INET,SOCK_STREAM,0);
    if(fd<0){
        printf("%s:create socket fail\n",__FUNCTION__);
        return -1;
    }

    struct sockaddr_in sin;
    memset(&sin,0, sizeof(sin));
    sin.sin_port=htons(8080);
    sin.sin_family=AF_INET;
#if 0
    /**这种方法监听明确的ip地址的网卡，但在有多网卡的时候用下面INADDR_ANY
     * 的方式可以同时监听多张网卡*/
    sin.sin_addr.s_addr=inet_addr("192.168.1.196");
#else
    sin.sin_addr.s_addr=htonl(INADDR_ANY);
#endif
    if(bind(fd,(struct sockaddr *)&sin,sizeof(sin))<0)
    {
        printf("%s:bind fail\n",__FUNCTION__);
        return -1;
    }
    /**监听的设备最多10个*/
    if(listen(fd,10)<0){
        printf("%s:listen fail\n"<__FUNCTION__);
        return -1;
    }

    while (1){
        struct sockaddr_in inaddr;
        /** 当accept函数接受一个连接时，会返回一个新的socket标识符，
         * 后面的数据传输和读取就要通过这个新的socket编号来处理*/
        int sd=accept(fd,&inaddr,sizeof(inaddr));
        if(sd<0){
            printf("%s:accept fail\n",__FUNCTION__);
        }
        pthread_t tid;
        if(pthread_create(&tid,NULL,(void *)handle,(void *)sd)<0){
            printf("%s:pthread_create fail\n",__FUNCTION__);

        }

    }
}

int main(){
    server_TCP();
    /*
    char ip[30];
    get_local_ip("enp0s31f6",ip);

    printf("ip=%s\n", ip);
     */
}