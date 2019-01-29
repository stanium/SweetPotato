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
    while (1){
        struct sockaddr_in inaddr;
        accept(fd,&inaddr,sizeof(inaddr));
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