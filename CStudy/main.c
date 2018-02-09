#include "head.h"

#pragma region 练手的函数
//判断闰年
int is_leap_year(int year);
//求水仙花数
int shui_xian_hua();
//循环计算1-2+3-4+5-6+…-100的值？
int add1();
//三角形打印
/*
打印指定层数的正三角形,如下图所示:
		*
	   ***
	  *****
	 *******
此时,num等于4.
*/
int triangle_print(int num);
/*
打印指定层数的直角三角形,如下图所示:
*
***
*****
*******
此时,num等于4.
*/
int triangle_print1(int num);
//倒叙输出99乘法表
//如:
//9*1=9 9*2=18  ```9*9=81
//````
//1*1=1
int multi_9();
//输出x以内的素数
int su_shu(int max);
//计算2008年8月8日这一天，是该年中的第几天.
int the_day_of_year(int year, int month, int day);
//求阶乘
int factorial(int n);
/*
猴子第一天摘下N个桃子，当时就吃了一半，还不过瘾，就又多吃了一个。
第二天又将剩下的桃子吃掉一半，又多吃了一个。以后每天都吃前一天剩下的一半零一个。
到第10天在想吃的时候就剩一个桃子了,问第一天共摘下来多少个桃子？并反向打印每天所剩桃子数。
*/
int monkey_eat_peach(int n);
/*
有5个人坐在一起，问第5个人多少岁？他说比第4个人大2岁。
问第4个人岁数，他说比第3个人大2岁。问第3个人，又说比第2人大两岁。
问第2个人，说比第1个人大两岁。最后 问第1个人，他说是10岁。请问第5个人多大？

程序分析：
利用递归的方法，递归分为回推和递推两个阶段。要想知道第5个人岁数，需知道第4人的岁数，
依次类推，推到第1人（10岁），再往回推。
*/
int factorial_test(int n);
/*
综合练习:
1. 每公里单价计费2.3元
2. 起步价13元(包含3公里)
3. 晚上23点(含)至次日凌晨5点(不含)打车，每公里单价计费加收20%。
4. 每次乘车加收1元钱的燃油附加税。
小明每天上下班都要打车，公司和家的距离为12公里，上午上班时间为9点，下午下班时间为6点。
请编写一个小程序计算小明每天打车的总费用。
*/
int xiaoming_dache(int total_length,int time_go,int time_back);
#pragma endregion

#pragma region 练手的函数2(不带声明)
//数组测试
int array_test() 
{
	int my_array[3] = {1,2,3};
	printf("%d %d\n",my_array[1],sizeof(my_array));

	return 0;
}
//冒泡排序
int paixu_maopao()
{
	double arr[] = { 1.78, 1.77, 1.82, 1.79, 1.85, 1.75, 1.86, 1.77, 1.81, 1.80 };
	int i, j;
	printf("\n************排队前*************\n");
	for (i = 0;i<10;i++)
	{
		if (i != 9)
			printf("%.2f, ", arr[i]);  //%.2f表示小数点后精确到两位
		else
			printf("%.2f", arr[i]);    //%.2f表示小数点后精确到两位
	}
	for (i = 9; i >= 0; i--)
	{
		for (j = 0;j <= i;j++)
		{
			if (arr[j]>arr[j + 1])      //当前面的数比后面的数大时
			{
				double temp;//定义临时变量temp
				temp = arr[j];//将前面的数赋值给temp
				arr[j] = arr[j + 1];//前后之数颠倒位置
				arr[j + 1] = temp;//将较大的数放在后面    
			}
		}
	}
	printf("\n************排队后*************\n");
	for (i = 0;i<10;i++)
	{
		if (i != 9)
			printf("%.2f, ", arr[i]);  //%.2f表示小数点后精确到两位     
		else
			printf("%.2f", arr[i]);    //%.2f表示小数点后精确到两位
	}
	return 0;
}
//计算二维数组的对角线的和
int count_er_wei()
{
	int arr[3][3] = { { 1,2,3 },{ 4,5,6 },{ 7,8,9 } };
	int i, j;
	int sum = 0;
	for (i = 0;i<3;i++)
	{
		for (j = 0;j<3;j++)
		{
			if ((i == 0 && j == 2) || (i == 2 && j == 0))
			{
				sum += arr[i][j];
			}
			else if (i == j)
			{
				sum += arr[i][j];
			}
			else
			{

			}
		}
	}
	printf("对角线元素之和是：%d\n", sum);
	return 0;
}
/*
在一个长度为10的整型数组里面，保存了班级10个学生的考试成绩。
要求编写5个函数，分别实现计算考试的总分，最高分，最低分，平均分和考试成绩降序排序。
*/
int my_test1() 
{
	int score[10] = { 67,98,75,63,82,79,81,91,66,84 };
	int i,j,total=0,max=score[0],min=score[0];

	for (i = 0; i < 10; i++)
	{
		total += score[i];
		if (i > 0 && score[i] > max)max = score[i];
		if (i > 0 && score[i] < min)min = score[i];
	}
	printf("总分:%d\n最高分:%d\n最低分:%d\n平均分:%d\n",total,max,min,total/10);
	for (i = 0; i < 10; i++)
	{
		for (j= i+1; j < 10; j++)
		{
			if (score[i] < score[j])
			{
				int temp;
				temp = score[i];
				score[i] = score[j];
				score[j] = temp;
			}
		}
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", score[i]);
	}
	return 0;
}
#pragma endregion

//一个C程序有且只有一个主函数,即main函数.
//C程序就是执行主函数里的代码,也可以说这个主函数就是C语言中的唯一入口.
int main() //注:在最新的C标准中,main函数前的类型为int而不是void
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
	
	//NO.2
	Node p1[3],p2[3];
	int nums1[] = { 2,4,3 };
	int nums2[] = { 5,6,4 };
	PNode head_node1 = (PNode)malloc(sizeof(Node) / sizeof(char));
	head_node1->next = NULL;
	PNode head_node2 = (PNode)malloc(sizeof(Node) / sizeof(char));
	head_node2->next = NULL;
	for (int i = 0; i < Get_Length_Of_Array(nums1); i++)
	{
		if (Create_List_Head(head_node1, nums1[i]) != OK)
		{
			return ERROR;
		}
	}
	for (int j = 0; j < Get_Length_Of_Array(nums2); j++)
	{
		if (Create_List_Head(head_node2, nums2[j]) != OK)
		{
			return ERROR;
		}
	}
	PNode result = addTwoNumbers(head_node1, head_node2);

	system("pause");
	return 0;
}

#pragma region 练习函数
int is_leap_year(int year)
{
	if (year % 4 == 0 && year % 100 != 0)
		return 1;
	else if (year % 400 == 0)
		return 1;
	else
		return 0;
}
int shui_xian_hua()
{
	//定义三位数num,个位数sd,十位数td,百位数hd
	int num, sd, td, hd;
	//循环所有三位数
	for (num = 100; num<1000; num++)
	{
		//获取三位数字num百位上的数字
		hd = num / 100;
		//获取三位数字num十位上的数字
		td = (num / 10) % 10;
		//获取三位数字num个位上的数字
		sd = num % 10;
		//水仙花数的条件是什么？
		if (hd*hd*hd + td*td*td + sd*sd*sd == num)
		{
			printf("水仙花数字：%d\n", num);
		}
	}
	return 0;
}
int add1()
{
	int i = 1;
	int sum = 0;
	while (i <= 100)
	{
		sum += i % 2 == 0 ? -i : i;
		i++;
	}
	printf("sum=%d\n", sum);
	return 0;
}
int triangle_print(int num)
{
	int m, n;
	for (m = 0; m < num; m++)
	{
		for (n = 0;n < num - m - 1;n++)
		{
			printf(" ");
		}
		for (n = 0;n < 2*m - 1;n++) 
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
int triangle_print1(int num)
{
	int m, n;
	for (m = 0; m < num; m++)
	{
		for (n = 0;n < 2 * m - 1;n++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
int multi_9()
{	
	int i, j;	
	for (i = 9; i > 0; i--)
	{
		for (j = 1; j <=i; j++)
		{
			printf("%d*%d=%d ", i, j, i*j);
		}
		printf("\n");
	}
	return 0;
}
int su_shu(int max) 
{
	int i;
	int m, n;
	for (m = 2; m <= max; m++)
	{
		for (n = 2; n<m; n++)
		{
			if (m%n == 0)       
				break; 
		}
		if (m == n)
			printf("%d  ", m);
	}
	return 0;
}
int the_day_of_year(int year, int month, int day)
{
	int sum = 0;
	switch (month)
	{
	case 1:
		sum = 0;break;
	case 2:
		sum = 31;break;
	case 3:
		sum = 59;break;
	case 4:
		sum = 90;break;
	case 5:
		sum = 120;break;
	case 6:
		sum = 151;break;
	case 7:
		sum = 181;break;
	case 8:
		sum = 212;break;
	case 9:
		sum = 243;break;
	case 10:
		sum = 273;break;
	case 11:
		sum = 304;break;
	case 12:
		sum = 334;break;
	default:
		printf("一年只有十二个月哦亲~~");
		break;
	}
	//判断是否闰年
	int is_leap_year(year);
	if (is_leap_year && month > 2)sum++;
	if (day > 0)sum += day;
	printf("%d年%d月%d日是该年的第%d天\n", year, month, day, sum);
	return 0;
}
int factorial(int n) 
{
	int result;
	if (n < 0)printf("对不起,您的输入有误,请重新输入!\n");
	else if (n == 1 || n == 0)result = 1;
	else
		result = factorial(n - 1)*n;
	return result;
}
int monkey_eat_peach(int n)
{
	int num; //定义所剩桃子数
	if (n == 10)
	{
		num = 1;
		printf("第%d天所剩桃子%d个\n", n, num);		
	}
	else
	{
		num =( monkey_eat_peach(n+1)+1)*2;//这里是不应该用递归呢？
		printf("第%d天所剩桃子%d个\n",n , num); //天数，所剩桃子个数
	}
	return num;
}
int factorial_test(int n) 
{
	if (n == 1)
	{
		return 10;
	}
	else
	{
		return factorial_test(n - 1) + 2;
	}
}
int xiaoming_dache(int total_length, int time_go, int time_back)
{
	if (time_go < 0 || time_go>23 || time_back < 0 || time_back>23)
	{
		printf("回家的时间不对吧小明~~");
	}
	int result = 13 + 1;//起步价+燃油附加费
	double price = 2.3;
	if (time_go < 5 || time_go >= 23)
	{		
		price *= 1.2;		
	}
	result += (total_length - 3)*price;
	price = 2.3;
	if (time_go < 5 || time_go >= 23)
	{
		price *= 1.2;		
	}
	result += (total_length - 3)*price;
	printf("小明一天的打车费%d",result);
	return result;
}
#pragma endregion

#pragma region 基础知识学习

//函数就是实现代码逻辑的一个小的单元.

//注释是写给程序员看的,不是写给电脑看的.所以注释的内容,C语言编译器在编译时会被自动忽略.
//多行注释:  /* 注释内容 */ 
//单行注释:  //注释一行

//标识符:
//标识符可以是字母(A～Z，a～z)、数字(0～9)、下划线_组成的字符串，并且第一个字符必须是字母或下划线。
//1.标识符的长度最好不要超过8位~~~某些版本的C中规定标识符前8位有效，当两个标识符前8位相同时，则被认为是同一个标识符
//2.标识符是严格区分大小写的
//3.标识符最好选择有意义的英文单词组成做到"见名知意"，不要使用中文。
//4.标识符不能是C语言的关键字。

//变量及赋值:
//1.使用变量之前必须先定义变量.
//2.变量定义的一般形式为：数据类型 变量名;
//3.多个类型相同的变量：数据类型 变量名, 变量名, 变量名...;  //注意:在定义中不允许连续赋值，如int a=b=c=5;是不合法的。
//4.变量的赋值分为两种方式：1.先声明再赋值  2.声明的同时赋值.

//编码规范:
//1.一个说明或一个语句占一行,例如:包含头文件,一个可执行语句结束都需要换行;
//2.函数体内的语句要有明显缩进,通常以按一下Tab键为一个缩进;
//3.括号要成对写,如果需要删除的话也要成对删除;
//4.当一句可执行语句结束的时候末尾需要有分号;
//5.代码中所有符号均为英文半角符号.

//数据类型:
//1.C语言中，数据类型可分为：基本数据类型，构造数据类型，指针类型，空类型四大类。
//基本数据类型:整型2,字符型1,实型(浮点型)[单精度型4,双精度型8]
//构造数据类型:枚举类型,数组类型,结构体类型,共用体类型
//指针类型
//空类型
//注:在C语言标准(C89)没有定义布尔类型，所以C语言判断真假时以0为假，非0为真。所以我们通常使用逻辑变量的做法;或者使用头文件<stdbool.h>来实现.

//整型:
//整型 int 2
//短整型 short int 2
//长整型 long int 4
//无符号[unsigned]整型2,无符号短整型2,无符号长整型4

//注：int、short int、long int是根据编译环境的不同，所取范围不同。
//注：C语言中不存在字符串变量，字符串只能存在字符数组中.

//格式化输出语句~~其格式为：printf("输出格式符"，输出项);
//常用的格式化符:%d[带符十进制整数],%c[单个字符],%f[6位小数],%s[字符串]
//注:如果要输出多个变量的并指定变量的位置时候，格式符还可以连用，变量之间需要用逗号隔开
//注意：格式符的个数要与变量、常量或者表达式的个数一一对应.
//%.2f表示小数点后精确到两位

//常量:值不发生改变的量称为常量
//直接常量:直接常量也称为字面量，是可以直接拿来使用，无需说明的量
//符号常量:可以用一个标识符来表示一个常量，称之为符号常量。符号常量在使用之前必须先定义:	#define 标识符 常量值 
//注:符号常量的标示符一般习惯使用大写字母，变量的标示符一般习惯使用小写字母，加以区分。
//注：常量是不可改变的

//自动类型转换:发生在不同数据类型运算时，在编译的时候自动完成.
//基础规则:自动转换遵循的规则就好比小盒子可以放进大盒子里面一样.
//注：字节小的可以向字节大的自动转换，但字节大的不能向字节小的自动转换.
//举个栗子:一个char类型的变量'a',自动转换成int类型时输出的为ASCII的编码,即97.
//强制类型转换:通过定义类型转换运算来实现的。其一般形式为：(数据类型) (表达式)
//注:
//数据类型和表达式都必须加括号.
//转换后不会改变原数据的类型及变量值.
//强制转换后的运算结果不遵循四舍五入原则.

//运算符:
//算术运算符
//赋值运算符:赋值运算符分为简单赋值运算符和复合赋值运算符.复合赋值运算符就是在简单赋值符“=”之前加上其它运算符构成，例如+=、-=、*=、/=、%=。
		   //注意：复合运算符中运算符和等号之间是不存在空格的。
//关系运算符:关系表达式的值是“真”和“假”，在C程序用整数1和0表示.
		   //注意：>=，<=，==，!=这种符号之间不能存在空格。
//逻辑运算符:&& || ！
		   //逻辑运算的值也是有两种分别为“真”和“假”，C语言中用整型的1和0来表示。		   
//三目运算符： 表达式1 ? 表达式2 : 表达式3; 
		   //先判断表达式1的值是否为真，如果是真的话执行表达式2；如果是假的话执行表达式3。

//注:除法运算的坑
//如果相除的两个数都是整数的话，则结果也为整数，小数部分省略，如8 / 3 = 2；而两数中有一个为小数，结果则为小数，如：9.0 / 2 = 4.500000。
//注:取余运算的坑
//只适合用两个整数进行取余运算,运算后的符号取决于被模数的符号，如(-10)%3 = -1;而10%(-3) = 1。
//注:自增自减的坑
//++a --a[先运算再取值],a++ a--[先取值再运算].
//无论是a++还是++a都等同于a=a+1,在表达式执行完毕后a的值都自增了1,无论是a--还是--a都等同于a=a-1,在表达式执行完毕后a的值都自减少1。

//运算的优先级:
//int a = 3; b = 4;计算a+b%(a+b)/a+a*b-b该算式的运算结果

//分支结构之if-else语句:
//注意：当某一条件为真的时候，则不会向下执行该分支结构的其他语句。

//循环结构之while循环:反复不停的执行某个动作称之谓循环.
//一定要记着在循环体中改变循环变量的值，否则会出现死循环（无休止的执行）.
//循环体如果包括有一个以上的语句，则必须用{}括起来，组成复合语句.

//do-while循环语句的语义是：它先执行循环中的执行代码块，然后再判断while中表达式是否为真，如果为真则继续循环；如果为假，则终止循环。
//注:因此，do-while循环至少要执行一次循环语句。
//注:使用do-while结构语句时，while括号后必须有分号。

//for循环:最屌的最实用的循环语句

//在for循环中，
//表达式1是一个或多个赋值语句，它用来控制变量的初始值；
//表达式2是一个关系表达式，它决定什么时候退出循环；
//表达式3是循环变量的步进值，定义控制循环变量每循环一次后按什么方式变化。
//这三部分之间用分号(;)分开。
//注：for循环中的条件可以省略,但是所有的分号一定要写.
//表达式1和表达式3可以是一个简单表达式也可以是多个表达式以逗号分割.
//表达式2一般是关系表达式或逻辑表达式，但也可是数值表达式或字符表达式，只要其值非零，就执行循环体。
//各表达式中的变量一定要在for循环之前定义。   #这个就跟c#有区别了,知识点Get

//1、在知道循环次数的情况下更适合使用for循环；
//2、在不知道循环次数的情况下适合使用while或者do - while循环，如果有可能一次都不循环应考虑使用while循环，如果至少循环一次应考虑使用do - while循环。
//但是从本质上讲，while, do - while和for循环之间是可以相互转换的.

//多重循环:多重循环就是在循环结构的循环体中又出现循环结构。
//一般最多用到三层重循环.
//父循环一次，子循环需要全部执行完，直到跳出循环。父循环再进入下一次，子循环继续执行...
//循环总次数为各层循环次数的乘积.

//break:跳出循环.
//在没有循环结构的情况下，break不能用在单独的if-else语句中。
//在多层循环中，一个break语句只跳出当前循环。

//continue:continue语句的作用是结束本次循环开始执行下一次循环。
//break语句与continue语句的区别是：break是跳出当前整个循环，continue结束本次循环开始下一次循环。

//switch:
//在case后的各常量表达式的值不能相同，否则会出现错误.
//在case子句后如果没有break;会一直往后执行一直到遇到break;才会跳出switch语句.
//switch后面的表达式语句只能是整型或者字符类型.
//在case后，允许有多个语句，可以不用{}括起来.
//各case和default子句的先后顺序可以变动，而不会影响程序执行结果.
//default子句可以省略不用

//臭名远扬的goto语句
//goto语句是一种无条件分支语句，goto 语句的使用格式为：goto 语句标号;
//其中语句标号是一个标识符，该标识符一般用英文大写并遵守标识符命名规则，这个标识符加上一个“:”一起出现在函数内某处，执行goto语句后，
//程序将跳转到该标号处并执行其后的语句。
//注意:
//goto语句通常不用，主要因为它将使程序层次不清，且不易读，但在特定情况下，可以使用goto语句来提高程序的执行速度，所以还是少用为妙。

#pragma endregion

#pragma region 函数

/*
自定义函数的一般形式:
[数据类型说明] 函数名称([参数])
{
	执行代码块;
	return(表达式);
}

注意:
1.[]包含的内容可以省略，
数据类型说明省略，默认是int类型函数；
参数省略表示该函数是无参函数，
参数不省略表示该函数是有参函数；
2.函数名称遵循标识符命名规范；
3.自定义函数尽量放在main函数之前，如果要放在main函数后面的话，
需要在main函数之前先声明自定义函数，声明格式为：[数据类型说明] 函数名称（[参数]）;

*/

/*
函数调用:函数名（[参数]）;

1、对无参函数调用的时候可以将[]包含的省略。
2、[]中可以是常数，变量或其它构造类型数据及表达式，多个参数之间用逗号分隔。

有参函数和无参函数:
有参函数和无参函数的唯一区别在于：函数（）中多了一个参数列表。

特点:
有参函数更为灵活
无参函数中输出的相对就比较固定

*/

/*
形参和实参:
形参:形参是在定义函数名和函数体的时候使用的参数,目的是用来接收调用该函数时传入的参数.
实参:实参是在调用时传递该函数的参数.

形参和实参的区别:
1.形参只有在被调用时才分配内存单元，在调用结束时，即刻释放所分配的内存单元。
因此，形参只有在函数内部有效。函数调用结束返回主调函数后则不能再使用该形参变量。

2.实参可以是常量、变量、表达式、函数等，无论实参是何种类型的量，在进行函数调用时，
它们都必须具有确定的值，以便把这些值传送给形参。因此应预先用赋值等办法使实参获得确定值。

3.在参数传递时，实参和形参在数量上，类型上，顺序上应严格一致，否则会发生类型不匹配”的错误。

*/

/*
函数的返回值:
函数的返回值是指函数被调用之后，执行函数体中的程序段所取得的并返回给主调函数的值。

1. 函数的值只能通过return语句返回主调函数。return语句的一般形式为：
return 表达式   或者为：  return (表达式);

2.函数值的类型和函数定义中函数的类型应保持一致。如果两者不一致，则以函数返回类型为准，
自动进行类型转换。

3.无返回值的使用void.
注意：void函数中可以有执行代码块，但是不能有返回值，另void函数中如果有return语句，
该语句只能起到结束函数运行的功能。其格式为：return;

4.自定义的函数中可以有多个return语句，但是只能返回一个值
5.自定义的函数中可以没有return语句.

*/

/*
递归函数:递归就是一个函数在它的函数体内调用它自身。
执行递归函数将反复调用其自身，每调用一次就进入新的一层。
一句话总结递归：自我调用且有完成状态。

递归函数的特点:
1.每一级函数调用时都有自己的变量，但是函数代码并不会得到复制，
  如计算5的阶乘时每递推一次变量都不同；
2.每次调用都会有一次返回，如计算5的阶乘时每递推一次都返回进行下一次；
3.递归函数中，位于递归调用前的语句和各级被调用函数具有相同的执行顺序；
4.递归函数中，位于递归调用后的语句的执行顺序和各个被调用函数的顺序相反；
5.递归函数中必须有终止语句。

*/

/*
局部与全局:

局部变量:也称为内部变量。
局部变量是在函数内作定义说明的。其作用域仅限于函数内， 离开该函数后再使用这种变量是非法的。
在复合语句中也可定义变量，其作用域只在复合语句范围内。

全局变量:也称为外部变量，它是在函数外部定义的变量。它不属于哪一个函数，它属于一个源程序文件。
其作用域是整个源程序。

//下面的代码跟c#的区别在于:if块里面c#不能定义同名的x的变量.
#include <stdio.h>
int x = 77;
void fn1()
{
	printf("fn1(): x=%d\n", x);
}
int main()
{
	int x = 10;
	if(x>0)
	{
		int  x = 100;
		x /= 2;
		printf("if语句内, x=%d\n", x);
	}
	printf("main方法内, x=%d\n", x);
	fn1();
	return 0;
}

*/

/*
变量存储类别:

静态存储方式：是指在程序运行期间分配固定的存储空间的方式。静态存储区中存放了在整个程序
执行过程中都存在的变量，如全局变量。

动态存储方式：是指在程序运行期间根据需要进行动态的分配存储空间的方式。
动态存储区中存放的变量是根据程序运行的需要而建立和释放的，通常包括：函数形式参数；
自动变量；函数调用时的现场保护和返回地址等.

C语言中存储类别又分为四类：自动（auto）、静态（static）、
寄存器的（register）和外部的（extern）。

1、用关键字auto定义的变量为自动变量，auto可以省略，auto不写则隐含定为“自动存储类别”，属于动态存储方式。
2、用关键字static修饰的为静态变量，如果定义在函数内部的，称之为静态局部变量；如果定义在函数外部，称之为静态外部变量。
注:静态局部变量属于静态存储类别，在静态存储区内分配存储单元，在程序整个运行期间都不释放；静态局部变量在编译时赋初值，即只赋初值一次；如果在定义局部变量时不赋初值的话，则对静态局部变量来说，编译时自动赋初值0（对数值型变量）或空字符（对字符变量）。
3.为了提高效率，C语言允许将局部变量得值放在CPU中的寄存器中，这种变量叫“寄存器变量”，用关键字register作声明。
register int i;  //定义i为寄存器类型变量
>只有局部自动变量和形式参数可以作为寄存器变量.
>一个计算机系统中的寄存器数目有限，不能定义任意多个寄存器变量.
>局部静态变量不能定义为寄存器变量
4.用extern声明的的变量是外部变量，外部变量的意义是某函数可以调用在该函数之后定义的变量。

注:C程序函数定义的自动变量,系统不自动的赋确定的初值.

*/

/*
内部函数与外部函数:

内部函数:(static)
在C语言中不能被其他源文件调用的函数称谓内部函数 ，内部函数由static关键字来定义，
因此又被称谓静态函数，形式为：static [数据类型] 函数名（[参数]）

注:这里的static是对函数的作用范围的一个限定，限定该函数只能在其所处的源文件中使用，因此在不同文件中出现相同的函数名称的内部函数是没有问题的。


外部函数:(extern 默认)
在C语言中能被其他源文件调用的函数称谓外部函数 ，外部函数由extern关键字来定义，
形式为：extern [数据类型] 函数名([参数])

注:C语言规定，在没有指定函数的作用范围时，系统会默认认为是外部函数，因此当需要定义外部函数时extern也可以省略。


*/

#pragma endregion

#pragma region 数组

/*
数组:
是一块连续的，大小固定并且里面的数据类型一致的内存空间.
声明: 数据类型 数组名称[长度]; 

以下是三种初始化的方式:
1.数据类型 数组名称[长度n] = {元素1,元素2…元素n};
2.数据类型 数组名称[] = {元素1,元素2…元素n};
3.数据类型 数组名称[长度n]; 
数组名称[0] = 元素1; 
数组名称[1] = 元素2; 
数组名称[n] = 元素n+1;

获取数组元素时： 数组名称[元素所对应下标];

以下为注意事项:
1、数组的下标均以0开始；
2、数组在初始化的时候，数组内元素的个数不能大于声明的数组长度；
3、如果采用第一种初始化方式，元素个数小于数组的长度时，多余的数组元素初始化为0；
4、在声明数组后没有进行初始化的时候，静态（static）和外部（extern）类型的数组
元素初始化元素为0，自动（auto）类型的数组的元素初始化值不确定。


数组的遍历:
1.最好避免出现数组越界访问，循环变量最好不要超出数组的长度.
2.C语言的数组长度一经声明，长度就是固定，无法改变，并且C语言并不提供计算数组长度的方法。
注:sizeof(my_array)  可以使用下面的方式来判断数组的长度.

由于C语言是没有检查数组长度改变或者数组越界的这个机制，可能会在编辑器中编译并通过，但是结果就不能肯定了，因此还是不要越界或者改变数组的长度
上面的意思是:即使越界了,最多结果错误,但是编译不会报错.


数组作为函数的参数:
1.整个数组当作函数参数，即把数组名称传入函数中.
2.数组中的元素当作函数参数，即把数组中的参数传入函数中.

注意:
1、数组名作为函数实参传递时，函数定义处作为接收参数的数组类型形参既可以指定长度也可
以不指定长度。
2、数组元素作为函数实参传递时，数组元素类型必须与形参数据类型一致。

数组作为形参的写法如下
int test(int arr[]){}
而不是:
int test(int[] arr){}
注意与C#的异同点.

字符串与数组:
C语言中无字符串数据类型.

可以有以下两种替代方法:即字符串数组
1、char 字符串名称[长度] = "字符串值";
2、char 字符串名称[长度] = {'字符1','字符2',...,'字符n','\0'};

注意:
[]中的长度是可以省略不写的；
采用第2种方式的时候最后一个元素必须是'\0'，'\0'表示字符串的结束标志；
采用第2种方式的时候在数组中不能写中文.

输出字符串的时候:
printf("%s",字符数组名字);
或者
puts(字符数组名字);

字符串的函数:
strlen():获得字符串的长度(单位字节)
获取字符串的长度，在字符串长度中是不包括‘\0’而且汉字和字母的长度是不一样的。
strcmp():比较字符串
在比较的时候会把字符串先转换成ASCII码再进行比较,
返回的结果为0表示s1和s2的ASCII码相等,
返回结果为1表示s1比s2的ASCII码大,
返回结果为-1表示s1比s2的ASCII码小.
strcpy():字符串拷贝
拷贝之后会覆盖原来字符串且不能对字符串常量进行拷贝.
strcat():字符串拼接
在使用时s1与s2指的内存空间不能重叠，且s1要有足够的空间来容纳要复制的字符串.


多维数组:
数据类型 数组名称[常量表达式1][常量表达式2]...[常量表达式n];

注:二维数组定义的时候，可以不指定行的数量，但是必须指定列的数量。

初始化:直接初始化 和 先声明再赋值.
第一种始化时数组声明必须指定列的维数。因为系统会根据数组中元素的总个数来分配空间，当知道元素总个数以及列的维数后，会直接计算出行的维数；
第二种方式必须同时指定行和列的维数.

多维数组的遍历:
多维数组的每一维下标均不能越界
*/


#pragma endregion




