//
// Created by sin on 19-1-28.
//
#include "sys/socket.h"
#include "arpa/inet.h"
#include "stdio.h"
#include "netdb.h"
#include "errno.h"
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

    struct hostent *htent=gethostbyname("www.baidu.com");
    if(htent==NULL){
        printf("%s :gethostbyname fail\n",__FUNCTION__);
        return -EFAULT;
    }

    printf("htent->h_length=%d\n",htent->h_length);
    for(int i=0;htent->h_addr_list[i]!=NULL;i++){
        printf("%s :ip=%s\n",__FUNCTION__,inet_ntoa(*(struct in_addr*)htent->h_addr_list[i]));
    }





}

int main(){
    test_http();
}


