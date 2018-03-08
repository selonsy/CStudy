// CPlusPlusStudy.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include<map>
using namespace std;

/*
给定输入文件与输出文件，读取输入文件中每行的有限个整数，输出该行最大最小值到输出文件
文件内容举例:
1 2 3 4 5 6 7
2 3 4 5
6 7 8 9
输出内容为:
<1>Max:7,Min:1
*/
struct max_min
{
	int max;
	int min;
};
void file_read_write1()
{
	FILE* file_r, *file_d;
	file_r = fopen("D:\\99Workspace\\90Test\\数字.txt", "r");//以只读模式打开文件
	file_d = fopen("D:\\99Workspace\\90Test\\数字大小.txt", "w+");//以读写模式,不存在则新建
	if (file_r == NULL) //如果文件打开失败
	{
		printf("cannot open file!\n");
		return;
	}
	char row[100];
	//char* res;
	int max = -100, min = 100;
	int i = 0, j;
	struct max_min res[10];
	while (!feof(file_r))
	{
		fgets(row, 100, file_r);
		char* temp = strtok(row, " ");
		int t_int = atoi(temp);
		if (t_int > max)max = t_int;
		if (t_int < min)min = t_int;
		while (temp)
		{
			temp = strtok(NULL, " ");
			if (temp)
			{
				t_int = atoi(temp);
				if (t_int > max)max = t_int;
				if (t_int < min)min = t_int;
			}
		}
		res[i].max = max;
		res[i].min = min;
		max = -100; min = 100;
		i++;
	}
	for (j = 0; j < i; j++)
	{
		fprintf(file_d, "<%d>Max:%d,Min:%d\n", j, res[j].max, res[j].min);
	}
	fclose(file_r);
	fclose(file_d);
	cout << "you fuck" << endl;
}

//求共同好友数量
/*
描述
Alice有N个朋友，Bob有M个朋友。 他们想知道有多少人是他们的共同朋友。 你能帮助他们吗？
输入:
输入以整数T（T <= 20）开始，表示测试样例的数量。 每个测试样例包含三行。 第一行包含两个整数N和M（1 <= N，M <= 50）。 第二行包含N个名字，代表Alice的朋友。 第三行包含M个名字，代表Bob的朋友。 每个名字的长度在3到10之间。 每个名称只包含小写英文字母（'a' - 'z'）。 保证两个不同的人不会共享相同的名称。
输出:
对于每个样例，用一行输出Alice和Bob的共同朋友的数目。
输入样例:
2
4 5
tom lucy kate eva
eva rose joe carl tom
3 3
jimmy jeff emily
zhanglan xiemin xiaran
输出样例
2
0
*/
void findCommonFriendsOfAlice()
{
	map<string, int> friends;
	string str;
	int n, a, b, i, count;
	scanf("%d", &n);

	while (n--)
	{
		count = 0;
		scanf("%d %d", &a, &b);
		for (i = 0; i < a; i++)
		{
			cin >> str;
			friends[str] += 1;
		}

		for (i = 0; i < b; i++)
		{
			cin >> str;
			if (friends[str] > 0)
			{
				count++;
			}
		}
		printf("%d\n", count);
	}
}

int main()
{
	file_read_write1();
    return 0;
}

