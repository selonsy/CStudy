#include "../header/sort.h" 

/* ��˳���L��ֱ�Ӳ��������㷨10.1 */
void InsertSort(SqList *L)
{
	//{ { 49,1 },{ 38,2 },{ 65,3 },{ 97,4 },{ 76,5 },{ 13,6 },{ 27,7 },{ 49,8 } };
	int i, j;
	for (i = 2; i <= (*L).length; ++i)
	{
		if LT((*L).r[i].key, (*L).r[i - 1].key)		/* "<",�轫L.r[i]���������ӱ� */
		{
			(*L).r[0] = (*L).r[i];					/* ����Ϊ�ڱ� */
			for (j = i - 1; LT((*L).r[0].key, (*L).r[j].key); --j)
			{
				(*L).r[j + 1] = (*L).r[j];			/* ��¼���� */
			}
			(*L).r[j + 1] = (*L).r[0];				/* ���뵽��ȷλ�� */
		}
		//��ӡ��ÿ������������
		//print(*L);
	}
}

/* ��˳���L���۰���������㷨10.2 */
void BInsertSort(SqList *L)
{ 
	//printf("\n");
	int i, j, m, low, high;
	for (i = 2; i <= (*L).length; ++i)
	{
		(*L).r[0] = (*L).r[i];				/* ��L.r[i]�ݴ浽L.r[0] */
		low = 1;
		high = i - 1;
		while (low <= high)					/* ��r[low..high]���۰������������λ�� */
		{				
			m = (low + high) / 2;			/* �۰� */
			if LT((*L).r[0].key, (*L).r[m].key)
				high = m - 1;				/* ������ڵͰ��� */
			else
				low = m + 1;				/* ������ڸ߰��� */
		}
		for (j = i - 1; j >= high + 1; --j)
		{
			(*L).r[j + 1] = (*L).r[j];		/* ��¼���� */
		}		
		(*L).r[high + 1] = (*L).r[0];		/* ���� */
		//��ӡ��ÿ������������
		//print(*L);
	}
	//printf("\n");
}

/* 2_·�������� */
void P2_InsertSort(SqList *L)
{ 
	int i, j, first, final;
	RedType *d;
	d = (RedType*)malloc((*L).length * sizeof(RedType));		/* ����L.length����¼����ʱ�ռ� */
	d[0] = (*L).r[1];											/* ��L�ĵ�1����¼Ϊd���ź���ļ�¼(��λ��[0]) */
	first = final = 0;										    /* first��final�ֱ�ָʾd���ź���ļ�¼�ĵ�1�������1����¼��λ�� */
	for (i = 2; i <= (*L).length; ++i)							/* ���ν�L�ĵ�2�������1����¼����d�� */
	{	
		if ((*L).r[i].key < d[first].key)						/* �����¼С��d����Сֵ���嵽d[first]֮ǰ(�����ƶ�d�����Ԫ��) */
		{ 
			first = (first - 1 + (*L).length) % (*L).length;	/* ��dΪѭ������ */
			d[first] = (*L).r[i];
		}
		else if ((*L).r[i].key > d[final].key)					/* �����¼����d�����ֵ���嵽d[final]֮��(�����ƶ�d�����Ԫ��) */
		{ 
			final = final + 1;
			d[final] = (*L).r[i];
		}
		else													/* �����¼����d����Сֵ��С��d�����ֵ���嵽d���м�(��Ҫ�ƶ�d�����Ԫ��) */
		{ 
			j = final++;										/* �ƶ�d��β��Ԫ���Ա㰴������¼ */
			while ((*L).r[i].key < d[j].key)
			{
				d[(j + 1) % (*L).length] = d[j];
				j = (j - 1 + (*L).length) % (*L).length;
			}
			d[j + 1] = (*L).r[i];
		}
	}
	for (i = 1; i <= (*L).length; i++)							/* ��d����L.r */
	{
		(*L).r[i] = d[(i + first - 1) % (*L).length];			/* ���Թ�ϵ */
	}		
}
