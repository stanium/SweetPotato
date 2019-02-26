//
// Created by sine on 19-1-29.
//
#include <netinet/in.h>
#include <netdb.h>
#include <memory.h>
#include "sys/socket.h"
#include "stdlib.h"
#include "stdio.h"
#include "sys/types.h"
#include "arpa/inet.h"
#include "unistd.h"

/**
 * struct sockaddr_in;
 * struct sockaddr_in6;
 * struct sockaddr_un;
 * struct
 */




/**
 *
 * @param domain
 * @param ip
 * @return
 */
int getIpByDomain(const char *domain,char *ip){
    struct hostent *htent;
    char **pptr;
    htent=gethostbyname(domain);
    if(htent==NULL)
    {
        printf("gethostbyname err\n");
        return -1;
    }
/*
    for(pptr=htent->h_addr_list;*pptr!=NULL;pptr++){
        if(NULL!=inet_ntop(htent->h_addrtype,*pptr,ip,IP_SIZE)){
            return 0;
        }
    }
    */
}

int getLocalIp(){

}

int getLocalMac(){

}
int a(){
    char hname[100];
    struct hostent *hent;
    gethostname(hname, sizeof(hname));
    hent=gethostbyname("www.qq.com");
    printf("hostname: %s\n",hent->h_name);

}
#define IPV4
int test_os_tcp(){
    char buf[1024];
#ifdef IPV4
    int fd=socket(AF_INET,SOCK_STREAM,0);
    if(fd<0){
        printf("create socket fail\n");
    }

#if 1
    struct sockaddr_in addr;
    memset(&addr,0,sizeof(addr));
   // addr.sin_addr.s_addr=inet_addr("127.0.0.1");
    inet_pton(AF_INET,"127.0.0.1",&addr.sin_addr);
    addr.sin_family=AF_INET;
    addr.sin_port=htons(10004);

#else
    struct sockaddr addr;
    memset(&addr,0,sizeof(addr));
    addr.sa_data=;
    addr.sa_family=AF_INET;
#endif
//   inet_pton(AF_INET,)
    printf("client addr=%s,sock fd=%d\n",inet_ntoa(addr.sin_addr),fd);
#endif
#ifdef IPV6
    int fd=socket(AF_INET6,SOCK_STREAM,0);
    if(fd<0){
        printf("create socket fail\n");
    }
    struct in6_addr addr6;
    struct sockaddr_in6 addr;
    addr.sin6_addr=;
    addr.sin6_family=AF_INET6;
    addr.sin6_flowinfo=;
    addr.sin6_port=htons(80);
    addr.sin6_scope_id=;

#endif
    if(connect(fd,(struct sockaddr*)&addr, sizeof(addr))<0){
        printf("%s:connect fail\n",__FUNCTION__);
        return -1;
    }

    stpncpy(buf,"hello fucu",11);
    send(fd,buf,11,0);


}

int test_os_udp(){
#ifdef IPV4
    int fd=socket(AF_INET,SOCK_DGRAM,0);
    if(fd<0){
        printf("create socket fail\n");
    }
#endif
#ifdef IPV6
    int fd=socket(AF_INET6,SOCK_DGRAM,0);
    if(fd<0){
        printf("create socket fail\n");
    }
#endif
    struct sockaddr_in sin;
    memset(&sin,0,sizeof(sin));
    sin.sin_family=AF_INET;
    sin.sin_port=htons(10005);
    //sin.sin_addr.s_addr=inet_addr("127.0.0.1");
    inet_pton(AF_INET,"127.0.0.1",&sin.sin_addr);
    char buf[1024];
    stpcpy(buf,"test udp");
    sendto(fd,buf,11,0,(struct sockaddr *)&sin, sizeof(sin));
}




int test_os_raw(){
#ifdef IPV4
    int fd=socket(AF_INET,SOCK_RAW,0);
    if(fd<0){
        printf("create socket fail\n");
    }
#endif
#ifdef IPV6
    int fd=socket(AF_INET6,SOCK_RAW,0);
    if(fd<0){
        prinf("create socket fail\n");
    }
#endif
}

int test_send()
{

}


int cm_getaddrinfo(const char *url,char *b){
    int ret = -1;
    struct addrinfo *res;
    struct addrinfo hint;
    struct addrinfo *curr;
    char ipstr[16];

    bzero(&hint, sizeof(hint));
    hint.ai_family = AF_INET;
    hint.ai_socktype = SOCK_STREAM;

    ret = getaddrinfo(url, NULL, &hint, &res);
    if (ret != 0)
    {
        printf("getaddrinfo error\n");
        return -1;
    }

    for (curr = res; curr != NULL; curr = curr->ai_next)
    {
        inet_ntop(AF_INET,&(((struct sockaddr_in *)(curr->ai_addr))->sin_addr), ipstr, 16);
        printf("%s\n", ipstr);
    }

    freeaddrinfo(res);
}

int cm_getaddrinfo_ipv6(const char *url){
    int ret = -1;
    struct addrinfo *res;
    struct addrinfo hint;
    struct addrinfo *curr;
    char ipstr[16];

    bzero(&hint, sizeof(hint));
    hint.ai_family = AF_INET6;
    hint.ai_socktype = SOCK_STREAM;

    ret = getaddrinfo(url, NULL, &hint, &res);
    if (ret != 0)
    {
        printf("getaddrinfo error\n");
        return -1;
    }

    for (curr = res; curr != NULL; curr = curr->ai_next)
    {
        inet_ntop(AF_INET,&(((struct sockaddr_in *)(curr->ai_addr))->sin_addr), ipstr, 16);
       // inet_ntop(AF_INET6&(((struct sockaddr_in6 *))))
        printf("%s\n", ipstr);
    }

    freeaddrinfo(res);
}






int main()
{
    //test_os_tcp();
    //test_os_udp();
    cm_getaddrinfo("www.baidu.com",NULL);
    //a();
}
