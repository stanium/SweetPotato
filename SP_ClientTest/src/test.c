//
// Created by sine on 18-8-2.
//
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/errno.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <sys/ioctl.h>

#include <sys/time.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

void menu(){
    printf("==========Cmd menu==========\n"
           "1:AAWANT_SYSTEM_IDLE_TASK       601\n"
           "2:AAWANT_SYSTEM_AUDIO_TASK      602\n"
           "3:AAWANT_SYSTEM_ALARM_TASK      603\n"
           "4:AAWANT_SYSTEM_NETCONFIG_TASK  604\n"
           "5:AAWANT_SYSTEM_MSC_RECOGNIZE   605\n"
           "6:AAWANT_SYSTEM_REQUEST_SERVLET 606\n"
           "7:AAWANT_SYSTEM_COMMAND_CONTROL 607\n");
}



void test_systemtask(){
    char buf[256];
    char buf1[3][50];
    char buf2[50];
    char buf3[50];
    int a;
    int b;
    int i;
    int j;
    char c;
    char *word;
    char *next;
    char *left;

    menu();

    while (1){

        //memset(buf1,0, sizeof(buf1));
        // memset(buf1,0, sizeof(buf1));
        // memset(buf1,0, sizeof(buf1));
        printf("sine@:");

        //scanf("%s%s%s",buf1,buf2,buf3);
        //b=scanf("%s",buf1);
        gets(buf);

        word=strtok_r(buf," ",&left);
        if(word!=NULL){
            //printf("word=%s\n",word);
            //printf("left=%s\n",left);

            if(strcmp(word,"menu")==0){
                menu();
            } else if(strcmp(word,"task")==0){
                //strcpy(next,left);
                word=strtok_r(left," ",&next);
                if(word!=NULL){
                    printf("word=%s\n",word);


                }
            }
        }




        fflush(stdin);
        //printf("sine@:%s\n",buf1);
    }

}


int AIEU_TCPSend(int sd, char *pBuffer,int lSize )
{
    int				rc;
    int				lLeft;
    fd_set			wr_set;
    struct timeval  tv;

    FD_ZERO(&wr_set);
    FD_SET(sd, &wr_set);

    tv.tv_sec = 60;
    tv.tv_usec = 0;

    lLeft = lSize;

    while (lLeft > 0)     {
        FD_ZERO(&wr_set);
        FD_SET(sd, &wr_set);
        rc = (int) select(sd+1, NULL, &wr_set, NULL, &tv);
        if(rc == 0) {
            break;
        }

        if(rc < 0) {
            if(errno == EINTR) {
                continue;
            }
            printf("PID %d::Select error, err:%s\n",getpid(), strerror(errno));
            return( -1 );
        }

        rc = send ( sd, pBuffer, lLeft, 0);
        if ( rc == -1 )  {
            printf("PID %d::Send error, err:%s\n",getpid(), strerror(errno));
            return (-1);
        };
        pBuffer += rc;
        lLeft -= rc;
    }

    /* -----<data all sent, now prepare for the next send>----- */
    return (lSize-lLeft);
}

int main(){
    struct sockaddr_in sin;
    int server_sock;
    int port=8000;



    server_sock = socket(AF_UNIX, SOCK_STREAM, 0 );
    if(server_sock<0) {
        printf("PID %d::Domain Socket failed!\n",getpid());
        return ( -1 );
    }

    memset( &sin, 0, sizeof( struct sockaddr_in ) );
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr("192.168.1.169");
    sin.sin_port = htons(port);

    if(connect(server_sock, (const struct sockaddr *)&sin, sizeof(struct sockaddr_in))<0) {
        close(server_sock);
        printf("PID %d::Connect failed on port=%d(errno=%d)!\n",getpid(),port,errno);
        return( -1 );
    }

    AIEU_TCPSend(server_sock,"abcdef1234",8);



}