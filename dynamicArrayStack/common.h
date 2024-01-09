#ifndef __COMMON_H_
#define __COMMON_H_

typedef void * ELEMENTTYPE;

/* 定义动态数组里的东西 */
typedef struct dynamicArray
{
    /* 定义数组的数据 */
    ELEMENTTYPE *data;
    /* 定义数组的容量 */
    int capacity;
    /* 定义数组的长度 */
    int len;
} dynamicArray;


#endif