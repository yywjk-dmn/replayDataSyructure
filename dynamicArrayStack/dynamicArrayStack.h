#ifndef __DYNAMIC_ARRAY_STACK_H_
#define __DYNAMIC_ARRAY_STACK_H_

#include "common.h"

typedef dynamicArray dynamicArrayStack;

/* 栈的初始化 */
int dynamicArrayStackInit(dynamicArrayStack *pStack);

/* 栈的压栈 放数据 */
int dynamicArrayStackPush(dynamicArrayStack *pStack, ELEMENTTYPE val);

/* 查看栈顶元素 */
int dynamicArrayStackTop(dynamicArrayStack *pStack, ELEMENTTYPE *pVal);

/* 栈的压栈 */
int dynamicArrayStackPop(dynamicArrayStack *pStack);

/* 栈是否为空 */
int dynamicArrayStackIsEmpty(dynamicArrayStack *pStack);

/* 栈的大小 */
int dynamicArrayStackGetSize(dynamicArrayStack *pStack, ELEMENTTYPE *pSize);

/* 栈的销毁 */
int dynamicArrayStackDestory(dynamicArrayStack *pStack);






#endif