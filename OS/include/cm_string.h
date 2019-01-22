//
// Created by sine on 19-1-22.
//

#ifndef SWEETPOTATO_CM_STRING_H
#define SWEETPOTATO_CM_STRING_H

/**
 * 内部使用了malloc分配内存，不需要使用返回字符串时，需要使用free释放内存空间，防止内存泄漏
 * @param s 所要复制的字符串
 * @return 成功则返回指向复制字符串分配的空间；失败则返回NULL
 */
char * cm_strdup(const char *s)
{
    if(s){
        return strdup(s);
    }
    return NULL;
}


#endif //SWEETPOTATO_CM_STRING_H
