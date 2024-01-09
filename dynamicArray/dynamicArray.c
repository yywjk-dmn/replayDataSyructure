#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dynamicArray.h"

/* 状态码 */
enum STATUS_CODE
{
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROE,
    INVALID_ACCESS,
};

#define BUFFER_SIZE 10

/* 静态函数前置声明 */
/* 动态数组的扩容 */
static int expandDynamicCapacity(dynamicArray *pArray);
/* 动态数组的缩容 */
static int shrinkDynamicCapacity(dynamicArray *pArray);

/* 动态数组的初始化 */
int dynamicArrayInit(dynamicArray *pArray, int capacity)
{
    #if 0
    if (pArray == NULL)
    {
        return NULL_PTR;
    }

    /* 判断是否有违法空间值 */
    if (capacity < 0)
    {
        capacity = DEFAULT_SIZE;
    }

    /* 开辟空间 */
    pArray->data = (ELEMENTTYPE *)malloc(sizeof(ELEMENTTYPE) * capacity);
    if (pArray->data == NULL)
    {
        return MALLOC_ERROE;
    }
    /* 清除脏数据 */
    memset(pArray->data, 0, sizeof(ELEMENTTYPE) * capacity);

    /* 初始化动态数组 */
    pArray->len = NULL;
    pArray->capacity = capacity;

    return ON_SUCCESS;
    #else
    if (pArray == NULL)
    {
        return NULL_PTR;
    }

    if (capacity < 0)
    {
        capacity = BUFFER_SIZE;
    }

    pArray->data = (ELEMENTTYPE *)malloc(sizeof(ELEMENTTYPE) * capacity);
    if (pArray->data == NULL)
    {
        return MALLOC_ERROE;
    }
    memset(pArray->data, 0, sizeof(ELEMENTTYPE) * capacity);

    /* 动态数组的初始化 */
    pArray->len = 0;
    pArray->capacity = capacity;


    return ON_SUCCESS;
    #endif
    

}

/* 动态数组的插入,默认插入到数组的末尾 */
int dynamicArrayInsertData(dynamicArray *pArray, ELEMENTTYPE val)
{
    return dynamicArrayAppointPosInsertData(pArray, pArray->len, val);
}

/* 动态数组的扩容 */
/* 扩容就是为了扩大动态数组的容量 将动态数组的容量扩大 然后将原有的数据放进去 进行容量的更新*/
static int expandDynamicCapacity(dynamicArray *pArray)
{
    int ret = 0;

    /* 定义一个新的容量 */
    int newexpandCapacity = pArray->capacity + (pArray->capacity >> 1);

    /* 将数据备份到一个指针 */
    ELEMENTTYPE *tempPtr = pArray->data;

    /* 将动态数组里的data清空 扩内存 */
    pArray->data = (ELEMENTTYPE *)malloc(sizeof(ELEMENTTYPE) * newexpandCapacity);
    if (pArray->data == NULL)
    {
        return MALLOC_ERROE;
    }

    /* 将拷贝的东西重新放到动态数组里 */
    for (int idx = 0; idx < pArray->capacity; idx++)
    {
        pArray->data[idx] = tempPtr[idx]; 
    }
    /* 将之前的指针释放 */
    if (tempPtr == NULL)
    {
        free(tempPtr);
        tempPtr = NULL;
    }

    /* 数组的容量更新 */
    pArray->capacity = newexpandCapacity;

    return ON_SUCCESS;
}

/* 动态数组的缩容 */
static int shrinkDynamicCapacity(dynamicArray *pArray)
{
    int ret = 0;

    /* 定义一个新的容量 */
    int needshrinkCapacity = pArray->capacity - (pArray->capacity >> 1);

    /* 定义一个指针将原来的数据放进去 */
    ELEMENTTYPE *temptr = pArray->data;

    /* 将原来放数据的空间清空 */
    pArray->data = (ELEMENTTYPE *)malloc(sizeof(ELEMENTTYPE) * needshrinkCapacity);
    if (pArray->data == NULL)
    {
        return MALLOC_ERROE;
    }

    /* 将拷贝的数据放在新的容量中 */
    for (int idx = 0; idx < pArray->capacity; idx++)
    {
        pArray->data[idx] = temptr[idx];
    }

    /* 释放之前的临时指针 */
    if (temptr != NULL)
    {
        free(temptr);
        temptr = NULL;
    }

    /* 动态数组的容量更新 */
    pArray->capacity = needshrinkCapacity;

    return ON_SUCCESS;

}

/* 动态数组的指定位置的插入 */
int dynamicArrayAppointPosInsertData(dynamicArray *pArray, int pos, ELEMENTTYPE val)
{
    /* 先对数组判空 */
    if (pArray == NULL)
    {
        return NULL_PTR;
    }
    /* 判断位置是否合法 */
    if (pos < 0 || pos > pArray->len)
    {
        return INVALID_ACCESS;
    }

    /* 满足扩容的条件 */
    if (pArray->len + (pArray->len >> 1) >= pArray->capacity)
    {
        /* 开始扩容 */
        expandDynamicCapacity(pArray);
    }

    /* 数据后移 将要插入数据的地方预留出来 */
    for (int idx = pArray->len; idx > pos; idx--)
    {
        pArray->data[idx] = pArray->data[idx - 1];
    }

    /* 将要插入的数据插入 */
    pArray->data[pos] = val;

    /* 更新数组的长度 */
    (pArray->len)++;

    return ON_SUCCESS;

}

/* 动态数组修改指定位置的值 */
int dynamicArrayModifyAppointPosData(dynamicArray *pArray, int pos, ELEMENTTYPE val)
{
    /* 对数组判空 */
    if (pArray == NULL)
    {
        return NULL_PTR;
    }
    /* 对位置判空 */
    if (pos < 0 || pos < pArray->len)
    {
        return INVALID_ACCESS;
    }

    /* 更新数据 */
    pArray->data[pos] = val;

    return ON_SUCCESS;

}

/* 动态数组删除数据,默认情况下删除最末尾的元素 */
int dynamicArrayDeleteData(dynamicArray *pArray)
{
    return dynamicArrayDeleteAppointData(pArray, pArray->len);
}

/* 动态数组删除指定位置上的数据 */
int dynamicArrayDeleteAppointPosData(dynamicArray *pArray, int pos)
{
    /* 对数组判空 */
    if (pArray == NULL)
    {
        return NULL_PTR;
    }
    /* 判断位置是否合法 */
    if (pos < 0 || pos > pArray->len)
    {
        return INVALID_ACCESS;
    }

    /* 删除数据，数据前移 */
    for (int idx = pos; idx < pArray->len; idx++)
    {
        pArray->data[idx] = pArray->data[idx++];
    }
    
    /* 缩容 */
    if (pArray->len - (pArray->len >> 1) < pArray->capacity)
    {
        shrinkDynamicCapacity(pArray);
    }

    /* 更新数组的长度 */
    (pArray->len)--;

    return ON_SUCCESS;

    

}

/* 比较两个元素是否相同 */
static int compareFunc(int val1, int val2)
{
    if (val1 == val2)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}
/* 动态数组删除指定数据 */
int dynamicArrayDeleteAppointData(dynamicArray *pArray, ELEMENTTYPE val)
{
    for (int idx = 0; idx < pArray->len; idx++)
    {
        int ret = compareFunc(val, pArray->data[idx]);
        if (ret == 1)
        {
            dynamicArrayDeleteAppointPosData(pArray, idx);
        }

    }
    return ON_SUCCESS;


}

/* 动态数组的销毁 */
int dynamicArrayDestory(dynamicArray *pArray, int pos)
{
    if (pArray == NULL)
    {
        return  NULL_PTR;
    }

    if (pArray->data != NULL)
    {
        free(pArray->data);
        pArray->data = NULL;
    }

    return ON_SUCCESS;

}

/* 获取数组的大小 */
int dynamicArrayGetSize(dynamicArray *pArray, int *pSize)
{
    if (pArray == NULL)
    {
        return NULL_PTR;
    }

    if (pSize)
    {
        *pSize = pArray->len;
    }

    return pArray->len;
}

/* 获取动态数组的容量 */
int dynamicArrayGetCapacity(dynamicArray *pArray, int *pCapacity)
{
    if (pArray == NULL)
    {
        return NULL_PTR;
    }

    if (pCapacity)
    {
        *pCapacity = pArray->capacity;
    }

    return ON_SUCCESS;

}

/* 获取动态数组指定位置的元素 */
int dynamicArrayGetAppointPosData(dynamicArray *pArray, int pos, ELEMENTTYPE *pVal)
{
    if (pArray == NULL)
    {
        return NULL_PTR;
    }
    /* 判断位置的合法性 */
    if (pos < 0 || pos > pArray->len)
    {
        return INVALID_ACCESS;
    }

    if (pVal)
    {
        *pVal = pArray->data[pos];
    }

    return ON_SUCCESS;


}

/* 数组的排序 */
int dynamicArrayAppointValSort(dynamicArray *pArray)
{
    int ret = 0;


    return ret;

}
