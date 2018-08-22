

#ifndef RINGBUFFER_H
#define RINGBUFFER_H

#include <stdlib.h>

struct RingBuffer;

struct RingBuffer* rb_new(size_t capacity);
void rb_free(struct RingBuffer *rb);
void rb_reset(struct RingBuffer *rb);

size_t rb_capacity(struct RingBuffer *rb);
size_t rb_can_read(struct RingBuffer *rb);
size_t rb_can_write(struct RingBuffer *rb);

size_t rb_read(struct RingBuffer *rb, void *data, size_t count);
size_t rb_write(struct RingBuffer *rb, const void *data, size_t count);

#endif
