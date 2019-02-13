//
// Created by sin on 19-1-28.
//
#include "sys/socket.h"
#include "arpa/inet.h"
#include "stdio.h"
#include "netdb.h"
#include "errno.h"
#include "malloc.h"
#include "memory.h"
#include "../include/http_header.h"
/**
 * reserved    = ";" | "/" | "?" | ":" | "@" | "&" | "=" | "+" |
                    "$" | ","
 */
typedef struct url_t{
    char *scheme;   //协议
    char *host;     //
    char *port;     //端口
}URL;

URL * new_url(char *url){
    URL *n_url;
}
int test_http_get(){

}

int test_http_post(){

}
int test_http()
{
    int fd;
    fd=socket(AF_INET,SOCK_STREAM,0);
    if(fd<0){
        printf("%s :create fail\n",__FUNCTION__);
    }

   // struct hostent *htent=gethostbyname("www.lhttp.qingting.fm");
   struct  hostent *htent=gethostbyname2("lhttp.qingting.fm",AF_INET);
    if(htent==NULL){
        printf("%s :gethostbyname fail\n",__FUNCTION__);
        return -EFAULT;
    }

    printf("htent->h_length=%d\n",htent->h_length);
    for(int i=0;htent->h_addr_list[i]!=NULL;i++){
        printf("%s :ip=%s,host=%s\n",__FUNCTION__,inet_ntoa(*(struct in_addr*)htent->h_addr_list[i]),htent->h_name);
    }

    struct sockaddr_in des_addr;
    memset(&des_addr,0,sizeof(des_addr));

    des_addr.sin_family=AF_INET;
    des_addr.sin_port=htons(80);
    des_addr.sin_addr=*(struct in_addr *)htent->h_addr_list[0];

    int ret=connect(fd,(struct sockaddr *)&des_addr, sizeof(des_addr));
    if(ret<0){
        printf("%s : connect fail\n",__FUNCTION__);
        return -1;
    }

    //http_header_type header_type=http_ty
    char *sbuf="Get http://lhttp.qingting.fm/live/386/64k.mp3 HTTP/1.1\r\n"
               "Accept-Language: zh-Hans-CN,zh-Hans;q=0.5\r\n"
               "Host: www.baidu.com\r\n"
               "Connection: Keep-Alive\r\n";
    int len=strlen(sbuf);
    printf("sbuf len=%d\n",len);
   // send(fd,sbuf)





}

int main(){
    test_http();
}


