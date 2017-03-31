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
	for (i = 0; i<N; i++) /* 给l1.r赋值 */
		l1.r[i + 1] = d[i];
	l1.length = N;
	l2 = l3 = l1; /* 复制顺序表l2、l3与l1相同 */
	printf("排序前:\n");
	print(l1);
	InsertSort(&l1);
	printf("直接插入排序后:\n");
	print(l1);
	BInsertSort(&l2);
	printf("折半插入排序后:\n");
	print(l2);
	P2_InsertSort(&l3);
	printf("2_路插入排序后:\n");
	print(l3);
	
	//加上的话,按F5也会停下来.不加的话需要按ctrl+F5
	system("pause");
	return 0;
}

#pragma region 相关知识点

//内部排序

//一.按照依据的不同的原则:

//1.插入排序:
//1.1 直接插入排序(O(n^2))
//1.2 折半插入排序(O(n^2))
//1.3 2-路插入排序
//1.4 表插入排序(O(n^2))
//1.5 希尔排序

//2.交换排序:
//2.1 冒泡排序(Bubble Sort)(O(n^2))
//2.2 快速排序(Quick Sort)(O(nlogn)) 注:在所有同数量级的排序方法中,其平均性能最好.

//3.选择排序:
//3.1 简单选择排序(Simple Selection Sort)(O(n^2))
//3.2 树形选择排序(Tree Selection Sort)(O(nlogn))
//3.3 堆排序(Heap Sort)(O(nlogn))

//4.归并排序(Merging Sort):
//4.1 2-路归并排序(O(nlogn))

//5.基数排序(Radix Sort):
//5.1 多关键字排序
//5.2 链式基数排序

//二.按照所需的工作量:

//1.简单的排序:O(n^2)

//2.先进的排序:O(nlogn)

//3.基数排序:O(d*n)


//外部排序:

#pragma endregion