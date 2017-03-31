#include "../header/sort.h" 

/* bo10-2.c ��������ĺ��� */

int Partition(SqList *L, int low, int high)
{ /* ����˳���L���ӱ�r[low..high]�ļ�¼�������¼��λ���������� */
  /* ����λ�ã���ʱ����֮ǰ���󣩵ļ�¼������С���������㷨10.6(b) */
	KeyType pivotkey;
	(*L).r[0] = (*L).r[low]; /* ���ӱ�ĵ�һ����¼�������¼ */
	pivotkey = (*L).r[low].key; /* �����¼�ؼ��� */
	while (low< high)
	{ /* �ӱ�����˽�������м�ɨ�� */
		while (low<high && (*L).r[high].key >= pivotkey)
			--high;
		(*L).r[low] = (*L).r[high]; /* ���������¼С�ļ�¼�Ƶ��Ͷ� */
		while (low<high && (*L).r[low].key <= pivotkey)
			++low;
		(*L).r[high] = (*L).r[low]; /* ���������¼��ļ�¼�Ƶ��߶� */
	}
	(*L).r[low] = (*L).r[0]; /* �����¼��λ */
	return low; /* ��������λ�� */
}

void QSort(SqList *L, int low, int high)
{ /* ��˳���L�е�������L.r[low..high]�����������㷨10.7 */
	int pivotloc;
	if (low < high)
	{ /* ���ȴ���1 */
		pivotloc = Partition(L, low, high); /* ��L.r[low..high]һ��Ϊ�� */
		QSort(L, low, pivotloc - 1); /* �Ե��ӱ�ݹ�����pivotloc������λ�� */
		QSort(L, pivotloc + 1, high); /* �Ը��ӱ�ݹ����� */
	}
}

void QuickSort(SqList *L)
{ /* ��˳���L�����������㷨10.8 */
	QSort(L, 1, (*L).length);
}
