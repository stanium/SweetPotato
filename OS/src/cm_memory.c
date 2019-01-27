//
// Created by sin on 19-1-27.
//
/**只分配内存，不初始化*/
void *cm_malloc(size_t size){
    void *net= malloc(size);
    if(!net){
        printf("cm_malloc fail\n");
    }
    return net;
}
/**分配内存，并设置为0*/
void *cm_calloc(size_t num,size_t sizeOftype){
    void *net=NULL;
    if(num&&sizeOftype) {
        net = calloc(num, sizeOftype);
        if (!net) {
            printf("cm_calloc fail\n");
        }
    }
    return net;
}

/**调整内存大小*/
void *cm_realloc(void *old, size_t newsize){
    void *net=NULL;

    if(newsize)
    {
        if(old) {//如果old不为空，则调整内存大小
            net = realloc(old, newsize);
            if (!net) {
                printf("realloc fail\n");
            }
        }else{//若为空，则分配newsize 个大小为1的空间，并设置为0
            net=calloc(newsize,1);
            if(!net) {
                printf("calloc fail\n");
            }
        }
    }else if(old){
        free(old);
    }
    return net;
}

void cm_free(void *p){

}
