#include "head.h"

int main()
{

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

	//NO.3
	//char* s = "shenjinlong";
	//int max = lengthOfLongestSubstring(s);
	//printf("the length of max_substring is %d", max);

	//spiralArray(3);
	//personalRate();
	horseChess();

	system("pause");
	return 0;

	return 0;
}

#pragma region Leetcode

/*
NO 1. Accepted Runtime: 93 ms
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/
/**
* Note: The returned array must be malloced, assume caller calls free().
返回的数组必须被分配，假设调用者负责释放

调用示例:
int nums[] = {2,7,11,15};
int *p  = twoSum(nums, 4, 9);
free(p);
*/
int * twoSum(int * nums, int numsSize, int target)
{
	int i, j;
	int* arr = (int*)malloc(2 * sizeof(int));;
	int index1, index2;
	int flag = 0;
	for (i = 0; i < numsSize; i++)
	{
		for (j = i + 1; j < numsSize; j++)
		{
			if (nums[i] + nums[j] == target)
			{
				arr[0] = i;
				arr[1] = j;
				return arr;
			}
		}
	}
	return NULL;
}

/*
NO 2. Accepted Runtime:37ms
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* q = p;
	p->next = NULL;
	int flag = 0, first = 0;;
	while (l1 != NULL || l2 != NULL)
	{
		int _val = (l1 != NULL ? l1->data : 0) + (l2 != NULL ? l2->data : 0) + flag;
		int val = _val % 10;
		if (_val >= 10)flag = 1;
		else flag = 0;
		struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));

		if (p->next == NULL&&first == 0) {
			p->data = val; first = 1;
		}
		else {
			node->data = val;
			q->next = node;
			q = node;
		}
		if (l1 != NULL)l1 = l1->next;
		if (l2 != NULL)l2 = l2->next;
	}
	if (flag == 0)q->next = NULL;
	else {
		struct ListNode* end = (struct ListNode*)malloc(sizeof(struct ListNode));
		end->data = 1;
		end->next = NULL;
		q->next = end;
	}
	return p;
}

/*
NO 3. Accepted Runtime:36 ms
Given a string, find the length of the longest substring without repeating characters.
Examples:
Given "abcabcbb", the answer is "abc", which the length is 3.
Given "bbbbb", the answer is "b", with the length of 1.
Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
int lengthOfLongestSubstring(char* s) {
	int exist[256];
	int i, j,k;
	for (k = 0; k < 256; k++)
	{
		exist[k] = 0;
	}
	int max = 0;
	
	for (i = 0; s[i] != NULL; i++)
	{		
		exist[s[i]] = 1;
		int count = 1;
		for (j = i + 1; s[j] != NULL; j++)
		{
			if (exist[s[j]] != 1)
			{
				exist[s[j]] = 1;
				count++;
			}
			else
			{
				for (k = 0; k < 256; k++)
				{
					exist[k] = 0;
				}
				break;
			}
		}
		max = count > max ? count : max;
	}
	return max;
}

/*
NO.4 Accepted Runtime:36 ms
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0


Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {

}

#pragma endregion

#pragma region 考研复试上机

/*
1.计算税率，题目给出了工资salary和保险insurance，根据工资加保险的大小范围不同，所缴纳的税率不同，根据题目要求输出需要交纳的税率.

具体题目不清晰,我将其理解为以下内容:
给定一个人的当月工资,求出他当月需要缴纳的个人所得税,并计算其税率.
//应缴个人所得税的计算公式为=（月应税收入-3500）*税率-速算扣除数
含税级距						税率(%)				速算扣除数
不超过1,500元的               3					0
超过1,500元至4,500元的部分		10					105
超过4,500元至9,000元的部分		20					555
超过9,000元至35,000元的部分	25					1,005
超过35,000元至55,000元的部分	30					2,755
超过55,000元至80,000元的部分	35					5,505
超过80,000元的部分				45					13,505
*/
void personalRate()
{
	float money, insurance;
	printf("Please input your income(monthly):");
	scanf_s("%f", &money);
	printf("Please input your insurance cost(monthly):");
	scanf_s("%f", &insurance);

	if (money < 0 || insurance < 0)printf("your input is error!\n");

	float money_rate = money - insurance - 3500; //保险不交税,3500是免征额
	float money_pay;

	if (money_rate <= 0)printf("your income is too low,you don't need to pay!\n");

	if (money_rate <= 1500)money_pay = money_rate*0.03;
	else if (money_rate > 1500 && money_rate <= 4500)money_pay = money_rate*0.1 - 105;
	else if (money_rate > 4500 && money_rate <= 9000)money_pay = money_rate*0.2 - 555;
	else if (money_rate > 9000 && money_rate <= 35000)money_pay = money_rate*0.25 - 1005;
	else if (money_rate > 35000 && money_rate <= 55000)money_pay = money_rate*0.3 - 2755;
	else if (money_rate > 55000 && money_rate <= 80000)money_pay = money_rate*0.35 - 5505;
	else money_pay = money_rate*0.45 - 13505;

	printf("you need to pay %.2f,the rate is %.2f\%", money_pay, (money_pay / money) * 100);
}


/*
2.中国象棋之马：这个题坑了我一个小时，大致说的是一个8*8的方阵里面，用户随意输入1到64中的一个数字，这个数字就是中国象棋中马的初始位置，大家都知道马只能走日字，请设计一个算法，给出一个路径，这个路径描述出马走遍棋盘上所有点所经过的路径，而且并不重复。总之这个题我最后没做出来。

分析如下:
>给定一个数字,可能有几种位置,比如48,那么有可能是横六竖八,也可能是横八竖六.
>给定一个居中的点,如横四竖四,那么他可能有八个位置可以走,一方两个.
>采用二维数组,循环操作,走过的路不再走.
>停止条件采用走过的点累积六十四个.
>二维数组的值可以采用先初始化为0,后面走一个加一的方式,比如第一步a[i][j]=1,第二步a[i][j]=2
>输出结果可以采用链表的方式

进一步分析:广度优先遍历
首先知道马在棋盘是怎么走的，根据国际象棋规则，马在一个起始位置共有8个可用的行动位置，当然边界方面需要另外考虑，我们的马的行走必须考虑这8种类可能性，排除不能使用的位置，走可用的位置，当8个位置不可以使用的时，需要考虑返回上一步，这点有点像图的广度优先遍历相同，当马走完所有位置，同时没有可用的位置用于行走的时候遍历结束。

进进一步分析:贪心算法/局部最优调整
其实马踏棋盘的问题很早就有人提出，且早在1823年，J.C.Warnsdorff就提出了一个有名的算法。在每个结点对其子结点进行选取时，优先选择‘出口’最小的进行搜索，‘出口’的意思是在这些子结点中它们的可行子结点的个数，也就是‘孙子’结点越少的越优先跳，为什么要这样选取，这是一种局部调整最优的做法，如果优先选择出口多的子结点，那出口少的子结点就会越来越多，很可能出现‘死’结点（顾名思义就是没有出口又没有跳过的结点），这样对下面的搜索纯粹是徒劳，这样会浪费很多无用的时间，反过来如果每次都优先选择出口少的结点跳，那出口少的结点就会越来越少，这样跳成功的机会就更大一些。这种算法称为为贪心算法，也叫贪婪算法或启发式算法，它对整个求解过程的局部做最优调整，它只适用于求较优解或者部分解，而不能求最优解。这样的调整方法叫贪心策略，至于什么问题需要什么样的贪心策略是不确定的，具体问题具体分析。实验可以证明马遍历问题在运用到了上面的贪心策略之后求解速率有非常明显的提高，如果只要求出一个解甚至不用回溯就可以完成，因为在这个算法提出的时候世界上还没有计算机，这种方法完全可以用手工求出解来，其效率可想而知。

算法思想步骤概括为下面的几点：
①找到一个位置的各个方向的出口（OUT1）。
②对各个方向的出口进行二次出口（OUT2）的搜索。
③记录每个方向上出口（OUT1）的二次出口（OUT2），（OUT2）最小的的那个（OUT1）即为接下来要访问的位置。
④将每次访问过的位置放入容器。


可能的变种题:
设有下图所示的一个棋盘，在棋盘上的A点，有一个中国象棋的马，并约定马走的规则,从A点跳至B点。
规则：1. 马走日字 2. 马只能向右走。找出从A跳到B的某一途径。
1）编写一个函数，输入A点的x和 y值，按规则跳马至B点。
2）在main函数中通过键盘输入x,y的初值，打印马跳过的轨迹和步数。
3）采用递归的思路设计该函数。
*/

typedef struct
{
	int x, y;
}item;
item move[4] = { { -2,1 },{ -1,2 },{ 1,2 },{ 2,1 } };
int map[5][9], sx, sy;
//判断是否在地图中，防止越界
int checkIn(int x, int y)
{
	if (x >= 0 && x <= 4 && y >= 0 && y <= 8)
		return 1;
	return 0;
}
//输出最终结果
void output()
{
	int i, j;
	for (i = 0; i <= 4; i++)
	{
		for (j = 0; j <= 8; j++)
			printf("%d ", map[i][j]);
		putchar('\n');
	}
	printf("共计%d步。", map[0][8]);
}
//从x y开始寻找能否到达终点，能返回1，不能返回0，step表示当前的步数。
int findPath(int x, int y, int step)
{
	int i;
	map[x][y] = step;
	//终点
	if (x == 0 && y == 8)
	{
		output();
		return 1;
	}
	//向右边4个方向前进
	for (i = 0; i < 4; i++)
		if (checkIn(x + move[i].x, y + move[i].y))
			if (findPath(x + move[i].x, y + move[i].y, step + 1) == 1)
				return 1;
	//四个方向均无法到达终点，回溯并返回0
	map[x][y] = 0;
	return 0;
}

//棋盘尺寸
#define X 8
#define Y 8
//B点坐标
#define BX 1
#define BY 8
int pos[100];
int idx = 0;
int drt[4][2] = { { 2,1 },{ 1,2 },{ -1,2 },{ -2,1 } };
int expand(int x, int y)
{
	int i, xn, yn;

	if (x == BX && y == BY)
		return 1;
	if (x<0 || y<0 || x>X || y>Y)
		return 0;

	for (i = 0; i<4; i++)
	{
		xn = x + drt[i][0];
		yn = y + drt[i][1];
		pos[2 * idx] = xn;
		pos[2 * idx + 1] = yn;
		idx++;
		if (expand(xn, yn))
			return 1;
		else
			idx--;
	}
	return 0;
}

//棋盘数据：  
const int WIDTH = 8;       //棋盘宽和高  （国际象棋）
const int HEIGHT = 8;
int board[8][8];  //棋盘数组保存数据为每个位置对应马的路线的第几步  
//dir为马的八个方向  
const int dir[8][2] = { { -2,-1 },{ -2,1 },{ -1,2 },{ 1,2 },{ 2,1 },{ 2,-1 },{ 1,-2 },{ -1,-2 } };
//求(i,j)位置的出口,并返回所有出口和对应的出口个数  
int exitn(int i, int j, int s, int a[])
{
	int k, i1, j1;
	int count;  //计数出口的个数  
	for (count = k = 0; k<8; k++)
	{
		i1 = i + dir[(s + k) % 8][0];  //八方向横坐标和纵坐标，(s+k)%8让索引保持在八方向上  
		j1 = j + dir[(s + k) % 8][1];
		if (i1 >= 0 && i1<HEIGHT && j1 >= 0 && j1<WIDTH && board[i1][j1] == 0) //在棋盘的范围内并且没有走过  
			a[count++] = (s + k) % 8;
	}
	return count;
}
//将(i,j)节点以s开始的下一个节点序列中，节点数最小的一个返回  //next(istartX, istartY, start)
int next(int i, int j, int s)
{
	int m, k, go, min, a[8], b[8], temp;
	m = exitn(i, j, s, a);  //当前位置有出口数  
	if (m == 0)                //没有  
		return -1;
	for (min = 8, k = 0; k<m; k++)       //搜寻出口最少的位置  
	{
		temp = exitn(i + dir[a[k]][0], j + dir[a[k]][1], s, b);
		if (temp < min)             //保存最小出口  
		{
			min = temp;
			go = a[k];             //保存方向索引  
		}
	}
	return go;             //返回最少出口位置的方向索引  
}


typedef struct chess {
	int heng;
	int shu;
	struct chess* next;
}Chess,*PChess;
PChess reverse(PChess head) {
	PChess p, q, pr;
	p = head->next;
	q = NULL;
	head->next = NULL;
	while (p) {
		pr = p->next;
		p->next = q;
		q = p;
		p = pr;
	}
	head->next = q;
	return head;
}
void horseChess()
{
	int num;
	int istartX, istartY;
	printf("Please input your number:");
	scanf_s("%d", &num);
	
	istartX = num % 8 == 0 ? num / 8 - 1 : num / 8;		//起始横坐标
	istartY = num % 8 == 0 ? 7 : (num % 8) - 1;			//起始纵坐标

	
	int step, flag, start = 1;    //step表示第几步,flag标记下一步的方向，start表示方向索引的初始值  
	memset(board, 0, sizeof(int)*WIDTH*HEIGHT);  //初始化棋盘，0表示没有走过//
	board[istartX][istartY] = 1;                 //起始位置的第一步，1表示第一步，N表示第N步  
	
	printf("\n棋盘中的轨迹：（数字表示第几步，所在位置为棋盘位置）\n");	
	for (step = 2; step <= WIDTH*HEIGHT; step++)  //从第二步开始，直到走满整个棋盘  
	{
		if ((flag = next(istartX, istartY, start)) == -1)      //返回-1，没有找到出口  
			break;
		istartX += dir[flag][0];                 //下一步的起始坐标  
		istartY += dir[flag][1];
		board[istartX][istartY] = step;                    //保存当前步到棋盘作为标记  
	}
	int i, j;
	for (i = 0; i<HEIGHT; i++)                    //输出棋盘保存的路径  
	{
		for (j = 0; j<WIDTH; j++)
			printf("%5d", board[i][j]);        //5格对齐  
		printf("\n");
	}

	/*int x, y, i, j;
	int ary[X + 1][Y + 1];

	printf("请输入起始点(x,y)\n");
	scanf_s("%d,%d", &x, &y);
	pos[0] = x;
	pos[1] = y;
	idx = 1;

	if (expand(x, y))
	{
		for (i = 0; i <= X; i++)
			for (j = 0; j <= Y; j++)
				ary[i][j] = 0;
		for (i = 0; i<idx; i++)
			ary[pos[2 * i]][pos[2 * i + 1]] = i + 1;
		for (i = 0; i <= X; i++)
		{
			for (j = 0; j <= Y; j++)
				printf("%d ", ary[i][j]);
			printf("\n");
		}
		printf("共计%d步\n", idx);
	}
	else
	{
		printf("不能从A到达B\n");
	}
	return;*/

	/*memset(map, 0, sizeof(map));
	printf("请输入起点<x,y>\n");
	scanf_s("%d,%d", &sx, &sy);
	findPath(sx, sy, 1);
	return;*/

	//int num, a[8][8], i, j, m, n, k = 0;
	//printf("Please input your number:");
	//scanf_s("%d", &num);

	////初始化二维数组
	//for (m = 0; m < 8; m++)
	//{
	//	for (n = 0; n < 8; n++)
	//	{
	//		a[m][n] = 0;
	//	}
	//}

	//i = num % 8 == 0 ? num / 8 - 1 : num / 8;		//起始横坐标
	//j = num % 8 == 0 ? 7 : (num % 8) - 1;	//起始纵坐标

	//a[i][j] = 1;		//第一步
	//k++;
	//PChess head = (PChess)malloc(sizeof(Chess));  //初始化头结点
	//head->heng = i;
	//head->shu = j;
	//head->next = NULL;

	//int count = 0;
	//for (m = 0; m < 64; m++)
	//{
	//	int flag = 0;
	//	count++;
	//	if ((i - 2) >= 0 && (j - 1) >= 0 && a[i - 2][j - 1] == 0)
	//	{
	//		i = i - 2; j = j - 1;
	//	}
	//	else if ((i - 2) >= 0 && (j + 1) >= 0 && a[i - 2][j + 1] == 0)
	//	{
	//		i = i - 2; j = j + 1;
	//	}
	//	else if ((i - 1) >= 0 && (j - 2) >= 0 && a[i - 1][j - 2] == 0)
	//	{
	//		i = i - 1; j = j - 2;
	//	}
	//	else if ((i + 1) >= 0 && (j - 2) >= 0 && a[i + 1][j - 2] == 0)
	//	{
	//		i = i + 1; j = j - 2;
	//	}
	//	else if ((i + 2) >= 0 && (j - 1) >= 0 && a[i + 2][j - 1] == 0)
	//	{
	//		i = i + 2; j = j - 1;
	//	}
	//	else if ((i + 2) >= 0 && (j + 1) >= 0 && a[i + 2][j + 1] == 0)
	//	{
	//		i = i + 2; j = j + 1;
	//	}
	//	else if ((i - 1) >= 0 && (j + 2) >= 0 && a[i - 1][j + 2] == 0)
	//	{
	//		i = i - 1; j = j + 2;
	//	}
	//	else if ((i + 1) >= 0 && (j + 2) >= 0 && a[i + 1][j + 2] == 0)
	//	{
	//		i = i + 1; j = j + 2;
	//	}
	//	else { flag = 1; }

	//	if (flag == 0)
	//	{
	//		//可以跳
	//		a[i][j] = ++k;
	//		PChess node = (PChess)malloc(sizeof(Chess));
	//		node->heng = i;
	//		node->shu = j;
	//		node->next = head;
	//		head = node;
	//	}
	//	/*else
	//	{
	//		if (k == 64)break;
	//		else m = 0;

	//		if (count == 100000) { printf("over time 10000!\n"); break; }
	//	}*/
	//}

	////打印出马跳动的轨迹
	//for ( i = 0; i < 8; i++)
	//{
	//	for (j = 0; j < 8; j++)
	//	{
	//		printf("%4d ",a[i][j]);
	//	}
	//	printf("\n");
	//}

	////按先后顺序输出
	//head = reverse(head);
	//PChess p = head;
	//k = 0;
	//while (p)
	//{
	//	printf("横 %d,竖 %d\n", p->heng, p->shu);
	//	p = p->next;
	//	k++;
	//}
	//printf("total is %d",k);
}


/*
3.输出螺旋数组:
Input array size N (1~20)
Using Two-Dimensional array
输出一个数字n，输出n阶螺旋数组。
所谓螺旋就是指下面举得这个例子,此时n为4
1   2  3  4
12  13 14 5
11  16 15 6
10  9  8  7
*/
void spiralArray(int num)
{
	int a[20][20], count, i, j, k, kend, lend;
	
	kend = num / 2;//轮数,也即圈数
	lend = num;
	count = 1;
	for (i = 0, j = 0, k = 0; k<kend; k++)
	{
		//一轮即一个外环圈
		a[i][j] = count++;
		//输出顶行
		for (j++; j<lend; j++)
			a[i][j] = count++;
		//输出最右一列(除顶行的末元素)
		for (i++, j--; i<lend; i++)
			a[i][j] = count++;
		//输出最底一行(除最右行的末元素)
		for (i--, j--; j >= k; j--)
			a[i][j] = count++;
		//输出第一列(除顶行和底行的头元素)
		for (i--, j++; i>k; i--)
			a[i][j] = count++;

		i++; j++; lend--;
	}
	//奇数螺旋组的中心元素
	if (num % 2 != 0) a[i][j] = count;
	for (i = 0; i<num; i++)
	{
		for (j = 0; j<num; j++)
			printf("%4d ", a[i][j]);
		printf("\n");
	}
}
void spiralArray1(int num)
{
	//c++版本
	/*int num, count, i, j, k, kend, lend;
	printf("Input a number[1-20]: ");
	scanf("%d", &num);

	int *a = new int[num*num];
	kend = num / 2;
	lend = num;
	count = 1;
	for (i = 0, j = 0, k = 0; k<kend; k++)
	{
		a[i*num + j] = count++;

		for (j++; j<lend; j++)
			a[i*num + j] = count++;

		for (i++, j--; i<lend; i++)
			a[i*num + j] = count++;

		for (i--, j--; j >= k; j--)
			a[i*num + j] = count++;

		for (i--, j++; i>k; i--)
			a[i*num + j] = count++;

		i++; j++; lend--;
	}
	if (num % 2 != 0) a[i*num + j] = count;
	for (i = 0; i<num; i++)
	{
		for (j = 0; j<num; j++)
			printf("%4d ", a[i*num + j]);
		printf("\n");
	}
	delete[]a;*/
}
void spiralArray2(int num)
{
	//C++版本
	//int **a;
	//int num, count, i, j, k, kend, lend;
	//printf("Input a number[1-20]: ");
	//scanf("%d", &num);

	//a = new int *[num]; //动态申请指针数组  
	//for (i = 0; i<num; i++)
	//{
	//	a[i] = new int[num];    //动态申请数组  
	//}

	//kend = num / 2;
	//lend = num;
	//count = 1;
	//for (i = 0, j = 0, k = 0; k<kend; k++)
	//{
	//	a[i][j] = count++;

	//	for (j++; j<lend; j++)
	//		a[i][j] = count++;

	//	for (i++, j--; i<lend; i++)
	//		a[i][j] = count++;

	//	for (i--, j--; j >= k; j--)
	//		a[i][j] = count++;

	//	for (i--, j++; i>k; i--)
	//		a[i][j] = count++;

	//	i++; j++; lend--;
	//}
	//if (num % 2 != 0) a[i][j] = count;
	//for (i = 0; i<num; i++)
	//{
	//	for (j = 0; j<num; j++)
	//		printf("%4d ", a[i][j]);
	//	printf("\n");
	//}

	//for (i = 0; i<num; i++)
	//{
	//	delete[]a[i];
	//}
	//delete[]a;
}
#pragma endregion


#pragma region Lib

//创建链表(坏的)
int Create_List_Head(PNode h, ElementType data)
{
	if (h == NULL)
	{
		return ERROR;
	}

	PNode node = (PNode)malloc(sizeof(Node) / sizeof(char));
	if (node == NULL)
	{
		return MALLOC_ERROR;
	}
	node->data = data;
	node->next = h->next;
	h->next = node;

	return OK;
}

//展示链表
void DisPlay(PNode h)
{
	if (h == NULL)
	{
		return;
	}
	PNode temp = h->next;  // 链表第一个结点指针  
	while (temp)
	{
		printf("%4d", temp->data);
		temp = temp->next;
	}

	printf("\n");
}

//获取数组长度
int Get_Length_Of_Array(int array[])
{
	int count = 0;
	for (int i = 0; array[i] != NULL; i++)
	{
		count++;
	}
	return count;
	//return (sizeof(array) / sizeof(array[0]));
}

#pragma endregion

