#ifndef    _SORT_H			//一般使用文件名的大写
#define    _SORT_H			//解决重复定义的问题:错误信息>redefinition; different basic types
#include <stdio.h>
#include<malloc.h>			/* malloc()等 */

#define MAXSIZE 20			/* 一个用作示例的小顺序表的最大长度 */
#define SIZE 100			/* 静态链表容量 */
#define MAX_NUM_OF_KEY 8	/* 关键字项数的最大值 */
#define RADIX 10			/* 关键字基数，此时是十进制整数的基数 */
#define MAX_SPACE 1000
typedef int KeyType;		/* 定义关键字类型为整型 */
typedef int InfoType;		/* 定义其它数据项的类型 */
typedef int ArrType[RADIX]; /* 指针数组类型 */
typedef char KeysType;		/* 定义关键字类型为字符型 */

#define EQ(a,b) ((a)==(b))
#define LT(a,b) ((a)<(b))
#define LQ(a,b) ((a)<=(b))

typedef struct
{
	KeyType key;		/* 关键字项 */
	InfoType otherinfo; /* 其它数据项，具体类型在主程中定义 */
}RedType;				/* 记录类型 */

typedef struct
{
	RedType r[MAXSIZE + 1]; /* r[0]闲置或用作哨兵单元 */
	int length;				/* 顺序表长度 */
}SqList;					/* 顺序表类型 */

typedef struct
{
	RedType rc;				/* 记录项 */
	int next;				/* 指针项 */
}SLNode;					/* 表结点类型 */

typedef struct
{
	SLNode r[SIZE];			/* 0号单元为表头结点 */
	int length;				/* 链表当前长度 */
}SLinkListType;				/* 静态链表类型 */

typedef struct
{
	KeysType keys[MAX_NUM_OF_KEY];  /* 关键字 */
	InfoType otheritems;			/* 其它数据项 */
	int next;
}SLCell;							/* 静态链表的结点类型 */

typedef struct
{
	SLCell r[MAX_SPACE];			/* 静态链表的可利用空间，r[0]为头结点 */
	int keynum;						/* 记录的当前关键字个数 */
	int recnum;						/*  静态链表的当前长度 */
}SLList;							/* 静态链表类型 */


//Common
void print(SqList L);

//插入排序
void InsertSort(SqList *L);
void BInsertSort(SqList *L);
void P2_InsertSort(SqList *L);

//快速排序
void QSort(SqList *L, int low, int high);
void QuickSort(SqList *L);


#endif