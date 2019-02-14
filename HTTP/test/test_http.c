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
// relativeURI   = ( ("//" (server | reg_name )[ ("/"  ((*pchar *( ";" param )) *( "/" (*pchar *( ";" param )) ))) ])
// | abs_path
// | rel_path ) [ "?" query ]
/**URI BNF
  URI-reference = [ absoluteURI | relativeURI ] [ "#" fragment ]
  absoluteURI   = scheme ":" ( hier_part | opaque_part )
  relativeURI   = ( net_path | abs_path | rel_path ) [ "?" query ]

  hier_part     = ( net_path | abs_path ) [ "?" query ]
  opaque_part   = uric_no_slash *uric

  uric_no_slash = unreserved | escaped | ";" | "?" | ":" | "@" |
                  "&" | "=" | "+" | "$" | ","

  net_path      = "//" authority [ abs_path ]
  abs_path      = "/"  path_segments
  rel_path      = rel_segment [ abs_path ]

  rel_segment   = 1*( unreserved | escaped |
                      ";" | "@" | "&" | "=" | "+" | "$" | "," )

  scheme        = alpha *( alpha | digit | "+" | "-" | "." )

  authority     = server | reg_name

  reg_name      = 1*( unreserved | escaped | "$" | "," |
                      ";" | ":" | "@" | "&" | "=" | "+" )

  server        = [ [ userinfo "@" ] hostport ]
  userinfo      = *( unreserved | escaped |
                     ";" | ":" | "&" | "=" | "+" | "$" | "," )

  hostport      = host [ ":" port ]
  host          = hostname | IPv4address
  hostname      = *( domainlabel "." ) toplabel [ "." ]
  domainlabel   = alphanum | alphanum *( alphanum | "-" ) alphanum
  toplabel      = alpha | alpha *( alphanum | "-" ) alphanum
  IPv4address   = 1*digit "." 1*digit "." 1*digit "." 1*digit
  port          = *digit

  path          = [ abs_path | opaque_part ]
  path_segments = segment *( "/" segment )
  segment       = *pchar *( ";" param )
  param         = *pchar
  pchar         = unreserved | escaped |
                  ":" | "@" | "&" | "=" | "+" | "$" | ","

  query         = *uric

  fragment      = *uric

  uric          = reserved | unreserved | escaped
  reserved      = ";" | "/" | "?" | ":" | "@" | "&" | "=" | "+" |
                  "$" | ","
  unreserved    = alphanum | mark
  mark          = "-" | "_" | "." | "!" | "~" | "*" | "'" |
                  "(" | ")"

 //转义
  escaped       = "%" hex hex
  hex           = digit | "A" | "B" | "C" | "D" | "E" | "F" |
                          "a" | "b" | "c" | "d" | "e" | "f"

  alphanum      = alpha | digit
  alpha         = lowalpha | upalpha

  lowalpha = "a" | "b" | "c" | "d" | "e" | "f" | "g" | "h" | "i" |
             "j" | "k" | "l" | "m" | "n" | "o" | "p" | "q" | "r" |
             "s" | "t" | "u" | "v" | "w" | "x" | "y" | "z"
  upalpha  = "A" | "B" | "C" | "D" | "E" | "F" | "G" | "H" | "I" |
             "J" | "K" | "L" | "M" | "N" | "O" | "P" | "Q" | "R" |
             "S" | "T" | "U" | "V" | "W" | "X" | "Y" | "Z"
  digit    = "0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" |
             "8" | "9"

 */
typedef struct url_t{
    char *scheme;   //协议
    char *username;
    char *password;
    char *host;     //
    unsigned int port;     //端口
    char *file;
    //char *url;
    //char *noauth_url;
}URL;
/**
 * 字符串转义
 * @param out
 * @param in
 * @return
 */
int url_escape_string(char *out,char *in){
    int len=strlen(in);
}

int url_unescape_string(char *out,char *in){

}

/**从一个url字符串提取出组成URL的各个部分
 * scheme =( lowalpha | upalpha) *( lowalpha | upalpha | digit | "+" | "-" | "." )
 *
 * http_URL = "http:" "//" host [ ":" port ] [ abs_path [ "?" query ]]
 * @param url
 * @return
 */
URL * new_url(char *url){
    URL *n_url;
    char *escape_url;
    char *pt1;
    int len;
    if(url==NULL)return NULL;
    len=strlen(url);


    if((pt1=strstr(escape_url,"://"))==NULL){

    }

    n_url->scheme=malloc()

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
   // test_http();
    printf("uint =%d,ulong =%d\n",sizeof(unsigned int), sizeof(unsigned long));
}


