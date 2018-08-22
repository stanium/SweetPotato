//
// Created by sine on 18-8-22.
//

#include <assert.h>
#include "pthread.h"
#include "malloc.h"
#include "memory.h"
/*
typedef struct RingBuffer_T{
    RingBuffer *head;
    RingBuffer *tail;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int data;
}RingBuffer;

void initRingBuffer(){

}

 */

int min(int a, int b){
    return a>b?b:a;
}

struct RingBuffer{
    size_t rb_capacity;
    char  *rb_head;
    char  *rb_tail;
    char  *rb_buff;
};

struct RingBuffer* rb_new(size_t capacity)
{
    struct RingBuffer *rb = (struct RingBuffer *) malloc(sizeof(struct RingBuffer) + capacity);
    if (rb == NULL) return NULL;

    rb->rb_capacity = capacity;
    rb->rb_buff     = (char*)rb + sizeof(struct RingBuffer);
    rb->rb_head     = rb->rb_buff;
    rb->rb_tail     = rb->rb_buff;

    return rb;
};

void rb_reset(struct RingBuffer *rb)
{
    rb->rb_buff     = (char*)rb + sizeof(struct RingBuffer);
    rb->rb_head     = rb->rb_buff;
    rb->rb_tail     = rb->rb_buff;
}

void  rb_free(struct RingBuffer *rb)
{
    free((char*)rb);
}

size_t     rb_capacity(struct RingBuffer *rb)
{
    assert(rb != NULL);
    return rb->rb_capacity;
}
size_t     rb_can_read(struct RingBuffer *rb)
{
    assert(rb != NULL);
    if (rb->rb_head == rb->rb_tail) return 0;
    if (rb->rb_head < rb->rb_tail) return rb->rb_tail - rb->rb_head;
    return rb_capacity(rb) - (rb->rb_head - rb->rb_tail);
}
size_t     rb_can_write(struct RingBuffer *rb)
{
    assert(rb != NULL);
    return rb_capacity(rb) - rb_can_read(rb) - 1;
}

size_t     rb_read(struct RingBuffer *rb, void *data, size_t count)
{
    assert(rb != NULL);
    assert(data != NULL);
    if (rb->rb_head < rb->rb_tail)
    {
        int copy_sz = min(count, rb_can_read(rb));
        memcpy(data, rb->rb_head, copy_sz);
        rb->rb_head += copy_sz;
        return copy_sz;
    }
    else
    {
        if (count < rb_capacity(rb)-(rb->rb_head - rb->rb_buff))
        {
            int copy_sz = count;
            memcpy(data, rb->rb_head, copy_sz);
            rb->rb_head += copy_sz;
            return copy_sz;
        }
        else
        {
            int copy_sz = rb_capacity(rb) - (rb->rb_head - rb->rb_buff);
            memcpy(data, rb->rb_head, copy_sz);
            rb->rb_head = rb->rb_buff;
            copy_sz += rb_read(rb, (char*)data+copy_sz, count-copy_sz);
            return copy_sz;
        }
    }
}

size_t rb_write(struct RingBuffer *rb, const void *data, size_t count)
{
    assert(rb != NULL);
    assert(data != NULL);

    if (count > rb_can_write(rb)) return -1;

    if (rb->rb_head <= rb->rb_tail)
    {
        int tail_avail_sz = (int)rb_capacity(rb) - (rb->rb_tail - rb->rb_buff);
        if ((int)count <= tail_avail_sz)
        {
            memcpy(rb->rb_tail, data, count);
            rb->rb_tail += count;
            if (rb->rb_tail == rb->rb_buff+rb_capacity(rb))
                rb->rb_tail = rb->rb_buff;
            return count;
        }
        else
        {
            memcpy(rb->rb_tail, data, tail_avail_sz);
            rb->rb_tail = rb->rb_buff;

            return tail_avail_sz + rb_write(rb, (char*)data+tail_avail_sz, count-tail_avail_sz);
        }
    }
    else
    {
        memcpy(rb->rb_tail, data, count);
        rb->rb_tail += count;
        return count;
    }
}

