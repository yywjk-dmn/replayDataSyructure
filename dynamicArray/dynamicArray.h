#ifndef __DYNAMIC_ARRAY_H_
#define __DYNAMIC_ARRAY_H_
/* 防止头文件重复 */

typedef int ELEMENTTYPE;

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


/* 动态数组的初始化 */
int dynamicArrayInit(dynamicArray *pArray, int capacity);

/* 动态数组的插入,默认插入到数组的末尾 */
int dynamicArrayInsertData(dynamicArray *pArray, ELEMENTTYPE val);

/* 动态数组的指定位置的插入 */
int dynamicArrayAppointPosInsertData(dynamicArray *pArray, int pos, ELEMENTTYPE val);

/* 动态数组修改指定位置的值 */
int dynamicArrayModifyAppointPosData(dynamicArray *pArray, int pos, ELEMENTTYPE val);

/* 动态数组删除数据,默认情况下删除最末尾的元素 */
int dynamicArrayDeleteData(dynamicArray *pArray);

/* 动态数组删除指定位置上的数据 */
int dynamicArrayDeleteAppointPosData(dynamicArray *pArray, int pos);

/* 动态数组删除指定数据 */
int dynamicArrayDeleteAppointData(dynamicArray *pArray, ELEMENTTYPE val);

/* 动态数组的销毁 */
int dynamicArrayDestory(dynamicArray *pArray, int pos);

/* 获取数组的大小 */
int dynamicArrayGetSize(dynamicArray *pArray, int *pSize);

/* 获取动态数组的容量 */
int dynamicArrayGetCapacity(dynamicArray *pArray, int *pCapacity);

/* 获取动态数组指定位置的元素 */
int dynamicArrayGetAppointPosData(dynamicArray *pArray, int pos, ELEMENTTYPE *pVal);

/* 数组的排序 */
int dynamicArrayAppointValSort(dynamicArray *pArray);


#endif