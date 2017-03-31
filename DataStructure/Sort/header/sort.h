#ifndef    _SORT_H			//һ��ʹ���ļ����Ĵ�д
#define    _SORT_H			//����ظ����������:������Ϣ>redefinition; different basic types
#include <stdio.h>
#include<malloc.h>			/* malloc()�� */

#define MAXSIZE 20			/* һ������ʾ����С˳������󳤶� */
#define SIZE 100			/* ��̬�������� */
#define MAX_NUM_OF_KEY 8	/* �ؼ������������ֵ */
#define RADIX 10			/* �ؼ��ֻ�������ʱ��ʮ���������Ļ��� */
#define MAX_SPACE 1000
typedef int KeyType;		/* ����ؼ�������Ϊ���� */
typedef int InfoType;		/* ������������������� */
typedef int ArrType[RADIX]; /* ָ���������� */
typedef char KeysType;		/* ����ؼ�������Ϊ�ַ��� */

#define EQ(a,b) ((a)==(b))
#define LT(a,b) ((a)<(b))
#define LQ(a,b) ((a)<=(b))

typedef struct
{
	KeyType key;		/* �ؼ����� */
	InfoType otherinfo; /* ������������������������ж��� */
}RedType;				/* ��¼���� */

typedef struct
{
	RedType r[MAXSIZE + 1]; /* r[0]���û������ڱ���Ԫ */
	int length;				/* ˳����� */
}SqList;					/* ˳������� */

typedef struct
{
	RedType rc;				/* ��¼�� */
	int next;				/* ָ���� */
}SLNode;					/* �������� */

typedef struct
{
	SLNode r[SIZE];			/* 0�ŵ�ԪΪ��ͷ��� */
	int length;				/* ����ǰ���� */
}SLinkListType;				/* ��̬�������� */

typedef struct
{
	KeysType keys[MAX_NUM_OF_KEY];  /* �ؼ��� */
	InfoType otheritems;			/* ���������� */
	int next;
}SLCell;							/* ��̬����Ľ������ */

typedef struct
{
	SLCell r[MAX_SPACE];			/* ��̬����Ŀ����ÿռ䣬r[0]Ϊͷ��� */
	int keynum;						/* ��¼�ĵ�ǰ�ؼ��ָ��� */
	int recnum;						/*  ��̬����ĵ�ǰ���� */
}SLList;							/* ��̬�������� */


//Common
void print(SqList L);

//��������
void InsertSort(SqList *L);
void BInsertSort(SqList *L);
void P2_InsertSort(SqList *L);

//��������
void QSort(SqList *L, int low, int high);
void QuickSort(SqList *L);


#endif