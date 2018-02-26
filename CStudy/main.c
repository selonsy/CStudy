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





