#include <stdio.h>
#include "dynamicArray.h"
#include "dynamicArrayStack.h"

#define DEFAULT_SIZE 10

/* 栈的初始化 */
int dynamicArrayStackInit(dynamicArrayStack *pStack)
{
    /* 就是动态数组的初始化 */
    return dynamicArrayInit(pStack, DEFAULT_SIZE);

}

/* 栈的压栈 放数据 */
int dynamicArrayStackPush(dynamicArrayStack *pStack, ELEMENTTYPE val)
{
    /* 相当于动态数组的插入数据 */
    return dynamicArrayInsertData(pStack, val);

}

/* 查看栈顶元素 */
int dynamicArrayStackTop(dynamicArrayStack *pStack, ELEMENTTYPE *pVal)
{
    /* 相当于动态数组的查看数组尾部的数据 */
    return dynamicArrayGetAppointPosData(pStack, pStack->len - 1, pVal);

}

/* 栈的压栈 */
int dynamicArrayStackPop(dynamicArrayStack *pStack)
{
    /* 相当于删除动态数组中的数据 */
    return dynamicArrayDeleteData(pStack);

}

/* 栈是否为空 */
int dynamicArrayStackIsEmpty(dynamicArrayStack *pStack)
{
    int size = 0;
    dynamicArrayGetSize(pStack, &size);
    return size == 0 ? 1 : 0;

}

/* 栈的大小 */
int dynamicArrayStackGetSize(dynamicArrayStack *pStack, ELEMENTTYPE *pSize)
{
    return dynamicArrayGetSize(pStack, pSize);

}

/* 栈的销毁 */
int dynamicArrayStackDestory(dynamicArrayStack *pStack)
{
    /* 直接调用动态数组的销毁 */
    return dynamicArrayDestory(pStack);

}


