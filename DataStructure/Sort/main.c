#include "./header/sort.h"
#define N 8

int main()
{
	/*if (27.9 * 3 > 83.700000){
		printf("%.2f", 27.9 * 3);
	}
	else {
		printf("ssssssssssssssssss");
	}
	*/

	RedType d[N] = { { 49,1 },{ 38,2 },{ 65,3 },{ 97,4 },{ 76,5 },{ 13,6 },{ 27,7 },{ 49,8 } };
	SqList l1, l2, l3;
	int i;
	for (i = 0; i<N; i++) /* ��l1.r��ֵ */
		l1.r[i + 1] = d[i];
	l1.length = N;
	l2 = l3 = l1; /* ����˳���l2��l3��l1��ͬ */
	printf("����ǰ:\n");
	print(l1);
	InsertSort(&l1);
	printf("ֱ�Ӳ��������:\n");
	print(l1);
	BInsertSort(&l2);
	printf("�۰���������:\n");
	print(l2);
	P2_InsertSort(&l3);
	printf("2_·���������:\n");
	print(l3);
	
	//���ϵĻ�,��F5Ҳ��ͣ����.���ӵĻ���Ҫ��ctrl+F5
	system("pause");
	return 0;
}

#pragma region ���֪ʶ��

//�ڲ�����

//һ.�������ݵĲ�ͬ��ԭ��:

//1.��������:
//1.1 ֱ�Ӳ�������(O(n^2))
//1.2 �۰��������(O(n^2))
//1.3 2-·��������
//1.4 ���������(O(n^2))
//1.5 ϣ������

//2.��������:
//2.1 ð������(Bubble Sort)(O(n^2))
//2.2 ��������(Quick Sort)(O(nlogn)) ע:������ͬ�����������򷽷���,��ƽ���������.

//3.ѡ������:
//3.1 ��ѡ������(Simple Selection Sort)(O(n^2))
//3.2 ����ѡ������(Tree Selection Sort)(O(nlogn))
//3.3 ������(Heap Sort)(O(nlogn))

//4.�鲢����(Merging Sort):
//4.1 2-·�鲢����(O(nlogn))

//5.��������(Radix Sort):
//5.1 ��ؼ�������
//5.2 ��ʽ��������

//��.��������Ĺ�����:

//1.�򵥵�����:O(n^2)

//2.�Ƚ�������:O(nlogn)

//3.��������:O(d*n)


//�ⲿ����:

#pragma endregion