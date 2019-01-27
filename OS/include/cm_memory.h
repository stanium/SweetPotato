//
// Created by sin on 19-1-27.
//

#ifndef SWEETPOTATO_CM_MEMORY_H
#define SWEETPOTATO_CM_MEMORY_H

#include "cm_cfg.h"
#include "malloc.h"
BEGIN_DECLS
void *cm_malloc(size_t size);
void *cm_calloc(size_t num,size_t sizeOftype);
void *cm_realloc(void *old, size_t newsize);
void cm_free(void *p);
END_DECLS
#endif //SWEETPOTATO_CM_MEMORY_H
