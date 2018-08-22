//
// Created by sine on 18-8-22.
//
#include <pthread.h>
#include <assert.h>
#include "malloc.h"
#include "string.h"
//#include "ringbuffer.h"

typedef struct RingBuffer_T{
    void * data;
    int * rcursor; //读指针
    int * wcursor; //写指针
    int * rb_buffer;
    int cursor;
    int number;
    int size;      //缓冲大小
}RingBuffer;
pthread_cond_t pcond=PTHREAD_COND_INITIALIZER;
pthread_mutex_t pmutex=PTHREAD_MUTEX_INITIALIZER;
RingBuffer *rb;

RingBuffer *CreateRingBuffer(int size){
    RingBuffer *rb;
    rb=malloc(sizeof(RingBuffer)+size);
    rb->size=size;
    //指向数据部分
    rb->rb_buffer=rb+sizeof(RingBuffer);
    rb->rcursor=rb->rb_buffer;
    rb->wcursor=rb->rb_buffer;
}

size_t rb_write(RingBuffer *rb,void *data,size_t count){

    assert(rb!=NULL);
    assert(data!=NULL);
    //if(rb->wcursor)
    memcpy(rb->wcursor,data,count);
    //指针移到下一段数据的地址
    rb->wcursor=rb->wcursor+count;

    if((rb->wcursor-rb->rb_buffer)<rb->size){

    } else{
        rb->wcursor
    }
    return count;


}
void *Customer(void *arg){
    RingBuffer *rb=(RingBuffer *)arg;
    while (1){
        pthread_cond_wait(&pcond,&pmutex);

    }
}

void *Productor(void *arg){
    RingBuffer *rb=(RingBuffer *)arg;
    while (1){
        rb=
        rb
    }
}


void main(){

    pthread_t cusPid;
    pthread_t proPid;
    //pcond =PTHREAD_COND_INITIALIZER;
   // pmutex=PTHREAD_MUTEX_INITIALIZER;
    rb=(struct RingBuffer *)malloc(sizeof(struct RingBuffer)*6);
    memset(rb,0, sizeof(struct RingBuffer)*6);

    pthread_create(&cusPid,NULL,Customer,NULL);
    pthread_create(&proPid,NULL,Productor,NULL);


    //rb=rb_new(4);
  //  rb_write(rb,)


}
