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

struct LedCtrl{
    int flags;
    int cmd;
};
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


size_t rb_can_read(RingBuffer *rb){

    assert(rb != NULL);
    if(rb->rcursor<rb->wcursor)return (rb->wcursor-rb->rcursor);
    if(rb->rcursor==rb->wcursor)return 0;
    return (rb->size-(rb->rcursor-rb->wcursor));
}



/**
 *
 * @param rb
 * @param data
 * @param count:数据大小
 * @return
 */
size_t rb_write(RingBuffer *rb,void *data,size_t count){

    assert(rb!=NULL);
    assert(data!=NULL);
//写的数据指针在读数据指针前面，
if(rb->wcursor>=rb->rcursor) {
    if ((rb->size-(rb->wcursor - rb->rb_buffer)) > count) {
        //if(rb->wcursor)
        memcpy(rb->wcursor, data, count);
        //指针移到下一段数据的地址
        rb->wcursor = rb->wcursor + count;
    } else if ((rb->size-(rb->wcursor - rb->rb_buffer)) == count) {
        memcpy(rb->wcursor, data, count);
        rb->wcursor = rb->rb_buffer;
        //如果指针越界，重新校正
    } else{
        rb->wcursor = rb->rb_buffer;
        return rb_write(rb,data,count);
    }
    //读比写快的情况下,前面有读指针所以必不会越界
} else{
    memcpy(rb->wcursor, data, count);
    rb->wcursor = rb->wcursor + count;
}
    return count;

}

size_t rb_read(RingBuffer *rb,void *data,int count){
    assert(rb!=NULL);
    //读理论上必须比写慢
    //读指针在写指针前面
    if(rb->rcursor>=rb->wcursor){
        if((rb->size-(rb->rcursor-rb->rb_buffer))>count){
            memcpy(data,rb->rcursor,count);
            rb->rcursor=rb->rcursor+count;
        } else if((rb->size-(rb->rcursor-rb->rb_buffer))>count){
            memcpy(data,rb->rcursor,count);
            rb->rcursor=rb->rb_buffer;
        } else{
            rb->rcursor=rb->rb_buffer;
            return rb_read(rb,data,count);
        }
        //读指针在写指针后面
    }else {

        memcpy(data,rb->rcursor,count);
        rb->rcursor=rb->rcursor+count;
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
   // RingBuffer *rb=(RingBuffer *)arg;

    while (1){

    }
}


void main(){

    pthread_t cusPid;
    pthread_t proPid;
    //pcond =PTHREAD_COND_INITIALIZER;
   // pmutex=PTHREAD_MUTEX_INITIALIZER;
    //rb=(struct RingBuffer *)malloc(sizeof(struct RingBuffer)+sizeof(struct LedCtrl)*6);
    //memset(rb,0, sizeof(struct RingBuffer)+sizeof(struct LedCtrl)*6);
    rb=CreateRingBuffer(sizeof(struct LedCtrl)*6);
    pthread_create(&cusPid,NULL,Customer,NULL);
    pthread_create(&proPid,NULL,Productor,NULL);


    //rb=rb_new(4);
  //  rb_write(rb,)


}
