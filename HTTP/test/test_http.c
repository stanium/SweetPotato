//
// Created by sin on 19-1-28.
//
#include <stdlib.h>
#include <fcntl.h>
#include "sys/socket.h"
#include "arpa/inet.h"
#include "stdio.h"
#include "netdb.h"
#include "errno.h"
#include "malloc.h"
#include "memory.h"
#include "../include/http_header.h"
#include "unistd.h"
#include "pthread.h"
#include "sys/mman.h"
#include "sys/inotify.h"
#include "poll.h"
// relativeURI   = ( ("//" (server | reg_name )[ ("/"  ((*pchar *( ";" param )) *( "/" (*pchar *( ";" param )) ))) ])
// | abs_path
// | rel_path ) [ "?" query ]
/**absoluteURI**/
/*
<hier_part>
<net_path>
///scheme ":"( "//" (server | reg_name) [ abs_path ])[ "?" query ]
 <server>
 ///scheme ":"( "//" ([ [ userinfo "@" ] hostport ]) [ abs_path ])[ "?" query ]

 </server>
 <reg_name>
 ///scheme ":"( "//" 1*( unreserved | escaped | "$" | "," |";" | ":" | "@" | "&" | "=" | "+" ) [ abs_path ])[ "?" query ]
 </reg_name>
</net_path>

<abs_path>
///scheme ":"( "/"  path_segments ) [ "?" query ]
</abs_path>
</hier_part>

<<opaque_part>
///scheme ":"( unreserved | escaped | ";" | "?" | ":" | "@" |
//                  "&" | "=" | "+" | "$" | ",")( *uric)
</opaque_part>
*/
/**relativeURI**/
/*
 ( net_path | abs_path | rel_path ) [ "?" query ]
 <net_path>
 <server>
 "//" [ [ userinfo "@" ] hostport ] [ abs_path ] [ "?" query ]
 </server>
 <reg_name>
"//" 1*( unreserved | escaped | "$" | "," |";" | ":" | "@" | "&" | "=" | "+" ) [ abs_path ] [ "?" query ]
 </reg_name>
 </net_path>
 <abs_path>
 "/"  (segment *( "/" segment )) [ "?" query ]
 </abs_path>
 <rel_path>
 1*( unreserved | escaped |";" | "@" | "&" | "=" | "+" | "$" | "," ) [ abs_path ][ "?" query ]
 </rel_path>
 */

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

/*
typedef struct mpeg_header{
    int flags:11;
    int id:2;
    int seq:2;
    int protection:1;
    int index_bsp:4;
    int index_sample:2;
    int padding:1;
    int pb:1;
    int channel_mode:2;
    int extention:2;
    int version:1;
    int obit:1;
};
 */
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

//    n_url->scheme=malloc()

}
int test_http_get(){

}

int test_http_post(){

}

FILE *file=NULL;
static pthread_cond_t pcond=PTHREAD_COND_INITIALIZER;
static pthread_mutex_t pmutex=PTHREAD_MUTEX_INITIALIZER;
#define MAX_BUF 2048*100
char rbuf[MAX_BUF*4];
int count;
struct audio_msg{
    char *position;
    int wflag;
    int size;
};
struct audio_msg amsg;
void * thread_test(void *arg){
   // pthread_mutex_lock(&pmutex);
    while (1){
        pthread_cond_wait(&pcond,&pmutex);
       // pthread_mutex_lock(&pmutex);
        if(amsg.wflag==1){
            printf("write start\n");
            fwrite(amsg.position,amsg.size,1,file);
            amsg.wflag=0;
            printf("write finish\n");
        }
        //count=0;
      //  pthread_mutex_unlock(&pmutex);
    }
  //  pthread_mutex_unlock(&pmutex);


}

typedef struct cache_t{
    char *buf;
    int size;
    int sector;
}cache;
int cache_init(int size,int sector){
    //int ret=mmap(NULL,,PROT_READ|PROT_WRITE,MAP_SHARED,);
}

int test_http()
{
    int fd;
    fd=socket(AF_INET,SOCK_STREAM,0);
    if(fd<0){
        printf("%s :create fail\n",__FUNCTION__);
    }
//http://lhttp.qingting.fm/live/386/64k.mp3
   // struct hostent *htent=gethostbyname("www.lhttp.qingting.fm");
   struct  hostent *htent=gethostbyname2("lhttp.qingting.fm",AF_INET);
   // struct  hostent *htent=gethostbyname2("www.baidu.com",AF_INET);
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
  //  fcntl( fd, F_SETFL, fcntl(fd, F_GETFL) | O_NONBLOCK );
    int ret=connect(fd,(struct sockaddr *)&des_addr, sizeof(des_addr));
    if(ret<0){
        printf("%s : connect fail\n",__FUNCTION__);
        return -1;
    } else{
        printf("connect to %s...\n",inet_ntoa(des_addr.sin_addr));
    }


    //http_header_type header_type=http_ty

    char *sbuf="GET /live/386/64k.mp3 HTTP/1.1\r\n"
               "Host: lhttp.qingting.fm\r\n"
               "Connection: keep-alive\r\n"
               "Upgrade-Insecure-Requests: 1\r\n"
      //         "User-Agent: Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Ubuntu Chromium/71.0.3578.98 Chrome/71.0.3578.98 Safari/537.36\r\n"
               "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8\r\n"
               "Accept-Encoding: gzip, deflate\r\n"
               "Accept-Language: zh-CN,zh;q=0.5\r\n"
               "\r\n";
               /*
    char *sbuf="GET http://www.baidu.com HTTP/1.1\r\n"
               "Accept-Language: zh-Hans-CN,zh-Hans;q=0.5\r\n"
               "Host: wwww.baidu.com\r\n"
               "Connection: Keep-Alive\r\n";
               */
    int len=strlen(sbuf);
    printf("sbuf len=%d,data=%s\n",len,sbuf);
    ret=send(fd,sbuf,len,0);
    if(ret<0){
        printf("send fail\n");
        return -1;
    }

    printf("send data size=%d\n",ret);


    file=fopen("test.mp3","w+");
    if(file==NULL){
        printf("fopen fail\n");
        return -1;
    }
    /*
    pthread_t ptd;
    int pd=pthread_create(&ptd,NULL,thread_test,NULL);
    if(pd<0){
        printf("pthread_create fail\n");
        return -1;
    }
     */
    char *p=rbuf;
     count=0;
     int bnum=1;
    while (1){
        ret=recv(fd,p,2048,0);
        if(ret<=0){
            printf("recv err\n");
            sleep(5);
            continue;
        }
        p=p+ret;
        count=count+ret;
       // printf("count=%d,ret=%d,p=0x%x\n",count,ret,p);

        if(MAX_BUF-count<=1460){

#if 0
          //  pthread_mutex_lock(&pmutex);
            amsg.size=count;
            amsg.position=p-count;
            amsg.wflag=1;

            p=p-count+MAX_BUF;
            bnum++;
            if(bnum==4){
                bnum=1;
                p=rbuf;
            }
            count=0;
            pthread_cond_signal(&pcond);
          //  pthread_mutex_unlock(&pmutex);
#else
            int sz=fwrite(rbuf,count,1,file);
            printf("write ok\n");
            exit(1);
#endif
        }
        //rbuf[1023]='\0';
        //printf("ret=%d,recv=%s\n",ret,rbuf);

    }








}

struct test_st{
    int b;
};

struct test_st *st;
int test_calloc_(){
   // st=(struct test_st *)calloc(1,sizeof(st[0]));
    printf("st[0] size=%d,st size=%d\n",sizeof(st[0]), sizeof(st));

}

int test_inotify_FileOrDir(){
#define PATH "/home/sine/tests/test"
    struct pollfd *pollfd1,*new_pollfd;

    char devname[4096];
    char *filename;
    nfds_t nfds;
    pollfd1=calloc(1,sizeof(pollfd1[0]));
    pollfd1->fd=inotify_init();
    pollfd1->events=POLLIN;
    int ret=inotify_add_watch(pollfd1->fd,PATH,IN_CREATE|IN_DELETE|IN_MODIFY);
    if(ret<0){
        printf("could not add watch ,%s\n",strerror(errno));
        return -1;
    }

//    ret=open(fd,O_RDWR);
//    if(ret<0){
//        printf("open fail,%s\n",strerror(errno));
//        return -1;
//    }

    nfds=1;
    char eventbuf[512];
    struct inotify_event *event;
    while (1) {
        printf("nfds =%d\n",nfds);
        poll(pollfd1,nfds,-1);
       // printf("nfds 1=%d\n",nfds);
        if(pollfd1[0].revents&POLLIN) {
            printf("can read\n");

            ret = read(pollfd1[0].fd, eventbuf, sizeof(eventbuf));
            if (ret < (int) sizeof(*event)) {
                printf("could not get event,%s\n", strerror(errno));
                //return -1;
            }
            strcpy(devname,PATH);
            filename=devname+strlen(devname);
            *filename++='/';
            if(ret>=(int) sizeof(*event)){
                event=(struct inotify_event *)eventbuf;
                if(event->len){
                    printf("file name=%s\n",event->name);
                    if(event->mask&IN_CREATE){
                        printf("event of creatint a new file happen\n");
                        strcpy(filename,event->name);
                        printf("devname=%s\n",devname);
                        /*
                        int sd=open(devname,O_RDWR);
                        if(sd<0){
                            printf("open fail,%s\n",strerror(errno));
                        }
                         */
                        new_pollfd=(struct pollfd*)realloc(pollfd1, sizeof(pollfd1[0])*(nfds+1));
                        if(new_pollfd==NULL){
                            printf("realloc fail\n");
                            continue;
                        }


                       // printf("nfds=%d\n",nfds);
                        pollfd1=new_pollfd;
                       // pollfd1[nfds].fd=sd;
                       // pollfd1[nfds].events=POLLIN;
                       // nfds++;

                        pollfd1[nfds].fd=inotify_init();
                        pollfd1[nfds].events=POLLIN;
                        ret=inotify_add_watch(pollfd1[nfds].fd,devname,IN_MODIFY);
                        printf("inotify_add_watch:ndfs=%d,fd=%d,devname=%s\n",nfds,pollfd1[nfds].fd,devname);
                        if(ret<0){
                            printf("could not add watch ,%s\n",strerror(errno));
                        //    return -1;
                        }
                        nfds++;


                    } else if(event->mask&IN_DELETE){
                        printf("event of deleting a file happen\n");
                    }
                }
            }

        }

        for(int i=1;i<nfds;i++){
            if(pollfd1[i].revents){
                if(pollfd1[i].revents&POLLIN){
                    printf("get a new read event,%d\n",i);
                }
            }
        }
    }

}

/**
 *
 * @return
 */
int test_inotify_File(){
#define PATH1 "/home/sine/tests/test/1"
    struct pollfd *pollfd1;
    struct inotify_event *event;
    pollfd1=calloc(1,sizeof(pollfd1[0]));
    pollfd1->fd=inotify_init();
    pollfd1->events=POLLIN;
    inotify_add_watch(pollfd1->fd,PATH1,IN_ACCESS);
    char buf[2048];
    while (1){
        poll(pollfd1,1,-1);
        if(pollfd1[0].revents){
            if(pollfd1[0].revents&POLLIN){
                printf("get a event\n");
                int len=read(pollfd1->fd,buf, sizeof(buf));
                if(len>0){
                    event=(struct inofity_event *)buf;

                }
            }
        }

    }

}


struct str_a{
    int a;
};

struct str_b{
    int b;
    struct str_a parent;


};

int test_p(){
    struct str_b *n1=(struct str_b *)malloc(sizeof(struct str_b));
    printf("n1 addr=0x%x,n1->parent addr=0x%x\n",n1,&(n1->parent));
    struct str_a *n2=(struct str_a *)n1;
    printf("n2 addr=0x%x\n",n2);
    n1->b=1;
    struct str_a *n3=(struct str_a *)n1;
    //n3.b=1;
   // printf()
}

int main(){
   // test_http();
 //  test_calloc_();
   //test_inotify_FileOrDir();
    //test_inotify_File();
    test_p();
    //printf("uint =%d,ulong =%d\n",sizeof(unsigned int), sizeof(unsigned long));
}


