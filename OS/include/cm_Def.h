//
// Created by sine on 19-1-22.
//

#ifndef SWEETPOTATO_CMDEF_H
#define SWEETPOTATO_CMDEF_H

typedef unsigned short int uint16_t;
typedef unsigned int uint32_t;

#if defined(__GNUC__)
#define cm_atomic_inc(a) __sync_fetch_and_add(a,1)
#define cm_atomic_dec(a) __sync_fetch_and_sub(a,1)
#endif

#endif //SWEETPOTATO_CMDEF_H
