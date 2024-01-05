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

/* 动态数组的指定位置的插入 */
int dynamicArrayAppointPosInsertData(dynamicArray *pArray, int pos, ELEMENTTYPE val)
{

}

/* 动态数组修改指定位置的值 */
int dynamicArrayModifyAppointPosData(dynamicArray *pArray, int pos, ELEMENTTYPE val)
{

}

/* 动态数组删除数据,默认情况下删除最末尾的元素 */
int dynamicArrayDeleteData(dynamicArray *pArray)
{
    return dynamicArrayDeleteAppointData(pArray, pArray->len);

}

/* 动态数组删除指定位置上的数据 */
int dynamicArrayDeleteAppointPosData(dynamicArray *pArray, int pos)
{

}

/* 动态数组删除指定数据 */
int dynamicArrayDeleteAppointData(dynamicArray *pArray, ELEMENTTYPE val)
{

}

/* 动态数组的销毁 */
int dynamicArrayDestory(dynamicArray *pArray, int pos)
{

}

/* 获取数组的大小 */
int dynamicArrayGetSize(dynamicArray *pArray, int *pSize)
{

}

/* 获取动态数组的容量 */
int dynamicArrayGetCapacity(dynamicArray *pArray, int *pCapacity)
{

}

/* 获取动态数组指定位置的元素 */
int dynamicArrayGetAppointPosData(dynamicArray *pArray, int pos, ELEMENTTYPE *pVal)
{

}

/* 数组的排序 */
int dynamicArrayAppointValSort(dynamicArray *pArray)
{

}
