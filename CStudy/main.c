#pragma once
#include "head.h"
#include "lib.h"

void c_test_for_study();

void fn1()
{
	extern int x;
	printf("fn1(): x=%d\n", x);
}
int main() 
{
#pragma region History

	//printf("Hello World!\n");

	//printf("%d年%s闰年\n",1900,is_leap_year(1900)==1?"是":"不是");

	//triangle_print(10);

	//multi_9();

	//su_shu(1000);

	//the_day_of_year(2008, 8, 8);

	//monkey_eat_peach(1);	

	//printf("第5个人的年龄是%d岁\n", factorial_test(5));

	//xiaoming_dache(12, 9, 18);

	//array_test();

	//paixu_maopao();

	//my_test1();

	//printf("hello world!\n");

#pragma endregion

	////NO.1
	//int nums[] = { 2,7,11,15 };
	//int *p = twoSum(nums, 4, 9);
	//printf("[%d,%d]",p[0],p[1]);
	
	////NO.2	
	//int nums1[] = { 5 };// { 2,4,3 };
	//int nums2[] = { 5 };// { 5,6,4 };
	//PNode head_node1 = (PNode)malloc(sizeof(Node) / sizeof(char));
	//PNode head_node2 = (PNode)malloc(sizeof(Node) / sizeof(char));
	//PNode node_1,node_2;
	//node_1 = head_node1;
	//node_2 = head_node2;
	//head_node1->data = nums1[0];
	//head_node1->next = NULL;	
	//head_node2->data = nums2[0];
	//head_node2->next = NULL;
	//for (int i = 1; i < sizeof(nums1)/sizeof(int); i++)
	//{
	//	PNode node_t = (PNode)malloc(sizeof(Node) / sizeof(char));
	//	node_t->data = nums1[i];		
	//	node_1->next = node_t;
	//	node_1 = node_t;
	//}
	//for (int i = 1; i < sizeof(nums2) / sizeof(int); i++)
	//{
	//	PNode node_t = (PNode)malloc(sizeof(Node) / sizeof(char));
	//	node_t->data = nums2[i];
	//	node_2->next = node_t;
	//	node_2 = node_t;
	//}
	//node_1->next = NULL;
	//node_2->next = NULL;
	//	
	//PNode result = addTwoNumbers(head_node1, head_node2);	
	//DisPlay(result);


	c_test_for_study();

	system("pause");
	return 0;
}

//语法测试校验
void c_test_for_study() 
{
	int x = 10;
	if (x>0)
	{
		int  x = 100;
		x /= 2;
		printf("if语句内, x=%d\n", x);
	}
	printf("main方法内, x=%d\n", x);
	fn1();
	return 0;

//	int input;
//	scanf("%d", &input);
//	if (input > 10) goto OVER10;
//	else goto LESS10;
//OVER10:
//	printf(">10\n"); c_test_for_study(); return;
//LESS10:
//	printf("<10\n"); c_test_for_study(); return;
}

int x = 77;





